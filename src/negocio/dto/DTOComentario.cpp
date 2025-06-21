
#include "DTOComentario.h"

 DTOComentario::DTOComentario() {}
 DTOComentario::DTOComentario(
   string texto, DTFecha *fecha, string cliente,
   string producto, set<DTOComentario *> respuestas) {
   this->texto = texto;
   this->fecha = fecha;
   this->cliente = cliente;
   this->producto = producto;
   this->respuestas = respuestas;
 }

 DTOComentario::~DTOComentario() {  }

string DTOComentario::getTexto() { return this->texto; }
DTFecha* DTOComentario::getFecha() { return this->fecha; }
string DTOComentario::getCliente() { return this->cliente; }
string DTOComentario::getProducto() { return this->producto; }
set<DTOComentario*> DTOComentario::getRespuestas() { return this->respuestas; }



string DTOComentario::toString() {
   return "" + this->getFecha()->toString() + " - " + this->getTexto() + ". "
   + to_string(this->getRespuestas().size()) + " rsp. | "
   + this->getProducto() + " - " + this->getCliente();
 }
