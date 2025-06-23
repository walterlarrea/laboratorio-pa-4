
#include "AltaProducto.h"

#include <iostream>
#include "../negocio//controller/producto/IProductoController.h"
#include "../negocio/enums/ECatProducto.h"

#include "../negocio/controller/usuario/IUsuarioController.h"

using namespace std;

AltaProducto::AltaProducto() {
  void* sesion = &sesion;
  this->iproducto = new IProductoController(sesion);
  this->iusuario = new IUsuarioController(sesion);
}

AltaProducto::~AltaProducto() {
  //El controlador solo dura lo que dura el caso de uso
  delete this->iproducto;
  delete this->iusuario;
}

void AltaProducto::altaProducto() {

  DTOVendedor* vendedor = ingresarVendedor();

  if (vendedor != nullptr) {
    string codigo;
    cout << "Ingrese codigo:"<< endl;
    cin >> codigo;

    bool existe = this->iproducto->verificarCodigo(codigo);
    if (!existe) {
      DTOProducto *nuevoProducto = ingresarProducto(codigo, vendedor);

      this->iproducto->agregarProducto(nuevoProducto);

      cout << "Fin ingreso de producto " << endl;

    } else  {
      cout << "Ya existe el producto. Imposible continuar..." << endl;
    }
  }

}

DTOVendedor* AltaProducto::ingresarVendedor() {
  set<string> nombreVendedores = this->iusuario->getVendedoresNick();

  DTOVendedor* vendedor;
  string nickVendedor = "";

  if (!nombreVendedores.empty()) {
    cout << "Lista de vendedores " << endl;

    for (const string& nom : nombreVendedores) {
      cout << nom << endl;
    }

    while (!nombreVendedores.contains(nickVendedor)) {
      cout << "Escriba el nombre del vendedor deseado: ";
      cin >> nickVendedor;

      if (!nombreVendedores.contains(nickVendedor)) {
        cout << "Nombre erroneo, intente nuevamente" << endl;
      }
    }

    vendedor = this->iusuario->getVendedor(nickVendedor);

  } else {
    cout << "No hay vendedores en el sistema." << endl;
  }

  return vendedor;
}

DTOProducto* AltaProducto::ingresarProducto(string codigo, DTOVendedor* vendedor) {
  int stock;
  double precio;
  string nombre;
  string descr;
  int cat;

  cout << "Ingresar nombre:" << endl;
  cin >> nombre;
  cout << "Ingresar descripcion:" << endl;
  cin.ignore();
  getline(cin, descr);
  cout << "Ingresar stock:" << endl;
  cin >> stock;
  cout << "Ingresar precio:" << endl;
  cin >> precio;

  map<int, string>* categorias = ECatProducto::getCategorias();
  do {
    cout << "Ingresar numero de categoria:" << endl;

    map<int, string>::iterator it;
    for (it = categorias->begin(); it != categorias->end(); ++it) {
      cout << it->first << " - " << it->second << endl;
    }

    cout << endl << "Categoria:" << endl;
    cin >> cat;

    if (!ECatProducto::verificarCategoria(cat)) {
      cout << "La categoria seleccionada no existe. Seleccione una diferente" << endl;
    }
  } while (!ECatProducto::verificarCategoria(cat));

  // TODO: Dar posibilidad de cancelar el proceso de alta?

  DTOProducto* nuevoProducto = new DTOProducto(
      codigo, stock, precio,
      nombre, descr, new ECatProducto(cat), vendedor);

  return nuevoProducto;
}

