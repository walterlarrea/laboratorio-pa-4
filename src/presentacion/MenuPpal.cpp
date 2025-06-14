//
// Created by walte on 14/06/2025.
//

#include "MenuPpal.h"
#include <iostream>

using namespace std;

MenuPpal::MenuPpal() {

}

MenuPpal::~MenuPpal() {
  // TODO Auto-generated destructor stub
}

void MenuPpal::mostrarMenu() {
  int op = 0;
  do {
    cout << "*** Menu principal ***" << endl;
    cout <<"1) Alta Usuario" << endl;
    cout <<"2) Realizar Ejercicio " << endl;
    cout <<"0) Salir " << endl;
    cout <<"Ingrese una opcion: " << endl;

    cin >> op;
    switch (op) {
      case 0:
        break;
      case 1: {
        // AltaUsuario altaUsuario;
        // altaUsuario.altaUsuario();
      }
      break;
      case 2:
      {
        // RealizarEjercicio realizarEjercicio;
        // realizarEjercicio.realizarEjercicio();
      }
      break;
      default:
        cout << "Opcion desconocida" << endl;
    }

  } while (op != 0);

  cout << "Fin del programa" << endl;
}