//
// Created by Walter on 27/06/2025.
//

#include "EnviarProducto.h"

#include "../negocio/controller/compra/ICompraController.h"
#include "../negocio/controller/usuario/IUsuarioController.h"
#include "../negocio/dto/DTOCompraCliente.h"

EnviarProducto::EnviarProducto() {
  void* sesion = &sesion;
  this->iusuario = new IUsuarioController(sesion);
  this->icompra = new ICompraController(sesion);
}

 EnviarProducto::~EnviarProducto() {
   delete this->iusuario;
 }

void EnviarProducto::enviarProducto() {
  DTOVendedor* vendedorSel = ingresarVendedor();

  if (vendedorSel == nullptr) {
    cout << endl << "El vendedor seleccionado no existe." << endl;
    return;
  }

  map<string, DTOProducto*> prodsEnvPendiente = icompra->productosConEnvioPendiente(vendedorSel->getNickName());

  if (prodsEnvPendiente.empty()) {
    cout << endl << "El vendedor seleccionado no tiene productos con envio pendiente." << endl;
    return;
  }
  DTOProducto* prodSeleccionado = seleccionarProducto(prodsEnvPendiente);
  if (prodSeleccionado == nullptr) {
    cout << endl << "El producto seleccionado no existe." << endl;
    return;
  }

  set<DTOCompraCliente*> comprasClientes = this->icompra->comprasPendientesProducto(prodSeleccionado->getCodigo());

  if (comprasClientes.empty()) {
    cout << endl << "El producto seleccionado no tiene compras con envio pendiente." << endl;
    return;
  }
  DTOCompraCliente* compraCliente = seleccionarCompraCliente(comprasClientes);
  if (compraCliente == nullptr) {
    cout << endl << "Hubo un problema al marcar el producto como enviado." << endl;
    return;
  }

  this->icompra->enviarProductoCompra(compraCliente);
  cout << endl << "Producto enviado correctamente." << endl;
}

DTOVendedor* EnviarProducto::ingresarVendedor() {
  set<string> nombreVendedores = this->iusuario->getVendedoresNick();

  DTOVendedor* vendedor = nullptr;
  string nickVendedor = "";

  if (!nombreVendedores.empty()) {
   cout << endl << "Lista de vendedores en el sistema:" << endl << endl;

   for (const string& nom : nombreVendedores) {
     cout << nom << endl;
   }

   while (!nombreVendedores.contains(nickVendedor)) {
     cout << endl << "Escriba el nombre del vendedor deseado: ";
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

DTOProducto* EnviarProducto::seleccionarProducto(map<string, DTOProducto*> productos) {
  if (!productos.empty()) {
    cout << endl << "Estos son los productos del vendedor seleccionado y que tienen algun envio pendiente:" << endl << endl;

    for (auto producto: productos) {
      cout << producto.second->getCodigo() << " - " << producto.second->getNombre() << endl;
    }

    string codigoProdSel;
    cout << endl << "Ingrese el codigo del producto a enviar: ";
    cin >> codigoProdSel;

    return productos[codigoProdSel];
  }

  return nullptr;
}

DTOCompraCliente* EnviarProducto::seleccionarCompraCliente(set<DTOCompraCliente*> compraClientes) {
  if (!compraClientes.empty()) {
    cout << endl << "Estas son las compras del producto seleccionado pendiente de ser enviado:" << endl << endl;

    map<int, DTOCompraCliente *> mapCompraCliente;
    int numOpcion = 0;
    for (auto compraCliente: compraClientes) {
      numOpcion++;
      cout << numOpcion << " - " << compraCliente->toString() << endl;
      mapCompraCliente.insert(pair(numOpcion, compraCliente));
    }

    int numOpcionSelec;
    cout << endl << "Ingrese el num# deseado: ";
    cin >> numOpcionSelec;

    if (!mapCompraCliente.contains(numOpcionSelec)) {
      cout << endl << "El codigo de compra seleccionado no existe." << endl;
    }

    return mapCompraCliente[numOpcionSelec];
  }

  return nullptr;
}
