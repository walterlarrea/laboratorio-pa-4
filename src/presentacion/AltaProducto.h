//
// Created by walte on 14/06/2025.
//

#ifndef ALTAPRODUCTO_H
#define ALTAPRODUCTO_H

#include "../negocio/controller/producto/IProducto.h"



class AltaProducto {
private:
  IProducto* iproducto;
  // ListarCategoriasProd* listarCategoriasProd;

	DTOProducto* ingresarProducto(string codigo);

public:
  AltaProducto();

  void altaProducto();

  virtual ~AltaProducto();
};



#endif //ALTAPRODUCTO_H
