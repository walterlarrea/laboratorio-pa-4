
#include "DTOProdPromo.h"

DTOProdPromo::DTOProdPromo() {  }

DTOProdPromo::DTOProdPromo(string codProd, int cant) {
  this->codProd = codProd;
  this->cant = cant;
}

DTOProdPromo::~DTOProdPromo() {  }

string DTOProdPromo::getProd() {
  return this->codProd;
}

int DTOProdPromo::getCant() {
  return this->cant;
}