#include "ConsultarPromocion.h"
#include "../negocio/controller/promocion/IPromocionController.h"
#include <limits>


ConsultarPromocion::ConsultarPromocion() {
  void* sesion = &sesion;
  this->ipromocion = new IPromocionController(sesion);
}

ConsultarPromocion::~ConsultarPromocion() {
  delete this->ipromocion;
}

void ConsultarPromocion::consultarPromocion() {
  cout << "--- Consultar Promocion ---" << endl << endl;

  map<string, DTOPromocion*> promociones = this->ipromocion->getPromocionesVigentes();

  if (!promociones.empty()) {
    bool salir = false;

    string promoSeleccionada;

    cin.ignore();
    do {

      listarPromociones(promociones);

      cout << "Ingrese el nombre de la promocion:" << endl;
      cout << "[Salir = 0]" << endl;

      getline(cin, promoSeleccionada);

      if (promoSeleccionada == "0") {
        salir = true;
      } else if (promociones.contains(promoSeleccionada)) {

        listarPromoSeleccionada(promociones.find(promoSeleccionada)->second);

      } else {
        cout << "Nombre de promo incorrecto, intente de nuevo" << endl;
      }
    } while (salir == false);

  } else {
    cout << "No hay promociones vigentes" << endl;
  }

}

void ConsultarPromocion::listarPromociones(map<string, DTOPromocion*> promociones) {

  cout << endl << "Promociones vigentes: " << endl;

  for (auto& par : promociones) {

    cout << par.second->toString() << endl;
  }

}

void ConsultarPromocion::listarPromoSeleccionada(DTOPromocion* promo) {
  cout << endl << "- Datos de la promocion -" << endl;

  cout << promo->toString() << endl << endl;
  cout << "Vendedor: " << promo->getVendedor() << endl << endl;

  cout << "- Productos de la promo -" << endl;

  for (DTOProdPromo* prodPromo : this->ipromocion->getPromoInfo(promo->getNombre())) {
    cout << prodPromo->toString() << endl;
  }

}