//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef LISTARUSUARIOS_H
#define LISTARUSUARIOS_H
#include "../negocio/controller/usuario/IUsuario.h"

class ListarUsuarios {
private:
    IUsuario* iusuario;

public:
    ListarUsuarios();

    void listarUsuarios();

    virtual ~ListarUsuarios();
};

#endif //LISTARUSUARIOS_H
