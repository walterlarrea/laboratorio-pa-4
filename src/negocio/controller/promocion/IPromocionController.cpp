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
  Usuario* u = this->sistema->usuarios.find(promocion->getVendedor())->second;
  Vendedor* v = dynamic_cast<Vendedor*>(u);

  for (auto prodPromo : promocion->getProdPromos()) {
    Producto* producto = productos.find(prodPromo->getProd()->getCodigo())->second;
    nuevaPromo->addProdPromo(prodPromo->getCant(), producto);
  }

  nuevaPromo->setVendedor(v);
  this->sistema->promociones.insert(make_pair(nuevaPromo->getNombre(), nuevaPromo));

}

map<string, DTOPromocion*> IPromocionController::getPromociones() {
  map<string, Promocion*> promociones = this->sistema->promociones;
  map<string, DTOPromocion*> retorno;

  for (pair<string, Promocion*> par : promociones) {
    Promocion* promocion = par.second;

    Vendedor* vendedor = promocion->getVendedor();
    DTOPromocion* p = new DTOPromocion(promocion->getNombre(), promocion->getDescripcion(),
        promocion->getDescuento(), promocion->getFechaVencimiento());
    p->setVendedor(vendedor->getNickName());
    retorno.insert(make_pair(promocion->getNombre(), p));
  }

  return retorno;
}

map<string, DTOPromocion*> IPromocionController::getPromocionesVigentes() {
  map<string, Promocion*> promociones = this->sistema->promociones;
  map<string, DTOPromocion*> retorno;

  for (pair<string, Promocion*> par : promociones) {
    Promocion* promocion = par.second;

    if (promocion->esVigente()) {
      Vendedor* vendedor = promocion->getVendedor();
      DTOPromocion* p = new DTOPromocion(promocion->getNombre(), promocion->getDescripcion(),
          promocion->getDescuento(), promocion->getFechaVencimiento());
      p->setVendedor(vendedor->getNickName());
      retorno.insert(make_pair(promocion->getNombre(), p));
    }
  }

  return retorno;
}

set<DTOProdPromo*> IPromocionController::getPromoInfo(string nombrePromo) {
  set<DTOProdPromo*> retorno;
  Promocion* promo = this->sistema->promociones.find(nombrePromo)->second;
  if (promo != nullptr) {
    for (auto& prodPromo : promo->getProdPromos()) {

      DTOProducto* dtProd = new DTOProducto(prodPromo->getProducto()->getCodigo(), prodPromo->getProducto()->getStock(), prodPromo->getProducto()->getPrecio(), prodPromo->getProducto()->getNombre(), prodPromo->getProducto()->getDescripcion(), prodPromo->getProducto()->getCategoria());
      retorno.insert(new DTOProdPromo(dtProd, prodPromo->getCantMinima()));

    }
  }
  return retorno;
}
