
#include "ICompraController.h"

ICompraController::ICompraController() {
  this->sistema = Sistema::getInstance();
}

ICompraController::ICompraController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}
ICompraController::~ICompraController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}

void ICompraController::altaCompra(set<DTOProdCantidad*> prodsCantidad) {
  DTFecha* fecha = DTFecha::obtenerFechaActual();

  Cliente* clienteEnMemoria = this->memoria->getCliente();
  if (clienteEnMemoria == nullptr)
    return;

  Compra* compra = new Compra(clienteEnMemoria, to_string(Compra::getContadorCompras()), fecha);

  for (auto& prodCant : prodsCantidad) {
    Producto* prod = this->sistema->productos.find(prodCant->getProducto()->getCodigo())->second;
    compra->agregarLineaProducto(prod, prodCant->getCantidad());
  }

  this->sistema->compras.insert(pair(compra->getCodigo(), compra));
}

map<string, DTOProducto*> ICompraController::productosConEnvioPendiente(string nickVend) {
  map<string, DTOProducto*> productosConEnvioPendiente;

  for (auto& compra : this->sistema->compras) {
    set<Producto*> productos;
    productos = compra.second->productosConEnvioPendiente(nickVend);

    for (auto& producto : productos) {
      if (!productosConEnvioPendiente.contains(producto->getCodigo())) {
        productosConEnvioPendiente.insert(pair(producto->getCodigo(), new DTOProducto(
          producto->getCodigo(), producto->getStock(), producto->getPrecio(), producto->getNombre(),
          producto->getDescripcion(), producto->getCategoria()
        )));
      }
    }
  }

  return productosConEnvioPendiente;
}

set<DTOCompraCliente*> ICompraController::comprasPendientesProducto(string codProd) {
  set<DTOCompraCliente*> comprasPendientes;
  for (auto& compra : this->sistema->compras) {
    DTOCompraCliente* compraCliente = compra.second->tienePendienteDeEnviar(codProd);
    if (compraCliente != nullptr) {
      comprasPendientes.insert(compraCliente);
    }
  }
  this->memoria->setProducto(this->sistema->productos.find(codProd)->second);
  return comprasPendientes;
}

void ICompraController::enviarProductoCompra(DTOCompraCliente* compraCliente) {
  if (compraCliente == nullptr) {
    return;
  }

  for (auto& compra :this->sistema->compras) {
    if (compra.second->getCodigo() == compraCliente->getCodigoCompra()) {
      compra.second->enviarProducto(this->memoria->getProducto()->getCodigo());
      break;
    }
  }
}
