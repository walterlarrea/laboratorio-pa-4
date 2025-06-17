
#include "Cliente.h"

Cliente::Cliente() {}

Cliente::Cliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia)
    : Usuario{nickname, password, fechaNacimiento} {
    this->direccion = direccion;
    this->ciudadResidencia = ciudadResidencia;
}

Cliente::~Cliente() {

}

// TODO: Implementar...
map<string, Comentario*> Cliente::getComentarios() {

}
void Cliente::eliminarComentario(Comentario* comentario) {

}
void Cliente::agregarCompra(Compra* compra) {

}
void Cliente::agregarComentario(Comentario* comentario) {

}

