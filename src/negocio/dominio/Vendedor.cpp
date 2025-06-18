#include "Vendedor.h"

Vendedor::Vendedor() {}

Vendedor::Vendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut)
    : Usuario(nickName, password, fechaNacimiento) {
    this->rut=rut;
}

Vendedor::~Vendedor() {

}

string Vendedor::getRut() {
    return this->rut;
}

// TODO: Implementar ....

void Vendedor::addProducto(Producto *producto) {

}

map<string,Producto*> Vendedor::getProductos() {

}



