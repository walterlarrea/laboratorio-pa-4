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
    auto& usuarios = this->sistema->usuarios;

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
    auto& usuarios = this->sistema->usuarios;

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
  auto& usuarios = this->sistema->usuarios;

  for (auto& par : usuarios) {
    resultado.insert(par.first);
  }
  return resultado;
}


set<string> IUsuarioController::getClientesNick() {
  set<string> resultado;
  auto& usuarios = this->sistema->usuarios;

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
  map<string, Usuario*> usuarios = this->sistema->usuarios;

  for (auto& par : usuarios) {
    Usuario* u = par.second;
    if (Vendedor * v = dynamic_cast<Vendedor*>(u)) {
      resultado.insert(v->getNickName());
    }
  }

  return resultado;
}

DTOVendedor *IUsuarioController::getVendedor(string nickVendedor) {

  Usuario* u = this->sistema->usuarios.find(nickVendedor)->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  DTOVendedor* resultado;

  if (v != nullptr) {
    resultado = new DTOVendedor(v->getNickName(), v->getPassword(),
      v->getFechaNacimiento(), v->getRut());
  }

  return resultado;
}

map<string, DTOProducto*> IUsuarioController::getProdVendedor(string vendedor) {

  Usuario* u = this->sistema->usuarios.find(vendedor)->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  map<string, DTOProducto*> resultado;

  for (pair<string,Producto*> par : v->getProductos()) {
    Producto* producto = par.second;

    DTOProducto* dt = new DTOProducto( producto->getCodigo(), producto->getStock(),
      producto->getPrecio(),producto->getNombre(), producto->getDescripcion(),
      producto->getCategoria());


    resultado.insert(make_pair(producto->getCodigo(),dt));
  }

  return resultado;
}

map<string, DTOProducto*> IUsuarioController::getProdVigentesVendedor(string vendedor) {

  Usuario* u = this->sistema->usuarios.find(vendedor)->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  map<string, DTOProducto*> resultado;

  for (pair<string,Producto*> par : v->getProductos()) {
    Producto* producto = par.second;

    if ( (producto->estaEnPromoVigente()) == false) {

      DTOProducto* dt = new DTOProducto( producto->getCodigo(), producto->getStock(),
        producto->getPrecio(),producto->getNombre(), producto->getDescripcion(), producto->getCategoria());

      resultado.insert(make_pair(producto->getCodigo(),dt));
    }

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
  Cliente* cliente = this->memoria->getCliente();
  if (!cliente) return;

  auto& comentarios = cliente->getComentarios();
  auto it = comentarios.find(com);
  if (it != comentarios.end()) {
    Comentario* comentario = it->second;
    eliminarComentarioRecursivo(comentario);
  }
}


void IUsuarioController::eliminarComentarioRecursivo(Comentario* comentario) {
  // Copia del set antes de borrar
  set<Comentario*> respuestas = comentario->getRespuestas();
  for (Comentario* respuesta : respuestas) {
    eliminarComentarioRecursivo(respuesta);
  }

  // Eliminar del cliente
  Cliente* cliente = comentario->getCliente();
  if (cliente && cliente->getComentarios().count(comentario->getTexto())) {
    cliente->eliminarComentario(comentario);
  }

  // Eliminar del producto
  Producto* producto = comentario->getProducto();
  if (producto) {
    auto& comentarios = producto->getComentarios();
    auto it = comentarios.find(comentario->getTexto());
    if (it != comentarios.end()) {
      comentarios.erase(it);
    } else {
      for (auto& par : comentarios) {
        auto& respuestas = par.second->getRespuestas();
        auto itResp = respuestas.find(comentario);
        if (itResp != respuestas.end()) {
          respuestas.erase(itResp);
          break;
        }
      }
    }
  }

  delete comentario;
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

  auto& comentarios = producto->getComentarios();
  auto it = comentarios.find(textoPadre);
  if (it != comentarios.end()) {
    it->second->agregarRespuesta(comentario);
    cliente->agregarComentario(comentario);
  } else {
    delete comentario;
    cout << "Error: Comentario padre no encontrado." << endl;
  }
}


void IUsuarioController::seleccionarCliente(string nickname) {
    Usuario* usuario = this->sistema->usuarios.find(nickname)->second;
    Cliente* cliente = dynamic_cast<Cliente*>(usuario);

    if (cliente != nullptr) {
        this->memoria->setCliente((cliente));
    }
}



#endif
