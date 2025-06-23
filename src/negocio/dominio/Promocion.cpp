#include "Promocion.h"

 Promocion::Promocion() {  }

 Promocion::Promocion(string nombre, string descripcion, double descuento, DTFecha *fecha) {
   this->nombre = nombre;
   this->descripcion = descripcion;
   this->descuento = descuento;
   this->fechaVencimiento = fecha;
 }

 Promocion::~Promocion() {

 }

string Promocion::getNombre() {
   return nombre;
 }

string Promocion::getDescripcion() {
   return descripcion;
 }

double Promocion::getDescuento() {
   return descuento;
 }

DTFecha* Promocion::getFechaVencimiento() {
   return fechaVencimiento;
 }

void Promocion::addProdPromo(int cantMinima, Producto *prod) {
   if (cantMinima > 0 & prod != nullptr) {
     ProdPromo * prodPromo = new ProdPromo(cantMinima, prod);
     this->prodPromos.push_back(prodPromo);
   }
 }
