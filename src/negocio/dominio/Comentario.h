
#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <set>
#include <string>

#include "Cliente.h"
#include "Producto.h"
#include "../dt/DTFecha.h"

using namespace std;

class Cliente;
class Producto;

class Comentario {
private:
    string texto;
    DTFecha* fecha;
    Cliente* cliente;
    Producto* producto;
    set<Comentario*> respuestas;

public:
    Comentario();
    Comentario(string texto, DTFecha* fecha, Cliente* cliente, Producto* producto);
    ~Comentario(); // Sería el eliminarComentario()

    // getInfoComentario ?? TODO
    void eliminarRespuestas();
    void agregarRespuesta(Comentario* respuesta);

  string getTexto();
  DTFecha* getFecha();
  Cliente* getCliente();
  Producto* getProducto();
  set<Comentario*> getRespuestas();

  void setTexto(string texto);
  void setFecha(DTFecha* fecha);
  void setCliente(Cliente* cliente);
  void setProducto(Producto* producto);
  void setRespuestas(set<Comentario*> respuestas);
};



#endif //COMENTARIO_H
