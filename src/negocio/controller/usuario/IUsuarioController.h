//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include "../../dto/DTOUsuario.h"
#include "IUsuario.h"
#include "../Sistema.h"
#include <set>
#include "../../dto/DTOUsuario.h"
#include "../../dto/DTOCliente.h"
#include "../../dto/DTOVendedor.h"
#include "../../dominio/Usuario.h"
#include "../../dominio/Cliente.h"
#include "../../dominio/Vendedor.h"

using namespace std;

class IUsuarioController : public IUsuario {
private:
    Sistema* sistema; //cada controlador de la aplicación tiene una instancia de la clase sistema
    //solo existe una instancia de la clase sistema en toda la aplicacion
    Memoria* memoria;
public:
    IUsuarioController();
    explicit IUsuarioController(void* idSesion);
    ~IUsuarioController();

    bool verificarNickname(string nick);
    virtual void altaUsuario(DTOUsuario* u);
    virtual set<DTOUsuario*> listarUsuarios();
    virtual set<string> getUsuariosNick();
    virtual set<string> getClientesNick();
    virtual set<string> getVendedoresNick();
    virtual DTOVendedor* getVendedor(string nickVendedor);
    virtual map<string, DTOProducto*> getProdVendedor(string vendedor);
    virtual map<string, DTOProducto*> getProdVigentesVendedor(string vendedor);
    virtual set<DTOComentario*> getComentariosCliente(string nickCliente);
    virtual void eliminarComentario(string com);
    virtual void eliminarComentarioRecursivo(Comentario* com);
    virtual void dejarComentario(DTOComentario* dto);
    virtual void responderComentario(DTOComentario* dto, string textopadre);

    virtual void seleccionarCliente(string nickname);
};

#endif


