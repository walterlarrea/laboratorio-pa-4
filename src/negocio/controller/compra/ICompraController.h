//
// Created by Walter on 25/06/2025.
//

#ifndef ICOMPRACONTROLLER_H
#define ICOMPRACONTROLLER_H
#include "../Sistema.h"
#include "ICompra.h"


class ICompraController:public ICompra {
private:
  Sistema* sistema;

  Memoria* memoria;

public:
  ICompraController();
  explicit ICompraController(void* idSesion);
  ~ICompraController();

  virtual void altaCompra(set<DTOProdCantidad*> prodsCantidad);
};



#endif //ICOMPRACONTROLLER_H
