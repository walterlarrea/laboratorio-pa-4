#include "IPromocionController.h"


IPromocionController::IPromocionController() {
  this->sistema = Sistema::getInstance();
}
IPromocionController::IPromocionController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}
IPromocionController::~IPromocionController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}

