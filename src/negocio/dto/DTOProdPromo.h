
#ifndef DTOPRODPROMO_H
#define DTOPRODPROMO_H

#include <string>
#include "../dto/DTOProducto.h"

using namespace std;

class DTOProdPromo {
private:
  DTOProducto* prod;
  int cant;
public:
  DTOProdPromo();
  DTOProdPromo(DTOProducto* producto, int cant);
  ~DTOProdPromo();

  DTOProducto* getProd();
  int getCant();
  string toString();
};



#endif //DTOPRODPROMO_H
