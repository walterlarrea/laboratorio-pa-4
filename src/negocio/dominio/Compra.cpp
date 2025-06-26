
#include "Compra.h"

#include <ctime>

Compra::Compra() = default;
Compra::Compra(Cliente* cliente, string codigo, DTFecha* fecha) {
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
