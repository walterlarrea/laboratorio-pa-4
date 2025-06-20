
#include "AltaPromocion.h"

#include "../negocio/controller/promocion/IPromocionController.h"
#include "../negocio/controller/usuario/IUsuarioController.h"

AltaPromocion::AltaPromocion() {
  void* sesion = &sesion;
  this->ipromocion = new IPromocionController(sesion);
  this->iusuario = new IUsuarioController(sesion);
 }


AltaPromocion::~AltaPromocion() {
  delete this->ipromocion;
  delete this->iusuario;
}

void AltaPromocion::altaPromocion() {
  set<string> nombreVendedores = this->iusuario->getClientesNick();

  cout << "--- Alta de Promocion ---" << endl;
  cout << "Lista de vendedores:";

  for (string nombre : nombreVendedores) {
    cout << nombre << endl;
  }

  string vendedorSeleccionado;
  cout << endl << "Ingrese el nombre del vendedor: ";
  cin >> vendedorSeleccionado;

}
