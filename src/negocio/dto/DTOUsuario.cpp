//
// Created by Guillermina Rodriguez on 17/6/25.
//
#include <iostream>

#include "../dt/DTFecha.h"
#include "DTOUsuario.h"

using namespace std;

DTOUsuario::DTOUsuario() {}

DTOUsuario::DTOUsuario(string nickName, string pass, DTFecha *fechaNacimiento) {
    this->nickName = nickName;
    this->password = pass;
    this->fechaNacimiento = fechaNacimiento;
}

DTOUsuario::~DTOUsuario() {

}
string DTOUsuario::getNickName() {
    return this->nickName;
}
string DTOUsuario::getPassword() {
    return this->password;
}
DTFecha *DTOUsuario::getFechaNacimiento() {
    return this->fechaNacimiento;
}

