#include "DTDireccion.h"

DTDireccion::DTDireccion() {

}

DTDireccion::DTDireccion(string calle, int puerta) {
    this->calle = calle;
    this->puerta = puerta;
}

DTDireccion::~DTDireccion() {

}

string DTDireccion::toString() {
        return calle + " " + std::to_string(puerta);
}

