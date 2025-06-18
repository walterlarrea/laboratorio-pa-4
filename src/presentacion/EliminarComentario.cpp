
#include "EliminarComentario.h"

#include "../negocio/controller/producto/IProductoController.h"

#include<iostream>

using namespace std;

EliminarComentario::EliminarComentario() {
  void* sesion = &sesion;
  // sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
}

 EliminarComentario::~EliminarComentario() {
  delete this->iproducto;
}

void EliminarComentario::eliminarComentario() {
  // set<string> nombreClientes = this->icliente->getClientesNick();
  //
  // if (nombreClientes.size() > 0){
  //   cout << "Estos son todos los clientes en el sistema:" << endl << endl;
  //
  //   for (string nombre : nombreClientes) {
  //     cout << nombre << endl;
  //   }
  //
  //   string clienteSeleccionado;
  //   cout << endl << "Ingrese el nombre del cliente: ";
  //   cin >> clienteSeleccionado;
  //
  //
  //   set<DTOComentario*> comentarios = this->icliente->getComentariosCliente(clienteSeleccionado);
  //   // vector <int> v(comentarios.begin(), comentarios.end());
  //
  //   int index = 0;
  //   cout << "Comentarios del cliente seleccionado: " << clienteSeleccionado << endl;
  //   for (DTOComentario* com : comentarios) {
  //     cout << index << " - " << com->toString() << endl;
  //     ++index;
  //   }
  //
  //   int indiceSeleccionado;
  //   cout << endl << "Ingrese el numero de comentario a eliminar: ";
  //   cin >> indiceSeleccionado;
  //
  //   auto it = comentarios.begin();
  //   advance(it, indiceSeleccionado);
  //
  //   string textoComSelec = (*it)->getTexto();
  //   // TODO: al icliente enviar msj eliminarComentario(string com, string nomCliente)
  // } else {
  //   cout << "No existen clientes en el sistema." << endl << endl;
  // }
}
