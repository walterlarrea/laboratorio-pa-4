//
// Created by Guillermina Rodriguez on 21/6/25.
//

#ifndef DEJARCOMENTARIO_H
#define DEJARCOMENTARIO_H
#include "../negocio/controller/producto/IProducto.h"
#include "../negocio/controller/usuario/IUsuario.h"

class DejarComentario {
private:
  IProducto* iproducto;
  IUsuario* iusuario;

public:

  DejarComentario();

  void dejarComentario();

  virtual ~DejarComentario();
};

#endif //DEJARCOMENTARIO_H
