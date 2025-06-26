#include "DTOPromocion.h"

 DTOPromocion::DTOPromocion() {  }

 DTOPromocion::DTOPromocion(string nombre, string descripcion, double descuento, DTFecha *fechaVencimiento) {
   this->nombre = nombre;
   this->descripcion = descripcion;
   this->descuento = descuento;
   this->fechaVencimiento = fechaVencimiento;
 }

 DTOPromocion::~DTOPromocion() {
 }

string DTOPromocion::getNombre() {
   return this->nombre;
 }

string DTOPromocion::getDescripcion() {
   return this->descripcion;
 }

double DTOPromocion::getDescuento() {
   return this->descuento;
 }

DTFecha* DTOPromocion::getFechaVencimiento() {
   return this->fechaVencimiento;
 }

set<DTOProdPromo*> DTOPromocion::getProdPromos() {
   return this->prodPromos;
 }

string DTOPromocion::getVendedor() {
   return this->vendedor;
 }

void DTOPromocion::setVendedor(string v) {
   this->vendedor = v;
 }

void DTOPromocion::addProdPromo(DTOProdPromo* prodPromo) {
   this->prodPromos.insert(prodPromo);
 }

string DTOPromocion::toString() {
   return this->nombre + " - " +  this->descripcion + " - " + to_string(this->descuento) + " - " + this->fechaVencimiento->toString();
 }
