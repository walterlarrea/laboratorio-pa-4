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

set<ProdPromo*> Promocion::getProdPromos() {
   return this->prodPromos;
 }

Vendedor* Promocion::getVendedor() {
   return this->vendedor;
 }

void Promocion::addProdPromo(int cantMinima, Producto *prod) {
   if (cantMinima > 0 & prod != nullptr) {
    ProdPromo *prodPromo = new ProdPromo(cantMinima, prod, this);
     this->prodPromos.insert(prodPromo);
   }
 }

bool Promocion::buscarExistencia(string codProd) {
   // TODO eliminar
 }

void Promocion::setVendedor(Vendedor* v) {
   this->vendedor = v;
 }

bool Promocion::esVigente() {
   return this->fechaVencimiento->esVigente();
 }
