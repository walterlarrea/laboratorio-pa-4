
#ifndef ELIMINARCOMENTARIO_H
#define ELIMINARCOMENTARIO_H

#include "../negocio/controller/producto/IProducto.h"

class EliminarComentario {
private:
  IProducto* iproducto;

public:
  EliminarComentario();

  void eliminarComentario();

  virtual ~EliminarComentario();
};



#endif //ELIMINARCOMENTARIO_H
