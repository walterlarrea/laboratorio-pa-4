
#ifndef CONSULTARPRODUCTO_H
#define CONSULTARPRODUCTO_H

#include "../negocio/controller/producto/IProducto.h"


class ConsultarProducto {
private:
  IProducto* iproducto;

public:
  ConsultarProducto();

  void consultarProducto();

  virtual ~ConsultarProducto();
};



#endif //CONSULTARPRODUCTO_H
