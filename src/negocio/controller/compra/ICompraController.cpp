
#include "ICompraController.h"

ICompraController::ICompraController() {
  this->sistema = Sistema::getInstance();
}

ICompraController::ICompraController(void* idSesion) {
  this->sistema = Sistema::getInstance();
  if (idSesion != nullptr) {
    this->memoria = MemoriaTemporal::darSesion(idSesion);
  }
}
ICompraController::~ICompraController() {
  if (this->memoria != nullptr) {
    MemoriaTemporal::terminarSesion(this->memoria);
  }
}

void ICompraController::altaCompra(set<DTOProdCantidad*> prodsCantidad) {
  // FIXME: Posible repeticion de codigo. Y es un asco jaja
  time_t hoy = time(0);
  struct tm* infoFecha = localtime(&hoy);
  char charFechaDia[10];
  strftime(charFechaDia, sizeof(charFechaDia), "%d", infoFecha);
  string dia(charFechaDia);
  char charFechaMes[10];
  strftime(charFechaMes, sizeof(charFechaMes), "%m", infoFecha);
  string mes(charFechaMes);
  char charFechaAnio[10];
  strftime(charFechaAnio, sizeof(charFechaAnio), "%Y", infoFecha);
  string anio(charFechaAnio);

  DTFecha* dfecha = new DTFecha(stoi(dia), stoi(mes), stoi(anio));

  Cliente* clienteEnMemoria = this->memoria->getCliente();
  if (clienteEnMemoria == nullptr)
    return;

  Compra* compra = new Compra(clienteEnMemoria, to_string(this->sistema->compras.size()), dfecha);

  for (auto& prodCant : prodsCantidad) {
    Producto* prod = this->sistema->productos.find(prodCant->getProducto()->getCodigo())->second;
    compra->agregarLineaProducto(prod, prodCant->getCantidad());
  }

  this->sistema->compras.insert(pair(compra->getCodigo(), compra));
}


