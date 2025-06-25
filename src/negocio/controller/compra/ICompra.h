
#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <set>

#include "../../dto/DTOProdCantidad.h"

class ICompra {
  public:
    virtual void altaCompra(set<DTOProdCantidad*>)=0;
};


#endif //ICOMPRA_H
