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

void Vendedor::addProducto(Producto *producto) {
  this->productos.insert(make_pair(producto->getCodigo(), producto));
}

map<string,Producto*> Vendedor::getProductos() {
  return this->productos;
}

void Vendedor::addPromocion(Promocion *promocion) {
  this->promociones.insert(promocion);
}

set<Promocion*> Vendedor::getPromociones() {
  return this->promociones;
}


