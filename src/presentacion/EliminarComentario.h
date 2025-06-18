
#ifndef ELIMINARCOMENTARIO_H
#define ELIMINARCOMENTARIO_H

// #include "../negocio/controller/producto/IProducto.h"
#include "../negocio/controller/usuario/IUsuario.h"

class EliminarComentario {
private:
  // IProducto* iproducto;
  IUsuario* iusuario;

public:
  EliminarComentario();

  void eliminarComentario();

  virtual ~EliminarComentario();
};



#endif //ELIMINARCOMENTARIO_H
