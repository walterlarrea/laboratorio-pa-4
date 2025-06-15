//
// Created by walte on 14/06/2025.
//

#include "DTOProducto.h"
#include <iostream>
using namespace std;

DTOProducto::DTOProducto() {}

DTOProducto::DTOProducto(
    string codigo, int stock, double precio,
    string nombre, string descripcion, ECatProducto* categoria) {

  this->codigo = codigo;
  this->stock = stock;
  this->precio = precio;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->categoria = categoria;

}

string DTOProducto::getCodigo() {
  return this->codigo;
}
int DTOProducto::getStock() {
  return this->stock;
}
double DTOProducto::getPrecio() {
  return this->precio;
}
string DTOProducto::getNombre() {
  return this->nombre;
}
string DTOProducto::getDescripcion() {
  return this->descripcion;
}
ECatProducto* DTOProducto::getCategoria() {
  return this->categoria;
}

DTOProducto::~DTOProducto() {}
