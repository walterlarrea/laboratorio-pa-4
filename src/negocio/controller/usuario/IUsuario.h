//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>
#include "../../dto/DTOUsuario.h"
#include "../../dt/DTFecha.h"

using namespace std;

class IUsuario {
public:
    virtual bool verificarNickname(string nick)=0;
    virtual void altaUsuario(DTOUsuario* u)=0;
    virtual set<DTOUsuario*> listarUsuarios()=0;

};

#endif


