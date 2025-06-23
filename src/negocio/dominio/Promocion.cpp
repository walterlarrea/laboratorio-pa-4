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
   return this->nombre;
 }

string Promocion::getDescripcion() {
   return this->descripcion;
 }

double Promocion::getDescuento() {
   return this->descuento;
 }

DTFecha* Promocion::getFechaVencimiento() {
   return this->fechaVencimiento;
 }

map<string, ProdPromo*> Promocion::getProdPromos() {
   return this->prodPromos;
 }

void Promocion::addProdPromo(int cantMinima, Producto *prod) {
   if (cantMinima > 0 & prod != nullptr) {
    ProdPromo *prodPromo = new ProdPromo(cantMinima, prod);
     this->prodPromos.insert(make_pair(prod->getCodigo(), prodPromo));
   }
 }

bool Promocion::buscarExistencia(string codProd) {
   map<string, ProdPromo*> prodPromos = this->getProdPromos();
   bool vacio = prodPromos.find(codProd)->first.empty();

   if ( vacio ) {
     return false;
   } else {
     return true;
   }

 }
