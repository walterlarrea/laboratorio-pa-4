
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "../dt/DTFecha.h"

using namespace std;

class Usuario {

private:
    string nickName;
    string password;
    DTFecha *fechaNacimiento;
public:
    Usuario();
    Usuario(string nickName, string password, DTFecha* fechaNacimiento);

    string getNickName();

    virtual ~Usuario();
};



#endif //USUARIO_H
