#ifndef IPROMOCIONCONTROLLER_H
#define IPROMOCIONCONTROLLER_H


#include "../Sistema.h"
#include "IPromocion.h"
#include <iostream>

using namespace std;

class IPromocionController : public IPromocion {
private:
  Sistema* sistema;
  Memoria* memoria;

public:
  IPromocionController();
  explicit IPromocionController(void* idSesion);
  ~IPromocionController();

  bool buscarExistencia(string codProd);
  void altaPromocion(DTOPromocion* promocion);
};



#endif //IPROMOCIONCONTROLLER_H
