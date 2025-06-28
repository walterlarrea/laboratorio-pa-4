
#include "Compra.h"

#include <ctime>

int Compra::contador = 0;

Compra::Compra() {
  contador++;
};
Compra::Compra(Cliente* cliente, string codigo, DTFecha* fecha) {
  contador++;

  this->codigo = codigo;
  this->fecha = fecha;
  this->cliente = cliente;
  cliente->agregarCompra(this, codigo);
}
Compra::~Compra() {
  delete this->fecha;
}

void Compra::agregarLineaProducto(Producto* producto, int cantidad) {
  this->compraProds.insert(new CompraProd(this, producto, cantidad));
}

string Compra::getCodigo() {
  return codigo;
}
DTFecha* Compra::getFecha() {
  return fecha;
}
double Compra::getMontoFinal() {
  double montoFinal = 0.0;
  for (auto& linea : this->compraProds) {
    montoFinal += linea->getMonto();
  }
  return montoFinal;
}
set<CompraProd*> Compra::getLineasProducto() {
  return this->compraProds;
}
Cliente* Compra::getCliente() {
  return this->cliente;
}
void Compra::setCodigo(string codigo) {
  this->codigo = codigo;
}
void Compra::setFecha(DTFecha* fecha) {
  this->fecha = fecha;
}
void Compra::setCliente(Cliente* cliente) {
  this->cliente = cliente;
}

void Compra::enviarProducto(string codProd) {
  for (auto& linea: this->compraProds) {
    if (linea->codigoProductoEsIgualA(codProd)) {
      linea->marcarProductoEnviado();
      break;
    }
  }
}

set<Producto*> Compra::productosConEnvioPendiente(string nickVend) {
  set<Producto*> productosDelVendedorConEnvioPendiente;
  for (auto& linea : this->compraProds) {
    bool esDeInteres = linea->envioPendienteYEsDeVendedor(nickVend);
    if (esDeInteres) {
      productosDelVendedorConEnvioPendiente.insert(linea->getProducto());
    }
  }
  return productosDelVendedorConEnvioPendiente;
}

DTOCompraCliente* Compra::tienePendienteDeEnviar(string codProd) {
  for (auto& linea : this->compraProds) {
    bool esDeInteres = linea->envioPendienteYEsProducto(codProd);
    if (esDeInteres) {
      return new DTOCompraCliente(this->fecha, this->cliente->getNickName(), this->codigo, this->getMontoFinal());
      break;
    }
  }
  return nullptr;
}

int Compra::getContadorCompras() {
  return contador;
};