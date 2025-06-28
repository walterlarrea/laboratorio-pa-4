
#include <format>
#include <iomanip>


#include "../negocio/controller/producto/IProductoController.h"
#include "ConsultarProducto.h"

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
  cout << "--- Consultar Producto ---" << endl << endl;

  set<DTOProducto*> productos = this->iproducto->obtenerProductos();

  if (!productos.empty()){
    cout << "Estos son todos los productos en el sistema:" << endl << endl;

    for (DTOProducto* producto : productos) {
      cout << producto->getCodigo()<< " - " << producto->getNombre() << endl;
    }

    string prodSeleccionado;
    cout << endl << "Ingrese el codigo del producto para ver toda su informacion: ";
    cin >> prodSeleccionado;

    DTOProducto* producto = this->iproducto->obtenerInfoProducto(prodSeleccionado);

    if (producto == nullptr) {
      cout << endl << "Código de producto inválido." << endl ;
      return;
    }

    cout << endl << "Información del producto seleccionado:" << endl << endl;

    cout << left;
    cout << setw(8) << "Codigo" << "|"
         << setw(25) << "Nombre" << "|"
         << setw(25) << "Descripcion" << "|"
         << right
         << setw(7) << "Stock" << "|"
         << setw(9) << "Precio" << "|"
         << left
         << setw(20) << "Categoria" << "|"
         << setw(12) << "Vendedor" << "|" << endl;
    cout << setfill('-') << setw(113) << "-" << endl;

    cout << left << setfill(' ');
    cout << setw(8) << producto->getCodigo() << "|"
         << setw(25) << producto->getNombre() << "|"
         << setw(25) << producto->getDescripcion() << "|"
         << right
         << setw(7) << to_string(producto->getStock()) << "|"
         << setw(9) << format("{:.2f}", producto->getPrecio()) << "|"
         << left
         << setw(20) << producto->getCategoria()->getNombre() << "|"
         << setw(12) << producto->getVendedor()->getNickName() << "|" << endl;
    cout << setfill('_') << setw(113) << "_" << endl;

    // cout << producto->toString() << endl << endl;
  } else {
    cout << endl << "No existen productos en el sistema." << endl << endl;
  }
}
