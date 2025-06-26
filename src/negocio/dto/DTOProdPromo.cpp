
#include "DTOProdPromo.h"

DTOProdPromo::DTOProdPromo() {  }

DTOProdPromo::DTOProdPromo(DTOProducto* prod, int cant) {
  this->prod = prod;
  this->cant = cant;
}

DTOProdPromo::~DTOProdPromo() {  }

DTOProducto* DTOProdPromo::getProd() {
  return this->prod;
}

int DTOProdPromo::getCant() {
  return this->cant;
}

string DTOProdPromo::toString() {
  return this->prod->getCodigo() + " - " + this->prod->getNombre() + " - " + to_string(this->prod->getPrecio()) + " - Cantidad: " + to_string(this->cant);
}