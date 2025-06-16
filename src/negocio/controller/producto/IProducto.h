#ifndef IPRODUCTO_H
#define IPRODUCTO_H


#include<set>
#include "../../dto/DTOProducto.h"

class IProducto {
  public:
    virtual bool verificarCodigo(string codigo)=0;
    virtual void agregarProducto(DTOProducto* producto)=0;
    virtual set<DTOProducto*> obtenerProductos()=0;
    virtual set<string> listarProductos()=0;
    virtual DTOProducto* obtenerInfoProducto(string nombreProd)=0;
};


#endif //IPRODUCTO_H