#include "DTFecha.h"

DTFecha::DTFecha() {

}

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

DTFecha::~DTFecha() {

}
std::string DTFecha::toString() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}
