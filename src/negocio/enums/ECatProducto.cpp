
#include "ECatProducto.h"

map<int, string>* ECatProducto::categorias = new map<int, string>{
  {0, "Ropa"},
  {1, "Electrodomestico"},
  {2, "Otros"}
};

bool ECatProducto::verificarCategoria(int valor) {
  return categorias->contains(valor);
}

string ECatProducto::getNombre(int valor){
  if(categorias->contains(valor)){
    return categorias->at(valor);
  }
  return ""; // TODO: Podria devolver nullptr
}

map<int, string>* ECatProducto::getCategorias() {
  return categorias;
}

// Meteodos de instancia

ECatProducto::ECatProducto() = default;

ECatProducto::ECatProducto(int valor) {
  this->valor = valor;
}

int ECatProducto::getValor(){
  return this->valor;
}
void ECatProducto::setValor(int valor){
  this->valor = valor;
}
string ECatProducto::getNombre(){
  if(categorias->contains(this->valor)){
    return categorias->at(this->valor);
  }
  return ""; // TODO: Podria devolver nullptr
}

string ECatProducto::toString(){
  if(categorias->contains(this->valor)){
    return categorias->at(this->valor);
  }
  return ""; // TODO: Podria devolver nullptr
}

ECatProducto::~ECatProducto() {}