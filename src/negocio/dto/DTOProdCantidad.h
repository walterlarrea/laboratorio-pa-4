
#ifndef DTOPRODCANTIDAD_H
#define DTOPRODCANTIDAD_H
#include "DTOProducto.h"


class DTOProdCantidad {
private:
  int cantidad;
  DTOProducto* producto;

public:
  DTOProdCantidad();
  DTOProdCantidad(int cantidad, DTOProducto* producto);
  ~DTOProdCantidad();

  int getCantidad();
  DTOProducto* getProducto();

  string toString();
};



#endif //DTOPRODCANTIDAD_H
