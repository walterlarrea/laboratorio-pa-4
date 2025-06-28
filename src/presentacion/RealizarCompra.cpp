
#include "RealizarCompra.h"

#include "../negocio/controller/producto/IProductoController.h"
#include "../negocio/controller/usuario/IUsuarioController.h"

#include <chrono>
#include <ctime>
#include <format>
#include <iomanip>
#include <iostream>

#include "../negocio/controller/compra/ICompraController.h"
#include "../negocio/dto/DTOProdCantidad.h"

using namespace std;

RealizarCompra::RealizarCompra() {
  void* sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
  this->iusuario = new IUsuarioController(sesion);
  this->icompra = new ICompraController(sesion);
}

RealizarCompra::~RealizarCompra() {
  delete this->iproducto;
  delete this->iusuario;
  delete this->icompra;
}

void RealizarCompra::realizarCompra() {
  cout << "--- Realizar Compra ---" << endl << endl;

  if (this->iusuario->getClientesNick().size() == 0) {
    cout << "No existen usuarios registrados en el sistema." << endl << endl;
    return;
  }

  this->ingresarCliente();

  set<DTOProdCantidad*> prodsCantidad = this->ingresarProductosCompra();

  if (prodsCantidad.empty()) {
    cout << endl << "No se ingresaron productos. Compra cancelada." << endl << endl;
  }

  this->mostrarDetallesCompra(prodsCantidad);

  int confirmacion = 0;
  cout << endl << "Confirma la compra? (1 = Si  |  0 = No): ";
  cin >> confirmacion;
  if (confirmacion == 1) {
    this->icompra->altaCompra(prodsCantidad);
  } else {
    cout << endl << endl << "Compra cancelada.";
  }
}

void RealizarCompra::ingresarCliente() {
  set<string> nicksClientes = this->iusuario->getClientesNick();

  if (nicksClientes.size() == 0) {
    cout << "No existen usuarios registrados en el sistema." << endl << endl;
    return;
  }

  cout << "Estos son todos los usuarios registrados en el sistema:" << endl << endl;
  for (auto& nick : nicksClientes) {
    cout << "- " << nick << endl;
  }

  string clienteSeleccionado;
  cout << endl << "Ingrese el nombre del cliente: ";
  cin >> clienteSeleccionado;

  this->iusuario->seleccionarCliente(clienteSeleccionado);
}

set<DTOProdCantidad*> RealizarCompra::ingresarProductosCompra() {
  // Map para no recorrer la lista cada vez que se revisa
  // si el producto ya fue agregado a la compra
  map<string, DTOProdCantidad*> prodsCantidadMap;

  // Creo un map de productos para no recorrer la lista cada vez
  // que se ingresa un producto a la compra
  map<string, DTOProducto*> productos;
  for (DTOProducto* prod : this->iproducto->obtenerProductos()) {
    productos.insert(pair(prod->getCodigo(), prod));
  }

  int ingresarProducto = 0;
  do {
    cout << "Estos son los productos registrados en el sistema: " << endl;
    for (auto& producto : productos) {
      cout << producto.second->toString() << endl;
    }
    cout << endl << "Desea agregar productos a la compra? (1 = Si  |  0 = No): ";
    cin >> ingresarProducto;

    if (ingresarProducto == 1) {
      string codigoSelec;
      int cantSelec;
      cout << endl << "Ingrese el codigo de producto para agregar a la compra: ";
      cin >> codigoSelec;
      cout << endl << "Ingrese la cantidad deseada del producto seleccionado anteriormente: ";
      cin >> cantSelec;

      if (prodsCantidadMap.contains(codigoSelec)) {
        cout << endl << "Error: No se puede ingresar un mismo producto mas de una vez." << endl << endl;
      } else {
        DTOProducto* producto = productos.find(codigoSelec)->second;
        prodsCantidadMap.insert(
          pair(producto->getCodigo(), new DTOProdCantidad(cantSelec, producto))
          );
      }
    }
  } while (ingresarProducto == 1);

  set<DTOProdCantidad*> prodsCantidad;
  for (auto& producto : prodsCantidadMap) {
    prodsCantidad.insert(producto.second);
  }
  return prodsCantidad;
}

void RealizarCompra::mostrarDetallesCompra(set<DTOProdCantidad*> prodsCantidad) {
  double precioTotal = 0.0;

  for (auto& producto : prodsCantidad) {
    precioTotal += producto->getProducto()->getPrecio() * producto->getCantidad();
  }

  DTFecha* fecha = DTFecha::obtenerFechaActual();

  cout << "Detalles de la compra: " << endl << endl;
  cout << setfill('_') << setw(73) << "_" << endl;
  cout << "Fecha: " << fecha->toString() << endl;
  cout << setfill('-') << setw(73) << "-" << endl;

  int numLinea = 1;

  cout << setfill(' ') << left;
  cout << setw(2) << "#" << "|"
       << setw(40) << "Producto" << "|"
       << setw(6) << "Cant." << "|"
       << setw(10) << "Precio u." << "|"
       << setw(10) << "Precio t." << "|" << endl;
  cout << setfill('_') << setw(73) << "_" << endl;

  for (auto& producto : prodsCantidad) {
    cout << setfill(' ') << left;
    cout << setw(2) << to_string(numLinea) << "|";
    cout << setw(40) << producto->getProducto()->getNombre() << "|";
    cout << right;
    cout << setw(6) << producto->getCantidad() << "|";
    cout << setw(10) << "$" + format("{:.2f}", producto->getProducto()->getPrecio() * producto->getCantidad()) << "|";
    cout << setw(10) << "$" + format("{:.2f}", producto->getProducto()->getPrecio()) << "|" << endl;
    cout << setfill('-') << setw(73) << "-" << endl;
    numLinea++;
  }
  cout << setfill(' ') << left;
  cout << setw(10) << "   TOTAL -";
  cout << right;
  cout << setw(52) << " ";

  cout << setw(10) << "$" + format("{:.2f}", precioTotal) << "|" << endl;
  cout << setfill('_') << setw(73) << "_" << endl;

}
