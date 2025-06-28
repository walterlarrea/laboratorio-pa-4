//
// Created by Guillermina Rodriguez on 17/6/25.
//
// ListarUsuarios.cpp
#include "ListarUsuarios.h"
#include "../negocio/controller/usuario/IUsuarioController.h"
#include <iostream>

ListarUsuarios::ListarUsuarios() {
    void* sesion = &sesion;
    this->iusuario = new IUsuarioController(sesion);
};

ListarUsuarios::~ListarUsuarios() {
    delete this->iusuario;
}

void ListarUsuarios::listarUsuarios() {
    cout << "--- Listar Usuarios ---" << endl << endl;

    std::set<DTOUsuario*> usuarios = this->iusuario->listarUsuarios();

    if (usuarios.size() > 0) {
        cout << "Estos son todos los usuarios registrados en el sistema:" << endl << endl;
        for (DTOUsuario* u : usuarios) {
            std::cout << u->toString() << std::endl;
        }
    }else {
        cout << "No existen usuarios registrados en el sistema." << endl << endl;
    }
}

