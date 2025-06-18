#ifndef DTFECHA_H
#define DTFECHA_H

#include<string>

using namespace std;

class DTFecha {
private:
  int dia;
  int mes;
  int anio;
public:

  DTFecha();
  DTFecha(int dia, int mes, int anio);
  ~DTFecha();

  string toString();
};



#endif //DTFECHA_H
