//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <set>
#include <string>
#include "../../dt/DTFecha.h"
#include "../../dto/DTOComentario.h"
#include "../../dto/DTOProducto.h"
#include "../../dto/DTOUsuario.h"

using namespace std;

class IUsuario {
public:
    virtual bool verificarNickname(string nick)=0;
    virtual void altaUsuario(DTOUsuario* u)=0;
    virtual set<DTOUsuario*> listarUsuarios()=0;
    virtual set<string> getUsuariosNick()=0;
    virtual set<string> getClientesNick()=0;
    virtual set<string> getVendedoresNick()=0;
    virtual DTOVendedor* getVendedor(string nickVendedor) = 0;
    virtual set<DTOProducto*> getProdVendedor(string vendedor)=0;
    virtual set<DTOComentario*> getComentariosCliente(string nickCliente)=0;
    virtual void eliminarComentario(string com)=0;
    virtual void dejarComentario(DTOComentario* dto) = 0;
    virtual void responderComentario(DTOComentario* dto, string textoPadre) = 0;


};

#endif


