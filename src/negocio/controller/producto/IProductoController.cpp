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

    string nickVendedor = producto->getVendedor()->getNickName();
    Usuario* u = this->sistema->usuarios.find(nickVendedor)->second;
    Vendedor* v = dynamic_cast<Vendedor*>(u);

    nuevoProducto->setVendedor(v);
    v->addProducto(nuevoProducto);

    // this->sistema->productos[producto->getNombre()] = nuevoProducto;
    this->sistema->productos.insert(make_pair(producto->getCodigo(), nuevoProducto));
  }
}

set<DTOProducto*> IProductoController::obtenerProductos() {
  set<DTOProducto*> retorno;
  map<string, Producto*> listaProductos = this->sistema->productos;

  for (pair<string, Producto*> par : listaProductos) {
    retorno.insert(crearDTOProducto(par.second));
  }

  return retorno;
}

DTOProducto* IProductoController::obtenerInfoProducto(string nombreProd) {
  Producto* producto = this->sistema->productos.at(nombreProd);

  return crearDTOProducto(producto);
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


DTOProducto* IProductoController::crearDTOProducto(Producto* producto) {

  Vendedor* v = producto->getVendedor();

  DTOVendedor* vendedor = new DTOVendedor(v->getNickName(), v->getPassword(), v->getFechaNacimiento(), v->getRut());

  return new DTOProducto(
    producto->getCodigo(), producto->getStock(), producto->getPrecio(),
    producto->getNombre(), producto->getDescripcion(), producto->getCategoria(), vendedor );
}



