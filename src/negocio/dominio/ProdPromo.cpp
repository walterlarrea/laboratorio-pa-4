
#include "ProdPromo.h"

 ProdPromo::ProdPromo() {

 }

 ProdPromo::ProdPromo(int cantMinima, Producto *prod, Promocion *promocion) {
   this->cantMinima = cantMinima;
   this->prod = prod;
   this->promocion = promocion;
   this->prod->addProdPromo(this);
 }

 ProdPromo::~ProdPromo() {

 }

bool ProdPromo::estaEnPromoVigente() {
   return this->promocion->esVigente();
 }

int ProdPromo::getCantMinima() {
   return this->cantMinima;
 }

Producto* ProdPromo::getProducto() {
   return this->prod;
 }

Promocion* ProdPromo::getPromocion() {
   return this->promocion;
 }




