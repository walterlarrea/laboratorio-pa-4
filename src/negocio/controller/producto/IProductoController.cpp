#include "IProductoController.h"
#include "../../dto/DTOProducto.h"
#include "../../dominio/Producto.h"


IProductoController::IProductoController() {
  this->sistema = Sistema::getInstance();
}

bool IProductoController::verificarCodigo(string codigo) {
  bool result = false;

  map<string, Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    if (codigo == (*it).second->getCodigo()) {
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

  // this->sistema->productos[producto->getNombre()] = nuevoProducto;
  this->sistema->productos.insert(make_pair(producto->getNombre(), nuevoProducto));
  }
}

set<DTOProducto*> IProductoController::obtenerProductos() {
  set<DTOProducto*> productos;

  map<string, Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    productos.insert(new DTOProducto(
        (*it).second->getCodigo(), (*it).second->getStock(), (*it).second->getPrecio(),
        (*it).second->getNombre(), (*it).second->getDescripcion(), (*it).second->getCategoria()
        ));
  }

  return productos;
}