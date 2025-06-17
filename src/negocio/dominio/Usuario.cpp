#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(string nickName, string password, DTFecha *fechaNacimiento) {
    this->nickName = nickName;
    this->password = password;
    this->fechaNacimiento = fechaNacimiento;
}

Usuario::~Usuario() {

}

string Usuario::getNickName() {
    return this->nickName;
}
