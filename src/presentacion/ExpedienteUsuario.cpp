#include "ExpedienteUsuario.h"
#include "../negocio/controller/usuario/IUsuarioController.h"
#include <iomanip>
#include <format>

ExpedienteUsuario::ExpedienteUsuario() {
  void* sesion = &sesion;
  this->iusuario = new IUsuarioController();
}

ExpedienteUsuario::~ExpedienteUsuario() {
  delete this->iusuario;
}

void ExpedienteUsuario::expedienteUsuario() {

  string usuarioSeleccionado = ingresarUsuario();
  if (!usuarioSeleccionado.empty()) {

    DTOUsuario* u = this->iusuario->obtenerExpedienteUsuario(usuarioSeleccionado);
    cout << u->toString() << endl;
    if (DTOCliente* c = dynamic_cast<DTOCliente*>(u)) {

      listarExpedienteCliente(c);

    } else if (DTOVendedor* v = dynamic_cast<DTOVendedor*>(u)) {

      listarExpedienteVendedor(v);

    }

  } else {
    cout << "Nombre de usuario incorrecto, imposible continuar." << endl << endl;
  }

}

string ExpedienteUsuario::ingresarUsuario() {
  set<string> nickUsuarios = this->iusuario->getUsuariosNick();

  if (nickUsuarios.empty()) {
    cout << "No existen usuarios registrados en el sistema." << endl << endl;
    return "";
  }

  cout << "Estos son todos los usuarios registrados en el sistema:" << endl << endl;
  for (const string& u : nickUsuarios) {
    cout << "- " << u << std::endl;
  }

  string usuarioSeleccionado;

  cout << "Ingrese el nombre del usuario: " << endl;
  cin >> usuarioSeleccionado;

  if (nickUsuarios.contains(usuarioSeleccionado)) {
    return usuarioSeleccionado;
  }
  return "";
}

void ExpedienteUsuario::listarExpedienteCliente(DTOCliente* c) {
  for (const auto& compra : c->getCompras()) {

    // Datos básicos
    cout << "Detalles de la compra (Codigo: " << compra->getCodigo() << ")" << endl;
    cout << "Fecha: " << compra->getFecha()->toString() << endl;

    cout << setfill('_') << setw(100) << "_" << endl;

    // Encabezado
    cout << setfill(' ') << left;
    cout << setw(3)  << "#" << "|"
         << setw(10) << "Código" << "|"
         << setw(25) << "Producto" << "|"
         << setw(6)  << "Cant." << "|"
         << setw(12) << "Precio u." << "|"
         << setw(12) << "Precio t." << "|"
         << setw(10) << "Enviado" << "|" << endl;

    cout << setfill('_') << setw(100) << "_" << endl;

    int numLinea = 1;
    float precioTotal = 0.0;

    for (auto& producto : compra->getCompraProds()) {
      string nombre = producto->getProducto()->getNombre();
      string codigo = producto->getProducto()->getCodigo();
      int cantidad = producto->getCantidad();
      float precioUnitario = producto->getProducto()->getPrecio();
      float precioLinea = cantidad * precioUnitario;
      string enviado = producto->getEnviado() ? "Sí" : "No";
      precioTotal += precioLinea;

      cout << setfill(' ') << left;
      cout << setw(3)  << numLinea << "|"
           << setw(10) << codigo << "|"
           << setw(25) << nombre << "|"
           << right << setw(6) << cantidad << "|";

      cout << setw(11) << right << "$" + to_string(precioUnitario).substr(0, to_string(precioUnitario).find(".") + 3) << "|";
      cout << setw(11) << right << "$" + to_string(precioLinea).substr(0, to_string(precioLinea).find(".") + 3) << "|";
      cout << setw(10) << right << enviado << "|" << endl;

      cout << setfill('-') << setw(100) << "-" << endl;
      numLinea++;
    }

    // Total
    cout << setfill(' ') << left;
    cout << setw(12) << "   TOTAL -";
    cout << right << setw(77) << "$" << fixed << setprecision(2) << precioTotal << "|" << endl;

    cout << setfill('_') << setw(100) << "_" << endl;
  }
}

void ExpedienteUsuario::listarExpedienteVendedor(DTOVendedor* v) {
  cout << "Productos en venta: " << endl;

  for (DTOProducto* prod : v->getProductos()) {
    cout << prod->toString() << endl;
  }

  cout << endl << "Promociones vigentes: " << endl;

  for (DTOPromocion* promo : v->getPromociones()) {
    cout << endl << promo->toString() << endl;

    cout << "Productos: " << endl;

    for (DTOProdPromo* prodPromo : promo->getProdPromos()) {
      cout << prodPromo->toString() << endl;
    }
  }
}