
#ifndef PROMOCION_H
#define PROMOCION_H
#include <list>
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
  list<ProdPromo*> prodPromos;

public:
  Promocion();
  Promocion(string nombre, string descripcion, double descuento, DTFecha* fecha);
  ~Promocion();

  string getNombre();
  string getDescripcion();
  double getDescuento();
  DTFecha* getFechaVencimiento();
  void addProdPromo(int cantMinima, Producto* prod);
};



#endif //PROMOCION_H
