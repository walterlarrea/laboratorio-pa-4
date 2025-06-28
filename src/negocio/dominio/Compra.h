
#ifndef COMPRA_H
#define COMPRA_H

#include "../dt/DTFecha.h"
#include "../dto/DTOCompraCliente.h"
#include "Cliente.h"
#include "CompraProd.h"
#include "Producto.h"

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

  static int contador;
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

  void enviarProducto(string codProd);
  set<Producto*> productosConEnvioPendiente(string nickVend);
  DTOCompraCliente* tienePendienteDeEnviar(string codProd);

  static int getContadorCompras();
};



#endif //COMPRA_H
