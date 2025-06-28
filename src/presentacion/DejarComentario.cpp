//
// Created by Guillermina Rodriguez on 21/6/25.
//
#include "../negocio/controller/usuario/IUsuarioController.h"
#include "../negocio/controller/producto/IProductoController.h"
#include "../negocio/dto/DTOComentario.h"
#include "DejarComentario.h"
#include "../negocio/dt/DTFecha.h"

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

DejarComentario::DejarComentario() {
  void* sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
  this->iusuario = new IUsuarioController(sesion);
};

DejarComentario::~DejarComentario() {
  delete this->iusuario;
  delete this->iproducto;
}

void DejarComentario::dejarComentario() {
  cout << "--- Dejar Comentario ---" << endl << endl;

  DTFecha* fecha = DTFecha::obtenerFechaActual();
  set<string> usuarios = iusuario->getClientesNick();

  if (usuarios.empty()) {
    cout << "No hay usuarios disponibles." << endl;
    return;
  }

  cout << "Usuarios disponibles:" << endl;
  for (const string& u : usuarios)
    cout << "- " << u << endl;

  string nick;
  cout << "Seleccione nickname: ";
  cin >> nick;

  set<DTOProducto*> productos = this->iproducto->obtenerProductos();

  if (productos.size() > 0) {

    cout << "Estos son todos los productos en el sistema:" << endl << endl;

    for (auto producto : productos) {
      cout << producto->getCodigo() << " - " << producto->getNombre() << endl;
    }

  } else {
    cout << "No existen productos en el sistema." << endl << endl;
    return ;
  }

  string prodSeleccionado;
  cout << endl << "Ingrese el codigo del producto: ";
  cin >> prodSeleccionado;

  if (!iproducto->verificarCodigo(prodSeleccionado)) {
    cout<< "Código inválido" << endl ;
    return;
  }

  int tipo;
  cout << "1 - Comentario nuevo\n2 - Responder a comentario\nSeleccione tipo: ";
  cin >> tipo;

  string texto;
  if (tipo == 1) {
    cout << "Ingrese comentario: ";
    cin.ignore();
    getline(cin, texto);

    DTOComentario* dto = new DTOComentario(texto, fecha, nick, prodSeleccionado, {});
    iusuario->dejarComentario(dto);
  } else if (tipo == 2) {
    set<DTOComentario*> comentarios = iproducto->getComentariosProducto(prodSeleccionado);
    if (comentarios.empty()) {
      cout << "No hay comentarios en este producto." << endl;
      return;
    }

    cout << "Comentarios del producto:" << endl;
    int i = 0;
    pmr::vector<string> referencias;
    for (DTOComentario* c : comentarios) {
      cout << i << ": " << c->toString() << endl;
      referencias.push_back(c->getTexto());
      i++;
    }

    int indice;
    cout << "Seleccione comentario a responder: ";
    cin >> indice;

    if (indice >= 0 && indice < referencias.size()) {
      string ref = referencias[indice];
      cout << "Ingrese respuesta: ";
      cin.ignore();
      getline(cin, texto);

      DTOComentario* dto = new DTOComentario(texto, fecha, nick, prodSeleccionado, {});
      iusuario->responderComentario(dto, ref);
    } else {
      cout << "Indice invalido." << endl;
    }
  } else {
    cout << "Opcion invalida." << endl;
  }
}



