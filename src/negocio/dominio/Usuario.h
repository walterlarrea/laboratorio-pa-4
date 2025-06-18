
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "../dt/DTFecha.h"

using namespace std;

class Usuario {

protected:
    string nickName;
    string password;
    DTFecha *fechaNacimiento;
public:
    Usuario();
    Usuario(string nickName, string password, DTFecha* fechaNacimiento);

    string getNickName() const;
    string getPassword() const;
    DTFecha* getFechaNacimiento() const;

    virtual ~Usuario();
};



#endif //USUARIO_H
