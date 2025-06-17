#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<string>
#include"../enums/ECatProducto.h"
#include "Vendedor.h"
#include "Comentario.h"

class Vendedor;
class Comentario;

using namespace std;

class Producto {
private:
  string codigo;
  int stock;
  double precio;
  string nombre;
  string descripcion;
  ECatProducto* categoria;
  Vendedor* vendedor;
  map<string, Comentario*> comentarios;

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
  string getNickVendedor();
  map<string, Comentario*> getComentarios();

  void setVendedor(Vendedor* v);
  bool vendedorIgualA(string nickVend);
  void disminuirStock(int cantidad);

  ~Producto();
};

#endif
