//
// Created by Walter on 27/06/2025.
//

#include "DTOCompraCliente.h"

DTOCompraCliente::DTOCompraCliente() = default;
DTOCompraCliente::DTOCompraCliente(DTFecha* fechaCompra, string nickCliente, string codCompra, double montoFinal) {
  this->fechaCompra = fechaCompra;
  this->nickCliente = nickCliente;
  this->codigoCompra = codCompra;
  this->montoFinal = montoFinal;
}
DTOCompraCliente::~DTOCompraCliente() = default;

DTFecha* DTOCompraCliente::getFechaCompra() {
  return this->fechaCompra;
}
string DTOCompraCliente::getNickCliente() {
  return this->nickCliente;
}
string DTOCompraCliente::getCodigoCompra() {
  return this->codigoCompra;
}
double DTOCompraCliente::getMontoFinal() {
  return this->montoFinal;
}

string DTOCompraCliente::toString() {
  return "" + this->nickCliente + " - " + this->fechaCompra->toString();
}