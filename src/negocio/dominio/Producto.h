#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "../enums/ECatProducto.h"
#include "Comentario.h"
#include "ProdPromo.h"
#include "Vendedor.h"

class Vendedor;
class Comentario;
class ProdPromo;

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
  set<ProdPromo*> prodPromos;

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
  Vendedor* getVendedor();
  map<string, Comentario*>& getComentarios();
  set<ProdPromo*> getProdPromos();
  void agregarComentario(Comentario* c);

  void addProdPromo(ProdPromo* prodPromo);
  void setVendedor(Vendedor* v);
  bool vendedorIgualA(string nickVend);
  void disminuirStock(int cantidad);
  bool estaEnPromoVigente();

  ~Producto();
};

#endif
