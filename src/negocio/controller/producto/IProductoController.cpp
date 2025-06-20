#include "IProductoController.h"
#include "../../dto/DTOProducto.h"
#include "../../dominio/Producto.h"

IProductoController::IProductoController() {
  this->sistema = Sistema::getInstance();
}
IProductoController::IProductoController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}
IProductoController::~IProductoController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}


bool IProductoController::verificarCodigo(string codigo) {
  bool result = false;

  map<string, Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    if (codigo == it->second->getCodigo()) {
      result = true;
      break;
    }
  }

  return result;
}

void IProductoController::agregarProducto(DTOProducto* producto) {

  if (producto != nullptr) {
    Producto* nuevoProducto = new Producto(
      producto->getCodigo(), producto->getStock(), producto->getPrecio(),
      producto->getNombre(), producto->getDescripcion(), producto->getCategoria());

    Vendedor* v = dynamic_cast<Vendedor*>(this->sistema->usuarios.find(producto->getNickVendedor())->second);

    nuevoProducto->setVendedor(v);

    v->addProducto(nuevoProducto);

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
        (*it).second->getNombre(), (*it).second->getDescripcion(), (*it).second->getCategoria(), (*it).second->getNickVendedor()
        ));
  }

  return productos;
}

set<string> IProductoController::listarProductos() {
  set<string> nombreProductos;

  map<string, Producto*>::iterator it;

  for (it = this->sistema->productos.begin(); it != this->sistema->productos.end(); ++it) {
    nombreProductos.insert((*it).second->getNombre());
  }

  return nombreProductos;
}

DTOProducto* IProductoController::obtenerInfoProducto(string nombreProd) {
  Producto* producto = this->sistema->productos.at(nombreProd);

  return new DTOProducto(
    producto->getCodigo(), producto->getStock(), producto->getPrecio(),
    producto->getNombre(), producto->getDescripcion(), producto->getCategoria(), producto->getNickVendedor()
    );
}