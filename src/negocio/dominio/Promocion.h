
#ifndef PROMOCION_H
#define PROMOCION_H
#include <string>

#include "../dt/DTFecha.h"

using namespace std;

class Promocion {

private:
  string nombre;
  string descripcion;
  double descuento;
  DTFecha* fecha;

public:
  Promocion();
  Promocion(string nombre, string descripcion, double descuento, DTFecha* fecha);
  ~Promocion();

  bool esVigente();
};



#endif //PROMOCION_H
