//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef ALTAUSUARIO_H
#define ALTAUSUARIO_H


#include "../negocio/dt/DTFecha.h"
#include "../negocio/controller/usuario/IUsuarioController.h"
#include "../negocio/controller/usuario/IUsuario.h"
#include "../negocio/dto/DTOUsuario.h"
#include "../negocio/dto/DTOCliente.h"
#include "../negocio/dto/DTOVendedor.h"

class AltaUsuario {
private:
    IUsuario* iusuario;
    DTOUsuario* registroUsuario(string nick);

public:
    AltaUsuario();

   void altaUsuario();

    virtual ~AltaUsuario();
};
#endif //ALTAUSUARIO_H


