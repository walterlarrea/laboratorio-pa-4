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

bool IPromocionController::buscarExistencia(string codProd) {
  map<string, Promocion*> promociones = this->sistema->promociones;

  for (pair<string, Promocion*> promocion : promociones) {
    if (promocion.second->buscarExistencia(codProd)) {
      return true;
    }
  }

  return false;

}

void IPromocionController::altaPromocion(DTOPromocion *promocion) {
  Promocion* nuevaPromo = new Promocion(promocion->getNombre(), promocion->getDescripcion(),
    promocion->getDescuento(), promocion->getFechaVencimiento());

  map<string, Producto*> productos = this->sistema->productos;
  for (auto prodPromo : promocion->getProdPromos()) {
    Producto* producto = productos.find(prodPromo->getProd())->second;
    nuevaPromo->addProdPromo(prodPromo->getCant(), producto);
  }

}

