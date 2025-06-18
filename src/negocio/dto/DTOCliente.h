//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef DTOCLIENTE_H
#define DTOCLIENTE_H

//class Comentario;

#include "../dt/DTFecha.h"
#include "DTOUsuario.h"
#include "../dt/DTDireccion.h"

class DTOCliente : public DTOUsuario{
private:
    DTDireccion* direccion;
    string ciudadResidencia;
   // map<string, Comentario*> comentarios;
  //  map<string, Compra*> compras;

public:
    DTOCliente();
    DTOCliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia);

    string getCiudad();
    DTDireccion* getDireccion();
    string toString() const;

   // map<string, Comentario*> getComentarios();

   // void eliminarComentario(Comentario* comentario);
  //  void agregarCompra(Compra* compra);
  //  void agregarComentario(Comentario* comentario);

    ~DTOCliente();
};
#endif //DTOCLIENTE_H
