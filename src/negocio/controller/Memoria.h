
#ifndef MEMORIA_H
#define MEMORIA_H

#include <map>
#include <string>

#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Producto.h"
#include "../dominio/Compra.h"

class Memoria;

// Singleton
class MemoriaTemporal {
private:
  MemoriaTemporal();
  static MemoriaTemporal* miMemoriaTemporal;
  static map<void*, pair<Memoria*, int>> sesiones;

  Memoria* agregarSesion(void* sesion);
public:

  virtual ~MemoriaTemporal();
  static MemoriaTemporal* getInstance(); //metodo de clase que devuele siempre la misma instancia

  Memoria* darSesion(void* sesion);
  void terminarSesion(void* sesion);
};

class Memoria {
private:
  string nombreConsumidor; // Nombre consumidor nunca es expuesto

  Usuario* usuario;
  Cliente* cliente;
  Vendedor* vendedor;
  Producto* producto;
  Compra* compra;
public:
  // void reset(); // Pone todas las referencias en nullptr

  Memoria();
  ~Memoria();

  Usuario* getUsuario();
  Cliente* getCliente();
  Vendedor* getVendedor();
  Producto* getProducto();
  Compra* getCompra();

  void setUsuario(Usuario* usuario);
  void setCliente(Cliente* cliente);
  void setVendedor(Vendedor* vendedor);
  void setProducto(Producto* producto);
  void setCompra(Compra* compra);
};


#endif //MEMORIA_H
