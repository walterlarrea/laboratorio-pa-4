
#include "ConsultarProducto.h"
#include "../negocio/controller/producto/IProductoController.h"

#include<iostream>

using namespace std;

ConsultarProducto::ConsultarProducto() {
  void* sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
}

ConsultarProducto::~ConsultarProducto() {
  delete this->iproducto;
}

void ConsultarProducto::consultarProducto() {
  set<DTOProducto*> productos = this->iproducto->obtenerProductos();

  if (!productos.empty()){
    cout << "Estos son todos los productos en el sistema:" << endl << endl;

    for (DTOProducto* producto : productos) {
      cout << producto->getNombre() << " - " << producto->getCodigo() << endl;
    }

    string prodSeleccionado;
    cout << endl << "Ingrese el codigo del producto: ";
    cin >> prodSeleccionado;

    DTOProducto* producto = this->iproducto->obtenerInfoProducto(prodSeleccionado);

    cout << "Información del producto:" << endl;
    cout << producto->toString() << endl << endl;
  } else {
    cout << "No existen productos en el sistema." << endl << endl;
  }
}
