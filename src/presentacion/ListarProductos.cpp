
#include "ListarProductos.h"
#include "../negocio/controller/producto/IProductoController.h"

#include<iostream>

using namespace std;

ListarProductos::ListarProductos() {
  void* sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
};

ListarProductos::~ListarProductos() {
  delete this->iproducto;
}

void ListarProductos::listarProductos() {
  set<DTOProducto*> productos = this->iproducto->obtenerProductos();

  if (productos.size() > 0) {

  cout << "Estos son todos los productos en el sistema:" << endl << endl;

  for (auto producto : productos) {
    cout << producto->getCodigo() << " - " << producto->getNombre() << endl;
  }

  } else {
    cout << "No existen productos en el sistema." << endl << endl;
  }
}
