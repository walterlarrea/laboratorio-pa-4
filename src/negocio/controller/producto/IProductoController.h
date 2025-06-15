#ifndef IPRODUCTOCONTROLLER_H
#define IPRODUCTOCONTROLLER_H

#include "../../dto/DTOProducto.h"
#include "IProducto.h"
#include "../Sistema.h"


class IProductoController:public IProducto {
private:
  Sistema* sistema; //cada controlador de la aplicación tiene una instancia de la clase sistema
  //solo existe una instancia de la clase sistema en toda la aplicacion

public:
  IProductoController();

  bool verificarCodigo(string codigo);
  void agregarProducto(DTOProducto *producto);
  set<DTOProducto*> obtenerProductos();
};



#endif
