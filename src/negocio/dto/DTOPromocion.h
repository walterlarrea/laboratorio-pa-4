#ifndef DTOPROMOCION_H
#define DTOPROMOCION_H
#include "DTOProdPromo.h"
#include "../dt/DTFecha.h"
#include <set>

using namespace std;


class DTOPromocion {

private:
  string nombre;
  string descripcion;
  double descuento;
  DTFecha* fechaVencimiento;
  set<DTOProdPromo*> prodPromos;

public:
  DTOPromocion();
  DTOPromocion(string nombre, string descripcion, double descuento, DTFecha* fechaVencimiento);
  ~DTOPromocion();

  string getNombre();
  string getDescripcion();
  double getDescuento();
  DTFecha* getFechaVencimiento();
  set<DTOProdPromo*> getProdPromos();
  void addProdPromo(DTOProdPromo* prodPromo);
};



#endif //DTOPROMOCION_H
