
#include "Cliente.h"

Cliente::Cliente() {}

Cliente::Cliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia)
    : Usuario{nickname, password, fechaNacimiento} {
    this->direccion = direccion;
    this->ciudadResidencia = ciudadResidencia;
}

Cliente::~Cliente() {

}

string Cliente::getCiudad() {
    return this->ciudadResidencia;
}
DTDireccion *Cliente::getDireccion() {
    return this->direccion;
}
// TODO: Implementar...
map<string, Comentario*> Cliente::getComentarios() {
  return this->comentarios;
}
void Cliente::eliminarComentario(Comentario* comentario) {
  this->comentarios.erase(comentario->getTexto());
}
void Cliente::agregarCompra(Compra* compra) {

}
void Cliente::agregarComentario(Comentario* comentario) {
  this->comentarios.insert(pair(comentario->getTexto(), comentario));
}

