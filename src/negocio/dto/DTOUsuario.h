//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef DTOUSUARIO_H
#define DTOUSUARIO_H
#include <iostream>
#include "../dt/DTFecha.h"
using namespace std;

class DTOUsuario {
protected:
  string nickName;
  string password;
  DTFecha *fechaNacimiento;

public:
  DTOUsuario();
  DTOUsuario(string nickName, string password, DTFecha* fechaNacimiento);
  virtual string getNickName();
  virtual string getPassword();
  virtual DTFecha* getFechaNacimiento();
  virtual ~DTOUsuario();
  virtual string toString() const = 0;
};

#endif //DTOUSUARIO_H
