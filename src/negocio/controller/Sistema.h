#ifndef NEGOCIO_CONTROLLER_SISTEMA_CPP_
#define NEGOCIO_CONTROLLER_SISTEMA_CPP_
#include <set>

#include "../dominio/Producto.h"
#include "Memoria.h"
#include "../dominio/Promocion.h"


using namespace std;

//Esto es un singleton (ver patron de diseño)

class Sistema {
private:
  Sistema();
  static Sistema* miSistema;
  void inicializarDatos();

public:
  //Esta es una clase utilitaria por lo que no tiene sentido encapsular su estado
  //(no utilizo getters y setters)

  static Sistema* getInstance(); //metodo de clase que devuele siempre la misma instancia
  virtual ~Sistema();

  map<string, Producto*> productos;
  map<string, Usuario*> usuarios;
  map<string, Promocion*> promociones;
  map<string, Compra*> compras;
};

#endif /* NEGOCIO_CONTROLLER_SISTEMA_CPP_ */