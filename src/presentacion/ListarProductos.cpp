
#include "ListarProductos.h"
#include "../negocio/controller/producto/IProductoController.h"

ListarProductos::ListarProductos() {
  this->iproducto = new IProductoController();
};

ListarProductos::~ListarProductos() {
  delete this->iproducto;
}

void ListarProductos::listarProductos() {
  set<DTOProducto*> productos = this->iproducto->obtenerProductos();

  if (productos.size() > 0) {
  cout << "Estos son todos los productos en el sistema:" << endl << endl;

  set<DTOProducto*>::iterator it;
  for (it = productos.begin(); it != productos.end(); ++it) {
    Producto* producto = new Producto(
      (*it)->getCodigo(), (*it)->getStock(), (*it)->getPrecio(),
      (*it)->getNombre(), (*it)->getDescripcion(), (*it)->getCategoria()
    );
    cout << producto->toString() << endl;
    delete producto;
  }
  } else {
    cout << "No existen productos en el sistema." << endl << endl;
  }
}
