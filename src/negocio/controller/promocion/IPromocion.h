#ifndef IPROMOCION_H
#define IPROMOCION_H
#include <string>
#include "../../dto/DTOPromocion.h"

using namespace std;

class IPromocion {
public:
  virtual bool buscarExistencia(string codProd)=0;
  virtual void altaPromocion(DTOPromocion* promocion)=0;
  virtual map<string, DTOPromocion*> getPromociones()=0;
  virtual map<string, DTOPromocion*> getPromocionesVigentes()=0;
  virtual set<DTOProdPromo*> getPromoInfo(string nombrePromo)=0;
};

#endif //IPROMOCION_H
