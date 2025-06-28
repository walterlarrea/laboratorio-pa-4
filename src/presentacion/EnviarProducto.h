//
// Created by Walter on 27/06/2025.
//

#ifndef ENVIARPRODUCTO_H
#define ENVIARPRODUCTO_H

#include "../negocio/controller/compra/ICompra.h"
#include "../negocio/controller/usuario/IUsuario.h"

class EnviarProducto {
private:
  IUsuario* iusuario;
  ICompra* icompra;

  DTOVendedor* ingresarVendedor();
  DTOProducto* seleccionarProducto(map<string, DTOProducto*> productos);
  DTOCompraCliente* seleccionarCompraCliente(set<DTOCompraCliente*> compraClientes);

public:
  EnviarProducto();

  void enviarProducto();

  virtual ~EnviarProducto();
};



#endif //ENVIARPRODUCTO_H
