
#ifndef DTOCOMENTARIO_H
#define DTOCOMENTARIO_H

#include <set>
#include <string>


#include "../dt/DTFecha.h"

class DTOComentario {
private:
  string texto;
  DTFecha* fecha;
  string cliente;
  string producto;
  set<DTOComentario*> respuestas;

public:
  DTOComentario();
  DTOComentario(string texto, DTFecha* fecha, string cliente, string producto, set<DTOComentario*> respuestas);

  string getTexto();
  DTFecha* getFecha();
  string getCliente();
  string getProducto();
  set<DTOComentario*> getRespuestas();

  string toString();

  ~DTOComentario();
};



#endif //DTOCOMENTARIO_H
