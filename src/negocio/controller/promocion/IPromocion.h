#ifndef IPROMOCION_H
#define IPROMOCION_H
#include <string>
#include "../../dto/DTOPromocion.h"

using namespace std;

class IPromocion {
  public:
    virtual bool buscarExistencia(string codProd)=0;
    virtual void altaPromocion(DTOPromocion* promocion)=0;
};

#endif //IPROMOCION_H
