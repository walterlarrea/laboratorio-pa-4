
#ifndef CLIENTE_H
#define CLIENTE_H
#include <map>
#include <string>

#include "Comentario.h"
#include "Compra.h"
#include "Usuario.h"
#include "../dt/DTDireccion.h"

using namespace std;

class Cliente : public Usuario{
private:
    DTDireccion* direccion;
    string ciudadResidencia;
    map<string, Comentario*> comentarios;
    map<string, Compra*> compras;

public:
    Cliente();
    Cliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia);

    map<string, Comentario*> getComentarios();

    void eliminarComentario(Comentario* comentario);
    void agregarCompra(Compra* compra);
    void agregarComentario(Comentario* comentario);

    ~Cliente();
};



#endif //CLIENTE_H
