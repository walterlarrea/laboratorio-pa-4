
#ifndef ALTAPROMOCION_H
#define ALTAPROMOCION_H
#include "../negocio/controller/producto/IProducto.h"
#include "../negocio/controller/promocion/IPromocion.h"
#include "../negocio/controller/usuario/IUsuario.h"


class AltaPromocion {
private:
  IPromocion *ipromocion;
  IProducto *iproducto;
  IUsuario *iusuario;

public:
  AltaPromocion();
  void altaPromocion();
  ~AltaPromocion();
};



#endif //ALTAPROMOCION_H
