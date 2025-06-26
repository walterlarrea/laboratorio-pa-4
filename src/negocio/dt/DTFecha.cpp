#include "DTFecha.h"
#include <ctime>

using namespace std;

DTFecha::DTFecha() {}

DTFecha::DTFecha(int dia, int mes, int anio) {
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

DTFecha::~DTFecha() {}

string DTFecha::toString() {
  return "" + to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}

DTFecha* obtenerFechaActual() {
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  return new DTFecha(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
};


bool DTFecha::esVigente() {
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  DTFecha* fechaActual = obtenerFechaActual();
  if (this->anio > fechaActual->anio) return true;
  if (this->anio < fechaActual->anio) return false;
  if (this->mes > fechaActual->mes) return true;
  if (this->mes < fechaActual->mes) return false;
  return this->dia > fechaActual->dia;
}