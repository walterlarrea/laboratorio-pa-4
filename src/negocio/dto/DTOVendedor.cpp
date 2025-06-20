//
// Created by Guillermina Rodriguez on 17/6/25.
//
#include "../dt/DTFecha.h"
#include "../dto/DTOVendedor.h"

DTOVendedor::DTOVendedor() {}

DTOVendedor::DTOVendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut)
    : DTOUsuario(nickName, password, fechaNacimiento) {
    this->rut=rut;
}

DTOVendedor::~DTOVendedor() {

}

string DTOVendedor::getRut() {
    return this->rut;
}

/*
map<string,DTOProducto*> DTOVendedor::getProductos() {
  return this->productos;
}

*/

std::string DTOVendedor::toString() const {
    return "Vendedor - Nick: " + this->nickName +
           ", RUT: " + this->rut +
           ", Fecha de nacimiento: " + this->fechaNacimiento->toString();
}
