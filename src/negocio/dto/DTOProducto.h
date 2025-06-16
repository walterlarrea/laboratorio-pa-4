//
// Created by walte on 14/06/2025.
//

#ifndef DTOPRODUCTO_H
#define DTOPRODUCTO_H

#include <iostream>
#include"../enums/ECatProducto.h"

using namespace std;

class DTOProducto {
private:
  string codigo;
  int stock;
  double precio;
  string nombre;
  string descripcion;
  ECatProducto* categoria;

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
