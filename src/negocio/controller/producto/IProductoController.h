#ifndef IPRODUCTOCONTROLLER_H
#define IPRODUCTOCONTROLLER_H

#include "../../dto/DTOProducto.h"
#include "IProducto.h"
#include "../Sistema.h"
#include "../Memoria.h"


class IProductoController:public IProducto {
private:
  Sistema* sistema; //cada controlador de la aplicación tiene una instancia de la clase sistema
  //solo existe una instancia de la clase sistema en toda la aplicacion
  Memoria* memoria;
public:
  IProductoController();
  explicit IProductoController(void* idSesion);
  ~IProductoController();

  bool verificarCodigo(string codigo);
  void agregarProducto(DTOProducto *producto);
  set<string> listarProductos();
  DTOProducto* obtenerInfoProducto(string nombreProd);

  // TODO: borrar este metodo porque no es un CU
  set<DTOProducto*> obtenerProductos();
};



#endif
