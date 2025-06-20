
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

  string vendedor = ingresarVendedor();

  if (!vendedor.empty()) {
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
  } else {
    cout << "No hay vendedores en el sistema." << endl;
  }

}

string AltaProducto::ingresarVendedor() {
  set<string> nombreVendedores = this->iusuario->getVendedoresNick();

  string retorno = "";

  if (nombreVendedores.empty()) {
    return retorno; // Se termina si no hay vendedores
  }

  cout << "Lista de vendedores:" << endl;
  for (string nombre : nombreVendedores) {
    cout << nombre << endl;
  }

  while (retorno == "") {
    cout << "Ingrese el nombre de vendedor: ";
    cin >> retorno;
    if (!nombreVendedores.contains(retorno)) {
      cout << "Nombre incorrecto"<< endl;
      retorno = "";
    }
  }

  return retorno;
}

DTOProducto* AltaProducto::ingresarProducto(string codigo, string vendedor) {
  int stock;
  double precio;
  string nombre;
  string descr;
  int cat;

  cout << "Ingresar nombre:" << endl;
  cin >> nombre;
  cout << "Ingresar descripcion:" << endl;
  cin >> descr;
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
      nombre, descr, new ECatProducto(cat),
      vendedor
      );

  return nuevoProducto;
}

