
#include "ListarCategoriasProd.h"


ListarCategoriasProd::ListarCategoriasProd() = default;


void ListarCategoriasProd::listarCategoriasProd() {
  map<int, string>* categorias = ECatProducto::getCategorias();

  cout << "Todas las categorias de productos:" << endl;

  map<int, string>::iterator it;
  for (it = categorias->begin(); it != categorias->end(); ++it) {
    cout << it->first << " - " << it->second << endl;
  }
}


ListarCategoriasProd::~ListarCategoriasProd() = default;