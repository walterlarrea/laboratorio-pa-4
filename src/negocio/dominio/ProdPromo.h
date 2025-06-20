
#ifndef PRODPROMO_H
#define PRODPROMO_H
#include "Producto.h"


class ProdPromo {
private:
  int cantMinima;
  Producto* prod;
public:
  ProdPromo();
  ProdPromo(int cantMinima, Producto* prod);
  ~ProdPromo();
};



#endif //PRODPROMO_H
