
#include "AltaProducto.h"

#include "../negocio/enums/ECatProducto.h"

AltaProducto::AltaProducto() {
  //TODO pendiente de usar una fabrica
  this->iproducto = new IProductoController();
}

AltaProducto::~AltaProducto() {
  //El controlador solo dura lo que dura el caso de uso
  delete this->iproducto;
}

void AltaProducto::altaProducto() {

  string codigo;
  cout << "Ingrese codigo:"<< endl;
  cin >> codigo;

  bool existe = this->iproducto->verificarCodigo(codigo);
  if (!existe) {
    DTOProducto *nuevoProducto = ingresarProducto(codigo);

    this->iproducto->agregarProducto(nuevoProducto);

    cout << "Fin ingreso de producto " << endl;

  } else  {
    cout << "Ya existe el producto. Imposible continuar..." << endl;
  }
}

DTOProducto* AltaProducto::ingresarProducto(string codigo) {
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

  ECatProducto* categoria = new ECatProducto(cat);

  DTOProducto* nuevoProducto = new DTOProducto(
      codigo, stock, precio,
      nombre, descr, categoria
      );

  return nuevoProducto;
}