//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef DTOCLIENTE_H
#define DTOCLIENTE_H

//class Comentario;

#include "../dt/DTFecha.h"
#include "DTOUsuario.h"
#include "DTOCompra.h"
#include "../dt/DTDireccion.h"
#include <set>

using namespace std;

class DTOCliente : public DTOUsuario{
private:
    DTDireccion* direccion;
    string ciudadResidencia;
   // map<string, Comentario*> comentarios;
    set<DTOCompra*> compras;

public:
    DTOCliente();
    DTOCliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia);

    string getCiudad();
    DTDireccion* getDireccion();
    string toString() const override;

    set<DTOCompra*> getCompras();
    void addCompra(DTOCompra* compra);

   // map<string, Comentario*> getComentarios();

   // void eliminarComentario(Comentario* comentario);
  //  void agregarCompra(Compra* compra);
  //  void agregarComentario(Comentario* comentario);

    ~DTOCliente();
};
#endif //DTOCLIENTE_H
