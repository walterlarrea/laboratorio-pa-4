
#include "Producto.h"
#include <format>

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

string Producto::toString() {
  return "" + this->codigo + " - " + this->nombre + " - " + this->descripcion +
    " - " + to_string(this->stock) + " - " + format("{:.2f}", this->precio) +
    " - " + this->categoria->getNombre();
}
