//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef DTOVENDEDOR_H
#define DTOVENDEDOR_H
#include <set>
#include "../dt/DTFecha.h"
#include "DTOProducto.h"
#include "DTOUsuario.h"

#include "DTOPromocion.h"

class DTOProducto;
class DTOPromocion;

class DTOVendedor : public DTOUsuario {

private:
  string rut;
  set<DTOProducto*> productos;
  set<DTOPromocion*> promociones;

public:
  DTOVendedor();
  DTOVendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut);
  ~DTOVendedor();

  string getRut();
  void addProducto(DTOProducto* producto);
  set<DTOProducto*> getProductos();
  void addPromocion(DTOPromocion* promocion);
  set<DTOPromocion*> getPromociones();
  string toString() const override;

};


#endif //DTOVENDEDOR_H
