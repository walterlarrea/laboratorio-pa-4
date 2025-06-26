#ifndef DTFECHA_H
#define DTFECHA_H

#include<string>
#include<ctime>

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

  bool esVigente();
};


DTFecha* obtenerFechaActual();
#endif //DTFECHA_H
