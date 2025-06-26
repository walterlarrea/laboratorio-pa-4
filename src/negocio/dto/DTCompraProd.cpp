#include "DTCompraProd.h"

DTCompraProd::DTCompraProd() {}

DTCompraProd::~DTCompraProd() {}

DTCompraProd::DTCompraProd(int cantidad, bool enviado, double monto, DTOProducto* producto) {
  this->cantidad = cantidad;
  this->enviado = enviado;
  this->monto = monto;
  this->producto = producto;
}

int DTCompraProd::getCantidad() {
  return this->cantidad;
}

bool DTCompraProd::getEnviado() {
  return this->enviado;
}

double DTCompraProd::getMonto() {
  return this->monto;
}

DTOProducto* DTCompraProd::getProducto() {
  return this->producto;
}