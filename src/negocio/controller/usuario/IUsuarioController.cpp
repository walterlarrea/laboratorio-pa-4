//
// Created by Guillermina Rodriguez on 17/6/25.
//
#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include <set>
#include <string>
#include <stdexcept>
#include "IUsuarioController.h"

IUsuarioController::IUsuarioController() {
  this->sistema = Sistema::getInstance();
}
IUsuarioController::IUsuarioController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}

IUsuarioController::~IUsuarioController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}

bool IUsuarioController::verificarNickname(string nick) {
    bool result = false;

    map<string, Usuario*>::iterator it;

    for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); ++it) {
        if (nick == (*it).second->getNickName()) {
            result = true;
            break;
        }
    }

    return result;
};

void IUsuarioController::altaUsuario(DTOUsuario* u) {
    string nick = u->getNickName();
    auto& usuarios = sistema->usuarios;

    Usuario* nuevo = nullptr;

    if (DTOCliente* c = dynamic_cast<DTOCliente*>(u)) {
        nuevo = new Cliente(nick, c->getPassword(), c->getFechaNacimiento(), c->getDireccion(), c->getCiudad());
    } else if (DTOVendedor* v = dynamic_cast<DTOVendedor*>(u)) {
        nuevo = new Vendedor(nick, v->getPassword(), v->getFechaNacimiento(), v->getRut());
    }

    if (nuevo)
        usuarios[nick] = nuevo;
}


set<DTOUsuario*> IUsuarioController::listarUsuarios() {
    set<DTOUsuario*> resultado;
    auto& usuarios = sistema->usuarios;

    for (auto& par : usuarios) {
        Usuario* u = par.second;
        if (Cliente* c = dynamic_cast<Cliente*>(u)) {
            resultado.insert(new DTOCliente(c->getNickName(), c->getPassword(), c->getFechaNacimiento(), c->getDireccion(), c->getCiudad()));
        } else if (Vendedor* v = dynamic_cast<Vendedor*>(u)) {
            resultado.insert(new DTOVendedor(v->getNickName(), v->getPassword(), v->getFechaNacimiento(), v->getRut()));
        }
    }

    return resultado;
}
set<string> IUsuarioController::getUsuariosNick() {
  set<string> resultado;
  auto& usuarios = sistema->usuarios;

  for (auto& par : usuarios) {
    resultado.insert(par.first);
  }
  return resultado;
}


set<string> IUsuarioController::getClientesNick() {
  set<string> resultado;
  auto& usuarios = sistema->usuarios;

  for (auto& par : usuarios) {
    Usuario* u = par.second;
    if (Cliente* c = dynamic_cast<Cliente*>(u)) {
      resultado.insert(c->getNickName());
    }
  }

  return resultado;
}

set<string> IUsuarioController::getVendedoresNick() {
  set<string> resultado;
  map<string, Usuario*> usuarios = sistema->usuarios;

  for (auto& par : usuarios) {
    Usuario* u = par.second;
    if (Vendedor * v = dynamic_cast<Vendedor*>(u)) {
      resultado.insert(v->getNickName());
    }
  }

  return resultado;
}

DTOVendedor *IUsuarioController::getVendedor(string nickVendedor) {

  Usuario* u = sistema->usuarios.find(nickVendedor)->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  DTOVendedor* resultado;

  if (v != nullptr) {
    resultado = new DTOVendedor(v->getNickName(), v->getPassword(),
      v->getFechaNacimiento(), v->getRut());
  }

  return resultado;
}

set<DTOProducto*> IUsuarioController::getProdVendedor(string vendedor) {
  Usuario* u = sistema->usuarios.find(vendedor)->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  set<DTOProducto*> resultado;
  if (v != nullptr) {

  }

  return resultado;
}

set<DTOComentario*> IUsuarioController::getComentariosCliente(string nickCliente) {
  Usuario* u  = sistema->usuarios.find(nickCliente)->second;
  Cliente* cliente = dynamic_cast<Cliente*>(u);

  set<DTOComentario*> resultado;
  if (cliente != nullptr) {
    // Guardo Cliente en memoria
    this->memoria->setCliente(cliente);

    for (auto& par : cliente->getComentarios()) {
      set<DTOComentario*> respuestas;
      for (auto& resp : par.second->getRespuestas()) {
        respuestas.insert(new DTOComentario(
        resp->getTexto(), resp->getFecha(),
      resp->getCliente()->getNickName(), resp->getProducto()->getNombre(), set<DTOComentario*>()
        ));
      }
      resultado.insert(
        new DTOComentario(par.second->getTexto(), par.second->getFecha(),
        par.second->getCliente()->getNickName(), par.second->getProducto()->getNombre(), respuestas
        ));
    }
  }
  return resultado;
}

void IUsuarioController::eliminarComentario(string com) {
  // Recupero el Cliente seleccionado anteriormente
  Cliente* cliente = this->memoria->getCliente();

  // Busca el comentario por clave de texto
  Comentario* comentario = cliente->getComentarios().find(com)->second;
  if (comentario != nullptr) {
    // Si el comentario existe,
    // es eliminado de memoria y de la lista de comentarios del cliente
    cliente->eliminarComentario(comentario);
    delete comentario;
  }
}

void IUsuarioController::dejarComentario(DTOComentario* dto) {
  string nickCliente = dto->getCliente();
  string nombreProd = dto->getProducto();

  Cliente* cliente = dynamic_cast<Cliente*>(sistema->usuarios[nickCliente]);
  Producto* producto = sistema->productos[nombreProd];

  Comentario* comentario = new Comentario(dto->getTexto(), dto->getFecha(), cliente, producto);

  producto->agregarComentario(comentario);
  cliente->agregarComentario(comentario);
}

void IUsuarioController::responderComentario(DTOComentario* dto, string textoPadre) {
  string nickCliente = dto->getCliente();
  string nombreProd = dto->getProducto();

  Cliente* cliente = dynamic_cast<Cliente*>(sistema->usuarios[nickCliente]);
  Producto* producto = sistema->productos[nombreProd];

  Comentario* comentario = new Comentario(dto->getTexto(), dto->getFecha(), cliente, producto);

  Comentario* comentarioPadre = producto->getComentarios().at(textoPadre);
  comentarioPadre->agregarRespuesta(comentario);

  cliente->agregarComentario(comentario);
}



#endif
