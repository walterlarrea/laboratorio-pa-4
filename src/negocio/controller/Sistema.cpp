#include "Sistema.h"

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
  // cout << "Comienza inicializacion Sistema " << endl;

  // Crear instancias y agregarlas a listas globales

  // cout << "Fin inicializacion Sistema " << endl;
}