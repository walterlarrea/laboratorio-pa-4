
#include "DTOProdCantidad.h"

DTOProdCantidad::DTOProdCantidad() = default;
DTOProdCantidad::DTOProdCantidad(int cantidad, DTOProducto* producto) {
  this->cantidad = cantidad;
  this->producto = producto;
}
DTOProdCantidad::~DTOProdCantidad() = default;

int DTOProdCantidad::getCantidad() {
  return this->cantidad;
}
DTOProducto* DTOProdCantidad::getProducto() {
  return this->producto;
}

string DTOProdCantidad::toString() {
  return "" + to_string(this->cantidad) + " - " + this->producto->getNombre();
}