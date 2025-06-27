#ifndef DTCOMPRAPROD_H
#define DTCOMPRAPROD_H

#include "DTOProducto.h"


class DTCompraProd {
private:
  int cantidad;
  bool enviado;
  double monto;
  DTOProducto* producto;
public:
  DTCompraProd();
  DTCompraProd(int cantidad, bool enviado, double monto, DTOProducto* producto);
  ~DTCompraProd();
  int getCantidad();
  bool getEnviado();
  double getMonto();
  DTOProducto* getProducto();
};



#endif //DTCOMPRAPROD_H
