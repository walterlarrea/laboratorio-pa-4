
#ifndef REALIZARCOMPRA_H
#define REALIZARCOMPRA_H

#include "../negocio/controller/compra/ICompra.h"
#include "../negocio/controller/producto/IProducto.h"
#include "../negocio/controller/usuario/IUsuario.h"
#include "../negocio/dto/DTOProdCantidad.h"

class RealizarCompra {
private:
  IProducto *iproducto;
  IUsuario *iusuario;
  ICompra *icompra;

  void ingresarCliente();
  set<DTOProdCantidad*> ingresarProductosCompra();
  void mostrarDetallesCompra(set<DTOProdCantidad*> prodsCantidad);
public:
  RealizarCompra();
  virtual ~RealizarCompra();

  void realizarCompra();
};



#endif //REALIZARCOMPRA_H
