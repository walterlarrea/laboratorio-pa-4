
#ifndef COMPRA_H
#define COMPRA_H

#include "../dt/DTFecha.h"
#include "CompraProd.h"
#include "Producto.h"
#include "Cliente.h"

using namespace std;

class CompraProd;
class Cliente;
class Producto;

class Compra {
private:
  string codigo;
  DTFecha* fecha;
  set<CompraProd*> compraProds;
  Cliente* cliente;

public:
  Compra();
  Compra(Cliente* cliente, string codigo, DTFecha* fecha);
  ~Compra();

  void agregarLineaProducto(Producto* producto, int cantidad);

  string getCodigo();
  DTFecha* getFecha();
  double getMontoFinal();
  set<CompraProd*> getLineasProducto();
  Cliente* getCliente();
  void setCodigo(string codigo);
  void setFecha(DTFecha* fecha);
  void setCliente(Cliente* cliente);

};



#endif //COMPRA_H
