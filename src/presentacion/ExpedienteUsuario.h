#ifndef EXPEDIENTEUSUARIO_H
#define EXPEDIENTEUSUARIO_H

#include "../negocio/controller/usuario/IUsuario.h"
#include "../negocio/dto/DTOCliente.h"

using namespace std;

class ExpedienteUsuario {
private:
  IUsuario* iusuario;

  string ingresarUsuario();
  void listarExpedienteCliente(DTOCliente*);
  void listarExpedienteVendedor(DTOVendedor*);
public:
   ExpedienteUsuario();
   ~ExpedienteUsuario();
   void expedienteUsuario();
};



#endif //EXPEDIENTEUSUARIO_H
