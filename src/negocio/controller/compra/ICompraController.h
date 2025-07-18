//
// Created by Walter on 25/06/2025.
//

#ifndef ICOMPRACONTROLLER_H
#define ICOMPRACONTROLLER_H
#include "../Sistema.h"
#include "ICompra.h"

#include <map>

using namespace std;


class ICompraController:public ICompra {
private:
  Sistema* sistema;

  Memoria* memoria;

public:
  ICompraController();
  explicit ICompraController(void* idSesion);
  ~ICompraController();

  virtual void altaCompra(set<DTOProdCantidad*> prodsCantidad);
  virtual map<string, DTOProducto*> productosConEnvioPendiente(string nickVend);
  virtual set<DTOCompraCliente*> comprasPendientesProducto(string codProd);
  virtual void enviarProductoCompra(DTOCompraCliente* compraCliente);
};



#endif //ICOMPRACONTROLLER_H
