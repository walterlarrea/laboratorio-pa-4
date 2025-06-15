
#include "MenuPpal.h"
#include "AltaProducto.h"
#include "ListarProductos.h"
#include <iostream>

using namespace std;

MenuPpal::MenuPpal() = default;

MenuPpal::~MenuPpal() = default;

void MenuPpal::mostrarMenu() {
  int op = 0;
  do {
    cout << "*** Menu principal ***" << endl;
    cout <<"1) Alta Producto" << endl;
    cout <<"2) Listar Productos" << endl;
    cout <<"0) Salir " << endl;
    cout <<"Ingrese una opcion: " << endl;

    cin >> op;
    switch (op) {
      case 0:
        break;
      case 1: {
        AltaProducto altaProducto;
        altaProducto.altaProducto();
      }
      break;
      case 2:
      {
        ListarProductos listarProductos;
        listarProductos.listarProductos();
      }
      break;
      default:
        cout << "Opcion desconocida" << endl;
    }

  } while (op != 0);

  cout << "Fin del programa" << endl;
}