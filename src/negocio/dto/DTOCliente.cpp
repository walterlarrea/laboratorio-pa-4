//
// Created by Guillermina Rodriguez on 17/6/25.
//
#include "../dto/DTOCliente.h"
#include "../dto/DTOUsuario.h"
#include "../dt/DTFecha.h"
#include "../dt/DTDireccion.h"

DTOCliente::DTOCliente() {}

DTOCliente::DTOCliente(string nickname, string password, DTFecha* fechaNacimiento, DTDireccion* direccion, string ciudadResidencia)
    : DTOUsuario{nickname, password, fechaNacimiento} {
    this->direccion = direccion;
    this->ciudadResidencia = ciudadResidencia;
}

DTOCliente::~DTOCliente() {

}

string DTOCliente::getCiudad() {
    return this->ciudadResidencia;
}

DTDireccion* DTOCliente::getDireccion() {
    return this->direccion;
}

string DTOCliente::toString() const {
    return "Cliente - Nick: " + this->nickName +
           ", Fecha de nacimiento: " + this->fechaNacimiento->toString() +
               ", Ciudad: " + this->ciudadResidencia +
           ", Direccion: " + this->direccion->toString();
}
