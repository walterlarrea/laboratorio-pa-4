#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<string>
#include"../enums/ECatProducto.h"

using namespace std;

class Producto {
private:
  string codigo;
  int stock;
  double precio;
  string nombre;
  string descripcion;
  ECatProducto* categoria;

public:
  Producto();
  Producto(string codigo, int stock, double precio,
    string nombre, string descripcion, ECatProducto* categoria);

  string getCodigo();
  int getStock();
  double getPrecio();
  string getNombre();
  string getDescripcion();
  ECatProducto* getCategoria();

  ~Producto();
};

#endif
