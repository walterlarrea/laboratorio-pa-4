
#include "Producto.h"

Producto::Producto() {}

Producto::Producto(
    string codigo, int stock, double precio,
    string nombre, string descripcion, ECatProducto* categoria) {
  this->codigo = codigo;
  this->stock = stock;
  this->precio = precio;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->categoria = categoria;
}

Producto::~Producto() {}

string Producto::getCodigo() {
  return this->codigo;
}
int Producto::getStock() {
  return this->stock;
}
double Producto::getPrecio() {
  return this->precio;
}
string Producto::getNombre() {
  return this->nombre;
}
string Producto::getDescripcion() {
  return this->descripcion;
}
ECatProducto* Producto::getCategoria() {
  return this->categoria;
}


// TODO: Para implementar .....
/*
string Producto::getNickVendedor() {

}
map<string, Comentario*> Producto::getComentarios() {

}

void Producto::setVendedor(Vendedor* v) {

}
bool Producto::vendedorIgualA(string nickVend) {

}
void Producto::disminuirStock(int cantidad) {

}
*/

