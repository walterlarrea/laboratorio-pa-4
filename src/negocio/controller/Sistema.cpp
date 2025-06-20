#include "Sistema.h"

#include <iostream>

Sistema* Sistema::miSistema=nullptr;

Sistema::Sistema() = default;

Sistema::~Sistema() = default;

Sistema* Sistema::getInstance() {
  if (miSistema==nullptr){
    // Se inicia una instancia de memoria para el sistema
    miSistema = new Sistema();
    miSistema->inicializarDatos();
  }

  return miSistema;
}

void Sistema::inicializarDatos() {
  //inicializo el sistema
  cout << "Comienza inicializacion Sistema " << endl;

  // Crear instancias y agregarlas a listas globales

  Cliente* cliente1 = new Cliente(
    "walter", "walter",
    new DTFecha(20, 10, 2003),
    new DTDireccion("Calle", 345),
    "Maldonado"
    );

  Vendedor* vendedor1 = new Vendedor("Maicol", "Maicol",
    new DTFecha(28, 11, 2004),
    "123456789012");

  Vendedor* vendedor2 = new Vendedor("Kevin", "NegroKevin",
    new DTFecha(24, 7, 2005),
    "123456789012");

  Producto* prod1 = new Producto("1", 20, 139.99,
    "Bidon 6L Salus", "Agua mineral riquisima",
    new ECatProducto(2));
  prod1->setVendedor(vendedor1);

  Producto* prod2 = new Producto("2", 50, 50.5,
    "Alfajor triple", "Buen alfajor",
    new ECatProducto(2));
  prod2->setVendedor(vendedor1);

  Producto* prod3 = new Producto("3", 5, 13000.0,
  "Lavarropas James", "Buena velocidad de lavado",
  new ECatProducto(1));
  prod3->setVendedor(vendedor2);

  Producto* prod4 = new Producto("4", 10, 5200.0,
  "Microondas chico", "Gran calidad y precio",
  new ECatProducto(1));
  prod4->setVendedor(vendedor2);

  Comentario* com1c1 = new Comentario("Muy bueno", new DTFecha(10, 06, 2025), cliente1, prod1);
  cliente1->agregarComentario(com1c1);

  this->usuarios.insert(pair(cliente1->getNickName(), cliente1));
  this->usuarios.insert(pair(vendedor1->getNickName(), vendedor1));
  this->usuarios.insert(pair(vendedor2->getNickName(), vendedor2));
  this->productos.insert(pair(prod1->getCodigo(), prod1));
  this->productos.insert(pair(prod2->getCodigo(), prod2));
  this->productos.insert(pair(prod3->getCodigo(), prod3));
  this->productos.insert(pair(prod4->getCodigo(), prod4));

  cout << "Fin inicializacion Sistema " << endl;
}