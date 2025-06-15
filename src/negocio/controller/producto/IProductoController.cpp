#include "IProductoController.h"
#include "../../dto/DTOProducto.h"
#include "../../dominio/Producto.h"


IProductoController::IProductoController() {
  this->sistema = Sistema::getInstance();
}

bool IProductoController::verificarCodigo(string codigo) {
  bool result = false;

  set<Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    if (codigo == (*it)->getCodigo()) {
      result = true;
      break;
    }
  }

  return result;
}

void IProductoController::agregarProducto(DTOProducto* producto) {
  Producto *nuevoProducto;

  if (producto != nullptr) {
    nuevoProducto = new Producto(producto->getCodigo(), producto->getStock(), producto->getPrecio(),
      producto->getNombre(), producto->getDescripcion(), producto->getCategoria());
  }

  this->sistema->productos.insert(nuevoProducto);
}

set<DTOProducto*> IProductoController::obtenerProductos() {
  set<DTOProducto*> productos;

  set<Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    productos.insert(new DTOProducto(
        (*it)->getCodigo(), (*it)->getStock(), (*it)->getPrecio(),
        (*it)->getNombre(), (*it)->getDescripcion(), (*it)->getCategoria()
        ));
  }

  return productos;
}