
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
  cout << "--- Alta de Promocion ---" << endl;

  string nombre;
  string descr;
  double desc;
  int dia, mes, anio;

  cout << "Ingresar nombre:" << endl;
  cin.ignore();
  getline(cin, nombre);
  cout << "Ingresar descripcion:" << endl;
  cin.ignore();
  getline(cin, descr);
  cout << "Ingresar descuento:" << endl;
  cin >> desc;
  cout << "Ingresar fecha de vencimiento:" << endl;
  cin >> dia >> mes >> anio;
  DTFecha* fechaVenc = new DTFecha(dia, mes, anio);

  set<string> nombreVendedores = this->iusuario->getVendedoresNick();
  cout << endl <<"Lista de vendedores: " << endl;

  for (string nombre : nombreVendedores) {
    cout << nombre << endl;
  }

  string vendedorSeleccionado;
  cout << endl << "Ingrese el nombre del vendedor: ";
  cin >> vendedorSeleccionado;

  map<string, DTOProducto*> productos = this->iusuario->getProdVendedor(vendedorSeleccionado);

  // Buscando existencias vigentes del prod en otra promo
  for (const auto producto : productos) {
    if (this->ipromocion->buscarExistencia(producto.second->getCodigo())) {
      cout << "El producto " << producto.second->getCodigo() << " ya está siendo utilizado en otra promo"<< endl;
      productos.erase(producto.first);
    }
  }

  if (productos.empty()) {
    cout << "No hay productos disponibles del vendedor." << endl << endl;
    return ;
  }

  DTOPromocion* promocion = new DTOPromocion(nombre, descr, desc, fechaVenc);
  string prodSeleccionado;
  int aux;
  int cant;
  bool salir = false;

  while ( !salir && !productos.empty()) {

    cout << "Productos disponibles del vendedor " << vendedorSeleccionado << " : " << endl << endl;

    for (const auto producto : productos) {
      cout << producto.second->getCodigo() << " - " << producto.second->getNombre() << endl;
    }

    cout << endl << "Ingrese el codigo del producto: ";
    cin >> prodSeleccionado;

    if (!productos.contains(prodSeleccionado)){
      cout<< "Codigo invalido, intente nuevamente" << endl ;
    } else {
      cout << endl << "Ingrese la cantidad: ";
      cin >> cant;

      promocion->addProdPromo( new DTOProdPromo(prodSeleccionado, cant) );

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
  }
  cout << "Promocion creada ";
  this->ipromocion->altaPromocion(promocion);
}
