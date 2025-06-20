
#ifndef PROMOCION_H
#define PROMOCION_H
#include <map>
#include <string>

#include "../dt/DTFecha.h"
#include "ProdPromo.h"

using namespace std;

class Promocion {

private:
  string nombre;
  string descripcion;
  double descuento;
  DTFecha* fechaVencimiento;
  map<string,ProdPromo*> prodPromo;

public:
  Promocion();
  Promocion(string nombre, string descripcion, double descuento, DTFecha* fecha);
  ~Promocion();

  string getNombre();
  string getDescripcion();
  double getDescuento();
  DTFecha* getFechaVencimiento();
};



#endif //PROMOCION_H
