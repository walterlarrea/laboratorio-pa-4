
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

void Producto::setVendedor(Vendedor* v) {
  this->vendedor = v;
}

Vendedor* Producto::getVendedor() {
  return this->vendedor;
}
map<string, Comentario*>& Producto::getComentarios() {
return this->comentarios;
}

void Producto::agregarComentario(Comentario* c) {
  this->comentarios[c->getTexto()] = c;
}

void Producto::disminuirStock(int cantidad) {
  this->stock -= cantidad;
}


