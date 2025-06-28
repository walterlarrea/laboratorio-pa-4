
#ifndef ICOMPRA_H
#define ICOMPRA_H

#include <set>

#include "../../dto/DTOCompraCliente.h"
#include "../../dto/DTOProdCantidad.h"
#include "../../dto/DTOProducto.h"

class ICompra {
  public:
    virtual void altaCompra(set<DTOProdCantidad*>)=0;
    virtual map<string, DTOProducto*> productosConEnvioPendiente(string nickVend)=0;
    virtual set<DTOCompraCliente*> comprasPendientesProducto(string codProd)=0;
    virtual void enviarProductoCompra(DTOCompraCliente* compraCliente)=0;
};


#endif //ICOMPRA_H
