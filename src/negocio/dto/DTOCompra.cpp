#include "DTOCompra.h"

DTOCompra::DTOCompra() { }

DTOCompra::~DTOCompra() { }

DTOCompra::DTOCompra(string codigo, double montoFinal, DTFecha* fecha) {
  this->codigo = codigo;
  this->montoFinal = montoFinal;
  this->fecha = fecha;
}

string DTOCompra::getCodigo() {
  return this->codigo;
}

double DTOCompra::getMontoFinal() {
  return this->montoFinal;
}

DTFecha* DTOCompra::getFecha() {
  return this->fecha;
}

set<DTCompraProd*> DTOCompra::getCompraProds() {
  return this->compraProds;
}

void DTOCompra::addCompraProd(DTCompraProd* compraProd) {
  this->compraProds.insert(compraProd);
}



