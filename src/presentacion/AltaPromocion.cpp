
#include "AltaPromocion.h"

#include <algorithm>

#include "../negocio/controller/producto/IProductoController.h"
#include "../negocio/controller/promocion/IPromocionController.h"
#include "../negocio/controller/usuario/IUsuarioController.h"

AltaPromocion::AltaPromocion() {
  void* sesion = &sesion;
  this->ipromocion = new IPromocionController(sesion);
  this->iusuario = new IUsuarioController(sesion);
  this->iproducto = new IProductoController(sesion);
 }


AltaPromocion::~AltaPromocion() {
  delete this->ipromocion;
  delete this->iusuario;
  delete this->iproducto;
}

void AltaPromocion::altaPromocion() {
  cout << "--- Crear de Promocion ---" << endl << endl;

  DTOPromocion* promocion = ingresarPromocion();

  ingresarVendedor(promocion);

  map<string, DTOProducto*> productos = this->iusuario->getProdVigentesVendedor(promocion->getVendedor());

  if (productos.empty()) {
    cout << "No hay productos disponibles del vendedor." << endl << endl;
  } else {

    ingresarProdPromos(promocion, productos);

    cout << "Promocion creada ";
    this->ipromocion->altaPromocion(promocion);
  }


}


DTOPromocion* AltaPromocion::ingresarPromocion() {

  string nombre;
  string descr;
  double desc;
  int dia, mes, anio;

  cout << "Ingresar nombre: ";
  cin.ignore();
  getline(cin, nombre);
  cout << "Ingresar descripcion: ";
  getline(cin, descr);
  cout << "Ingresar % de descuento para los productos en la promocion: ";
  cin >> desc;
  cout << "Ingresar fecha de vencimiento (dia mes anio): ";
  cin >> dia >> mes >> anio;
  DTFecha* fechaVenc = new DTFecha(dia, mes, anio);

  return new DTOPromocion(nombre, descr, desc, fechaVenc);
}

void AltaPromocion::ingresarVendedor(DTOPromocion* promocion) {

  set<string> nombreVendedores = this->iusuario->getVendedoresNick();
  cout << endl <<"Lista de vendedores: " << endl;

  for (string nombre : nombreVendedores) {
    cout << nombre << endl;
  }

  string vendedorSeleccionado;

  while (!nombreVendedores.contains(vendedorSeleccionado)) {
    cout << "Escriba el nombre del vendedor deseado: ";
    cin >> vendedorSeleccionado;

    if (!nombreVendedores.contains(vendedorSeleccionado)) {
      cout << "Nombre erroneo, intente nuevamente" << endl;
    }
  }

  promocion->setVendedor(vendedorSeleccionado);
}

void AltaPromocion::ingresarProdPromos(DTOPromocion* promocion, map<string, DTOProducto*> productos) {

  string prodSeleccionado;
  int aux;
  int cant;
  bool salir = false;

  do {

    cout << "Productos disponibles del vendedor " << promocion->getVendedor() << " : " << endl << endl;

    for (const auto producto : productos) {
      cout << producto.second->getCodigo() << " - " << producto.second->getNombre() << endl;
    }

    cout << endl << "Ingrese el codigo del producto para agregar a la promocion: " << endl;
    cin >> prodSeleccionado;

    if (!productos.contains(prodSeleccionado)){
      cout<< "Codigo invalido, intente nuevamente" << endl ;
    } else {
      cout << endl << "Ingrese la cantidad minima necesaria para que se aplique el descuento: " << endl;
      cin >> cant;

      promocion->addProdPromo( new DTOProdPromo(productos.find(prodSeleccionado)->second, cant) );

      productos.erase(prodSeleccionado);

      if (!productos.empty()) {
        cout << "¿Desea agregar más productos?" << endl;
        cout << "Digite 0 para NO" << endl;
        cout << "Digite 1 para SI" << endl;
        cin >> aux;

        if (aux == 0) {
          salir = true;
        }
      } else {
        cout << "No hay más productos disponibles"<< endl;
        salir = true;
      }
    }
  } while ( !salir && !productos.empty());

}