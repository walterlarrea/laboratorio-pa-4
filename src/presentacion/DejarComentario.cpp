//
// Created by Guillermina Rodriguez on 21/6/25.
//
#include "../negocio/controller/usuario/IUsuarioController.h"
#include "../negocio/controller/producto/IProductoController.h"
#include "../negocio/dto/DTOComentario.h"
#include "DejarComentario.h"

#include <iostream>


using namespace std;

DejarComentario::DejarComentario() {
  void* sesion = &sesion;
  // sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
  this->iusuario = new IUsuarioController(sesion);
};

DejarComentario::~DejarComentario() {
  delete this->iusuario;
  delete this->iproducto;
}

void DejarComentario::dejarComentario() {
  DTFecha* fecha = new DTFecha(12, 2, 2025);
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

  set<string> productos = iproducto->listarProductos();
  if (productos.empty()) {
    cout << "No hay productos disponibles." << endl;
    return;
  }

  cout << "Productos disponibles:" << endl;
  for (const string& p : productos)
    cout << "- " << p << endl;

  string nombreProd;
  cout << "Seleccione producto: ";
  cin >> nombreProd;

  int tipo;
  cout << "1 - Comentario nuevo\n2 - Responder a comentario\nSeleccione tipo: ";
  cin >> tipo;

  string texto;
  if (tipo == 1) {
    cout << "Ingrese comentario: ";
    cin.ignore();
    getline(cin, texto);

    DTOComentario* dto = new DTOComentario(texto, fecha, nick, nombreProd, {});
    iusuario->dejarComentario(dto);
  } else if (tipo == 2) {
    set<DTOComentario*> comentarios = iproducto->getComentariosProducto(nombreProd);
    if (comentarios.empty()) {
      cout << "No hay comentarios en este producto." << endl;
      return;
    }

    cout << "Comentarios del producto:" << endl;
    int i = 0;
    vector<string> referencias;
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

      DTOComentario* dto = new DTOComentario(texto, fecha, nick, nombreProd, {});
      iusuario->responderComentario(dto, ref);
    } else {
      cout << "Indice invalido." << endl;
    }
  } else {
    cout << "Opcion invalida." << endl;
  }
}



