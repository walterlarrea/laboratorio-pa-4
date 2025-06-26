#ifndef CONSULTARPROMOCION_H
#define CONSULTARPROMOCION_H

#include "../negocio/controller/promocion/IPromocion.h"



class ConsultarPromocion {
private:
  IPromocion* ipromocion;

  void listarPromoSeleccionada(DTOPromocion* promociones);
  void listarPromociones(map<string, DTOPromocion*> promociones);

public:
  ConsultarPromocion();
  void consultarPromocion();
  virtual ~ConsultarPromocion();
};



#endif //CONSULTARPROMOCION_H
