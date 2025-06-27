#ifndef DTOPROMOCION_H
#define DTOPROMOCION_H
#include <set>
#include "../dt/DTFecha.h"
#include "DTOProdPromo.h"

#include "DTOVendedor.h"

using namespace std;

class DTOProdPromo;

class DTOPromocion {

private:
  string nombre;
  string descripcion;
  double descuento;
  DTFecha* fechaVencimiento;
  set<DTOProdPromo*> prodPromos;
  string vendedor;

public:
  DTOPromocion();
  DTOPromocion(string nombre, string descripcion, double descuento, DTFecha* fechaVencimiento);
  ~DTOPromocion();

  string getNombre();
  string getDescripcion();
  double getDescuento();
  DTFecha* getFechaVencimiento();
  set<DTOProdPromo*> getProdPromos();
  string getVendedor();
  void setVendedor(string v);
  void addProdPromo(DTOProdPromo* prodPromo);

  string toString();
};



#endif //DTOPROMOCION_H
