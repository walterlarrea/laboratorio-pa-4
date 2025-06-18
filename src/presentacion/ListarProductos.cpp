
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

  set<DTOProducto*>::iterator it;
  for (it = productos.begin(); it != productos.end(); ++it) {
    // Producto* producto = new Producto(
    //   (*it)->getCodigo(), (*it)->getStock(), (*it)->getPrecio(),
    //   (*it)->getNombre(), (*it)->getDescripcion(), (*it)->getCategoria()
    // );
    cout << (*it)->toString() << endl;
  }
  } else {
    cout << "No existen productos en el sistema." << endl << endl;
  }
}
