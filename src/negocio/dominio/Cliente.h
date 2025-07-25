
#ifndef CLIENTE_H
#define CLIENTE_H
#include <map>
#include <string>

#include "Comentario.h"
#include "Compra.h"
#include "Usuario.h"
#include "../dt/DTDireccion.h"

using namespace std;

class Comentario;
class Compra;
class Producto;

class Cliente : public Usuario{
private:
  DTDireccion* direccion;
  string ciudadResidencia;
  map<string, Comentario*> comentarios;
  map<string, Compra*> compras;

public:
  Cliente();
  Cliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia);

  DTDireccion* getDireccion();
  string getCiudad();
  map<string, Comentario*>& getComentarios();
  map<string, Compra*>& getCompras();

  void eliminarComentario(Comentario* comentario);
  void agregarCompra(Compra* compra, string codigo);
  void agregarComentario(Comentario* comentario);

  ~Cliente();
};



#endif //CLIENTE_H
