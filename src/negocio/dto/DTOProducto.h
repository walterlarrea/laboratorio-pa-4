
#ifndef DTOPRODUCTO_H
#define DTOPRODUCTO_H

#include <string>
#include "../enums/ECatProducto.h"
#include "../dto/DTOVendedor.h"

using namespace std;

class DTOVendedor;

class DTOProducto {
private:
  string codigo;
  int stock;
  double precio;
  string nombre;
  string descripcion;
  ECatProducto* categoria;
  DTOVendedor* vendedor;

public:
  DTOProducto();
  DTOProducto(
      string codigo, int stock, double precio,
      string nombre, string descripcion, ECatProducto* categoria);

  string getCodigo();
  int getStock();
  double getPrecio();
  string getNombre();
  string getDescripcion();
  ECatProducto* getCategoria();

  string toString();

  virtual ~DTOProducto();
};



#endif //DTOPRODUCTO_H
