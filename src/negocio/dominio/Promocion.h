
#ifndef PROMOCION_H
#define PROMOCION_H
#include <list>
#include <map>
#include <string>

#include "../dt/DTFecha.h"
#include "ProdPromo.h"

using namespace std;

class ProdPromo;
class Vendedor;
class Producto;

class Promocion {

private:
  string nombre;
  string descripcion;
  double descuento;
  DTFecha* fechaVencimiento;
  set<ProdPromo*> prodPromos;
  Vendedor* vendedor;

public:
  Promocion();
  Promocion(string nombre, string descripcion, double descuento, DTFecha* fecha);
  ~Promocion();

  string getNombre();
  string getDescripcion();
  double getDescuento();
  DTFecha* getFechaVencimiento();
  Vendedor* getVendedor();
  void setVendedor(Vendedor* v);
  set<ProdPromo*> getProdPromos();
  void addProdPromo(int cantMinima, Producto* prod);
  bool buscarExistencia(string codProd);
  bool esVigente();

};



#endif //PROMOCION_H
