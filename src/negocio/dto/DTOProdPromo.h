
#ifndef DTOPRODPROMO_H
#define DTOPRODPROMO_H

#include <string>

using namespace std;

class DTOProdPromo {
private:
  string codProd;
  int cant;
public:
  DTOProdPromo();
  DTOProdPromo(string codProd, int cant);
  ~DTOProdPromo();

  string getProd();
  int getCant();
};



#endif //DTOPRODPROMO_H
