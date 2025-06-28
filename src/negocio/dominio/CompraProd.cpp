
#include "CompraProd.h"

CompraProd::CompraProd() = default;
CompraProd::CompraProd(Compra* compra, Producto* producto, int cantidad) {
  this->producto = producto;
  this->cantidad = cantidad;
  this->compra = compra;
  this->enviado = false;
  producto->disminuirStock(cantidad);
}
CompraProd::CompraProd(Compra* compra, Producto* producto, int cantidad, bool enviado) {
  this->producto = producto;
  this->cantidad = cantidad;
  this->compra = compra;
  this->enviado = enviado;
  producto->disminuirStock(cantidad);
}
CompraProd::~CompraProd() = default;

Producto* CompraProd::getProducto() {
  return producto;
}
int CompraProd::getCantidad() {
  return cantidad;
}
bool CompraProd::getEnviado() {
  return enviado;
}
double CompraProd::getMonto() {
  double monto = 0.0;
  if (this->producto != nullptr) {
    monto += this->producto->getPrecio() * this->cantidad;
  }
  return monto;
}
Compra* CompraProd::getCompra() {
  return compra;
}
void CompraProd::setProducto(Producto* producto) {
  this->producto = producto;
}
void CompraProd::setCantidad(int cantidad) {
  this->cantidad = cantidad;
}
void CompraProd::setEnviado(bool enviado) {
  this->enviado = enviado;
}
void CompraProd::setCompra(Compra* compra) {
  this->compra = compra;
}

void CompraProd::marcarProductoEnviado() {
  this->enviado = true;
}

bool CompraProd::codigoProductoEsIgualA(string codProd) {
  return this->producto->getCodigo() == codProd;
}

bool CompraProd::envioPendienteYEsDeVendedor(string nickVend) {
  bool enviado = this->enviado;
  bool esDeVendedor = this->producto->vendedorIgualA(nickVend);

  return !enviado && esDeVendedor;
}

bool CompraProd::envioPendienteYEsProducto(string codProd) {
  bool enviado = this->enviado;
  bool esProducto = this->producto->getCodigo() == codProd;

  return !enviado && esProducto;
}
