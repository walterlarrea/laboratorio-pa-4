#include "Comentario.h"

Comentario::Comentario() {}
Comentario::Comentario(string texto, DTFecha* fecha, Cliente* cliente, Producto* producto) {
  this->texto = texto;
  this->fecha = fecha;
  this->cliente = cliente;
  this->producto = producto;
}

Comentario::~Comentario() {
  this->eliminarRespuestas();
}


// TODO Implementar ...
void Comentario::eliminarRespuestas() {
  // TODO
}
void Comentario::agregarRespuesta(Comentario* respuesta) {
  this->respuestas.insert(respuesta);
}


string Comentario::getTexto() {
  return this->texto;
}
DTFecha* Comentario::getFecha() {
  return this->fecha;
}
Cliente* Comentario::getCliente() {
  return this->cliente;
}
Producto* Comentario::getProducto() {
  return this->producto;
}
set<Comentario*> Comentario::getRespuestas() {
  return respuestas;
}

void Comentario::setTexto(string texto) {
  this->texto = texto;
}
void Comentario::setFecha(DTFecha* fecha) {
  this->fecha = fecha;
}
void Comentario::setCliente(Cliente* cliente) {
  this->cliente = cliente;
}
void Comentario::setProducto(Producto* producto) {
  this->producto = producto;
}
void Comentario::setRespuestas(set<Comentario*> respuestas) {
  this->respuestas = respuestas;
}