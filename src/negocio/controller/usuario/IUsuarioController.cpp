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




#endif
