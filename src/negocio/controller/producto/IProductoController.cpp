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
    producto->getNombre(), producto->getDescripcion(), producto->getCategoria()
    );
}

set<DTOComentario*> IProductoController::getComentariosProducto(string nombreProd) {
  set<DTOComentario*> resultado;
  Producto* producto = this->sistema->productos[nombreProd];

  for (auto& par : producto->getComentarios()) {
    Comentario* c = par.second;
    set<DTOComentario*> dtoRespuestas;

    for (Comentario* r : c->getRespuestas()) {
      dtoRespuestas.insert(new DTOComentario(
        r->getTexto(), r->getFecha(),
        r->getCliente()->getNickName(), nombreProd, {}
      ));
    }

    resultado.insert(new DTOComentario(
      c->getTexto(), c->getFecha(),
      c->getCliente()->getNickName(), nombreProd, dtoRespuestas
    ));
  }

  return resultado;
}

void IProductoController::agregarComentario(string nombreProd, DTOComentario* dtoComentario, string textoPadre) {
  Producto* prod = this->sistema->productos[nombreProd];
  Cliente* cliente = dynamic_cast<Cliente*>(this->sistema->usuarios[dtoComentario->getCliente()]);

  Comentario* comentario = new Comentario(dtoComentario->getTexto(), dtoComentario->getFecha(), cliente, prod);

  if (textoPadre.empty()) {
    prod->agregarComentario(comentario);
    cliente->agregarComentario(comentario);
  } else {
    auto& comentarios = prod->getComentarios();
    auto it = comentarios.find(textoPadre);
    if (it != comentarios.end()) {
      it->second->agregarRespuesta(comentario);
      cliente->agregarComentario(comentario);
    } else {
      delete comentario;
    }
  }
}




