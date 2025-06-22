#ifndef IPRODUCTO_H
#define IPRODUCTO_H


#include<set>
#include "../../dto/DTOProducto.h"
#include "../../dto/DTOComentario.h"

class IProducto {
  public:
    virtual bool verificarCodigo(string codigo)=0;
    virtual void agregarProducto(DTOProducto* producto)=0;
    virtual set<DTOProducto*> obtenerProductos()=0;
    virtual set<string> listarProductos()=0;
    virtual DTOProducto* obtenerInfoProducto(string nombreProd)=0;
    virtual set<DTOComentario*> getComentariosProducto(string nombreProd) = 0;
    virtual void agregarComentario(string nombreProd, DTOComentario* comentario, string textoPadre = "") = 0;
};


#endif //IPRODUCTO_H