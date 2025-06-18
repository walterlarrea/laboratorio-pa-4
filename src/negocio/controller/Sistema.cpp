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
  Producto* prod1 = new Producto("124", 20, 139.99, "Bidon 6L Salus", "Agua mineral riquisima", new ECatProducto(2));
  Usuario* usuario1 = new Cliente(
    "walter", "walter",
    new DTFecha(20, 10, 2003),
    new DTDireccion("Calle", 345),
    "Maldonado"
    );
  Cliente* cliente1 = dynamic_cast<Cliente*>(usuario1);
  Comentario* com1c1 = new Comentario("Muy bueno", new DTFecha(10, 06, 2025), cliente1, prod1);
  cliente1->agregarComentario(com1c1);

  this->usuarios.insert(pair(cliente1->getNickName(), cliente1));

  cout << "Fin inicializacion Sistema " << endl;
}