#include "Memoria.h"

MemoriaTemporal* MemoriaTemporal::miMemoriaTemporal=nullptr;
map<void*, pair<Memoria*, int>> MemoriaTemporal::sesiones;

MemoriaTemporal::MemoriaTemporal() = default;
MemoriaTemporal::~MemoriaTemporal() = default;


// MemoriaTemporal* MemoriaTemporal::getInstance() {
//   if (miMemoriaTemporal==nullptr){
//     miMemoriaTemporal = new MemoriaTemporal();
//   }
//
//   return miMemoriaTemporal;
// }

Memoria* MemoriaTemporal::darSesion(void* sesion) {
  if (miMemoriaTemporal==nullptr){
    miMemoriaTemporal = new MemoriaTemporal();
  }
  Memoria* memSesion = agregarSesion(sesion);

  return memSesion;
}

Memoria* MemoriaTemporal::agregarSesion(void* sesion) {
  if (sesiones.contains(sesion)) {
    // Al agregar un suscriptor a una sesion existente sumamos 1 a la cantidad
    // Se devuelve la memoria asociada a la sesion existente
    pair<Memoria *, int> memSesion = sesiones.find(sesion)->second;

    memSesion.second++;
    return memSesion.first;
  }
  // Al crear una memoria de sesion nueva la iniciamos con cantidad en 1
  // ya que es el primer y unico suscriptor
  Memoria* nuevaMemoria = new Memoria();
  MemoriaTemporal::sesiones.insert(pair(sesion, pair(nuevaMemoria, 1)));
  return nuevaMemoria;
}

void MemoriaTemporal::terminarSesion(void* sesion) {
  if (sesiones.contains(sesion) && sesiones.find(sesion)->second.second == 1) {
    // Si la cantidad es igual a 1 la sesion
    // no tendra mas suscriptores y la eliminamos junto a su memoria
    delete sesiones.find(sesion)->second.first;
    sesiones.erase(sesion);
  } else {
    // Si la cantidad es mayor a 1 aun hay suscriptores
    // y no eliminamos la memoria pero reducimos la cantidad
    sesiones.find(sesion)->second.second--;
  }
}


// MEMORIA

Memoria::Memoria() = default;
Memoria::~Memoria() = default;

Usuario* Memoria::getUsuario() {
  return this->usuario;
}
Cliente* Memoria::getCliente() {
  return this->cliente;
}
Vendedor* Memoria::getVendedor() {
  return this->vendedor;
}
Producto* Memoria::getProducto() {
  return this->producto;
}
Compra* Memoria::getCompra() {
  return this->compra;
}

void Memoria::setUsuario(Usuario* usuario) {
  this->usuario = usuario;
}
void Memoria::setCliente(Cliente* cliente) {
  this->cliente = cliente;
}
void Memoria::setVendedor(Vendedor* vendedor) {
  this->vendedor = vendedor;
}
void Memoria::setProducto(Producto* producto) {
  this->producto = producto;
}
void Memoria::setCompra(Compra* compra) {
  this->compra = compra;
}