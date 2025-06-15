#include "Sistema.h"


Sistema* Sistema::miSistema=nullptr;

Sistema::Sistema() {}

Sistema::~Sistema() {
  // TODO Auto-generated destructor stub
}

Sistema* Sistema::getInstance() {
  if (Sistema::miSistema==nullptr){
    Sistema::miSistema = new Sistema();
    Sistema::miSistema->inicializarDatos();
  }
  return Sistema::miSistema;

}

void Sistema::inicializarDatos() {
  //inicializo el sistema


  // cout << "Comienza inicializacion Sistema " << endl;

  // Crear instancias y agregarlas a listas globales

  // cout << "Fin inicializacion Sistema " << endl;
}