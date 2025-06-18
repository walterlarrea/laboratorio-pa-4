#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>
using namespace std;



class DTDireccion {
private:
    string calle;
int puerta;
    public:
    DTDireccion();
    DTDireccion(string calle, int puerta);
    ~DTDireccion();
    string toString();
};



#endif //DTDIRECCION_H
