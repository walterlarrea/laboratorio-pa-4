
#ifndef PRODPROMO_H
#define PRODPROMO_H
#include "Producto.h"
#include "Promocion.h"

class Promocion;
class Producto;

class ProdPromo {
private:
  int cantMinima;
  Producto* prod;
  Promocion* promocion;
public:
  ProdPromo();
  ProdPromo(int cantMinima, Producto* prod, Promocion* promocion);
  ~ProdPromo();

  bool estaEnPromoVigente();
  int getCantMinima();
  Producto* getProducto();
  Promocion* getPromocion();
};



#endif //PRODPROMO_H
