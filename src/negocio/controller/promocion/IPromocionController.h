#ifndef IPROMOCIONCONTROLLER_H
#define IPROMOCIONCONTROLLER_H

#include "IPromocion.h"
#include "../Sistema.h"
#include "..

class IPromocionController : public IPromocion {
private:
  Sistema* sistema;
  Memoria* memoria;

public:
  IPromocionController();
  explicit IPromocionController(void* idSesion);
  ~IPromocionController();

  void crearPromocion(set<DTProductoPromo>);
};



#endif //IPROMOCIONCONTROLLER_H
