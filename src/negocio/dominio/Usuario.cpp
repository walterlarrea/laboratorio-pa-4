#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(string nickName, string pass, DTFecha *fechaNacimiento) {
    this->nickName = nickName;
    this->password = pass;
    this->fechaNacimiento = fechaNacimiento;
}

Usuario::~Usuario() {

}
string Usuario::getNickName() const {
    return this->nickName;
}
string Usuario::getPassword() const{
    return this->password;
}
DTFecha *Usuario::getFechaNacimiento() const {
    return this->fechaNacimiento;
}