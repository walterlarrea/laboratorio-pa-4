
#include "ListarCategoriasProd.h"
#include "../negocio/controller/producto/IProducto.h"
#include "../negocio/enums/ECatProducto.h"

#include<iostream>

using namespace std;

ListarCategoriasProd::ListarCategoriasProd() = default;


void ListarCategoriasProd::listarCategoriasProd() {
  cout << "--- Listar Categorias de Productos ---" << endl << endl;

  map<int, string>* categorias = ECatProducto::getCategorias();

  cout << "Todas las categorias de productos:" << endl;

  map<int, string>::iterator it;
  for (it = categorias->begin(); it != categorias->end(); ++it) {
    cout << it->first << " - " << it->second << endl;
  }
}


ListarCategoriasProd::~ListarCategoriasProd() = default;