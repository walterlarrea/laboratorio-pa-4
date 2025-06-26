#ifndef DTOCOMPRA_H
#define DTOCOMPRA_H

#include <string>
#include "DTOProducto.h"
#include "DTCompraProd.h"
#include <set>

using namespace std;

class DTOCompra {
private:
  string codigo;
  DTFecha* fecha;
  double montoFinal;
  set<DTCompraProd*> compraProds;

public:
  DTOCompra();
  DTOCompra(string codigo, double montoFinal, DTFecha* fecha);
  ~DTOCompra();
  string getCodigo();
  double getMontoFinal();
  DTFecha* getFecha();
  set<DTCompraProd*> getCompraProds();
  void addCompraProd(DTCompraProd* compraProd);
};



#endif //DTOCOMPRA_H
