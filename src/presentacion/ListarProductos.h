
#ifndef LISTARPRODUCTOS_H
#define LISTARPRODUCTOS_H

#include "../negocio/controller/producto/IProducto.h"


class ListarProductos {
private:
  IProducto* iproducto;

public:
  ListarProductos();

  void listarProductos();

  virtual ~ListarProductos();
};



#endif //LISTARPRODUCTOS_H
