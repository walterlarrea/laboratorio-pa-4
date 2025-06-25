
#ifndef COMPRAPROD_H
#define COMPRAPROD_H

#include "Producto.h"
#include "Compra.h"

class Compra;
class Producto;

class CompraProd {
private:
  Producto* producto;
  int cantidad;
  bool enviado;
  Compra* compra;
public:
  CompraProd();
  CompraProd(Compra* compra, Producto* producto, int cantidad);
  CompraProd(Compra* compra, Producto* producto, int cantidad, bool enviado);
  ~CompraProd();

  Producto* getProducto();
  int getCantidad();
  bool getEnviado();
  double getMonto();
  Compra* getCompra();
  void setProducto(Producto* producto);
  void setCantidad(int cantidad);
  void setEnviado(bool enviado);
  void setCompra(Compra* compra);
};



#endif //COMPRAPROD_H
