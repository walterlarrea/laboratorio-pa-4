
#include "EliminarComentario.h"

// #include "../negocio/controller/producto/IProductoController.h"
#include "../negocio/controller/usuario/IUsuarioController.h"
#include "../negocio/dto/DTOComentario.h"

#include <iostream>


using namespace std;

EliminarComentario::EliminarComentario() {
  void* sesion = &sesion;
  // sesion = &sesion;
  // this->iproducto = new IProductoController(sesion);
  this->iusuario = new IUsuarioController(sesion);
}

 EliminarComentario::~EliminarComentario() {
  delete this->iusuario;
}

void EliminarComentario::eliminarComentario() {
  set<string> nombreClientes = this->iusuario->getClientesNick();

  if (nombreClientes.size() > 0){
    cout << "Estos son todos los clientes en el sistema:" << endl << endl;

    for (string nombre : nombreClientes) {
      cout << nombre << endl;
    }

    string clienteSeleccionado;
    cout << endl << "Ingrese el nombre del cliente: ";
    cin >> clienteSeleccionado;

    set<DTOComentario*> comentarios = this->iusuario->getComentariosCliente(clienteSeleccionado);
    // vector <int> v(comentarios.begin(), comentarios.end());

    if (!comentarios.empty()) {
      int index = 0;
      cout << "Comentarios del cliente seleccionado: " << clienteSeleccionado << endl;
      for (DTOComentario* com : comentarios) {
        cout << index << " - " << com->toString() << endl;
        ++index;
      }

      int indiceSeleccionado;
      cout << endl << "Ingrese el numero de comentario a eliminar: ";
      cin >> indiceSeleccionado;

      if (indiceSeleccionado < 0 || indiceSeleccionado < comentarios.size()) {
        auto it = comentarios.begin();
        advance(it, indiceSeleccionado);

        string textoComSelec = (*it)->getTexto();
        this->iusuario->eliminarComentario(textoComSelec);
      } else {
        cout << "El numero de comentario ingresado no existe." << endl << endl;
      }
    } else {
      cout << "El cliente seleccionado no ha hecho comentarios." << endl << endl;
    }
  } else {
    cout << "No existen clientes en el sistema." << endl << endl;
  }
}
