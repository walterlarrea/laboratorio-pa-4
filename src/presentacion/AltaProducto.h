//
// Created by walte on 14/06/2025.
//

#ifndef ALTAPRODUCTO_H
#define ALTAPRODUCTO_H

#include "../negocio/controller/producto/IProducto.h"
#include "../negocio/controller/usuario/IUsuario.h"


class AltaProducto {
private:
  IProducto* iproducto;
  IUsuario* iusuario;
  // ListarCategoriasProd* listarCategoriasProd;

	DTOProducto* ingresarProducto(string codigo);
  string ingresarVendedor();

public:
  AltaProducto();

  void altaProducto();


  virtual ~AltaProducto();
};



#endif //ALTAPRODUCTO_H
