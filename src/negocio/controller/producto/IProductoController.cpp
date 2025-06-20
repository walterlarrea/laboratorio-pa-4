#include "IProductoController.h"
#include "../../dto/DTOProducto.h"
#include "../../dominio/Producto.h"

IProductoController::IProductoController() {
  this->sistema = Sistema::getInstance();
}
IProductoController::IProductoController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}
IProductoController::~IProductoController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}


bool IProductoController::verificarCodigo(string codigo) {
  bool result = false;

  map<string, Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    if (codigo == it->second->getCodigo()) {
      result = true;
      break;
    }
  }

  return result;
}

void IProductoController::agregarProducto(DTOProducto* producto) {

  if (producto != nullptr) {
    Producto* nuevoProducto = new Producto(
      producto->getCodigo(), producto->getStock(), producto->getPrecio(),
      producto->getNombre(), producto->getDescripcion(), producto->getCategoria());

    string nickVendedor = producto->getVendedor()->getNickName();
    Usuario* u = this->sistema->usuarios.find(nickVendedor)->second;
    Vendedor* v = dynamic_cast<Vendedor*>(u);

    nuevoProducto->setVendedor(v);
    v->addProducto(nuevoProducto);

    // this->sistema->productos[producto->getNombre()] = nuevoProducto;
    this->sistema->productos.insert(make_pair(producto->getNombre(), nuevoProducto));
  }
}

set<DTOProducto*> IProductoController::obtenerProductos() {
  set<DTOProducto*> retorno;
  map<string, Producto*> listaProductos = this->sistema->productos;

  for (pair<string, Producto*> par : listaProductos) {
    retorno.insert(crearDTOProducto(par.second));
  }

  return retorno;

}

DTOProducto* IProductoController::obtenerInfoProducto(string codProd) {
  Producto* producto = this->sistema->productos.find(codProd)->second;

  return crearDTOProducto(producto);
}

DTOProducto *IProductoController::crearDTOProducto(Producto* producto) {

  Vendedor* v = producto->getVendedor();

  DTOVendedor* vendedor = new DTOVendedor(v->getNickName(), v->getPassword(), v->getFechaNacimiento(), v->getRut());

  return new DTOProducto(
    producto->getCodigo(), producto->getStock(), producto->getPrecio(),
    producto->getNombre(), producto->getDescripcion(), producto->getCategoria(), vendedor );
}
