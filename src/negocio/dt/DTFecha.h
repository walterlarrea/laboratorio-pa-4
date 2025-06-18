#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>

class DTFecha {
private:
    int dia, mes, anio;
    public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    ~DTFecha();
    std::string toString() const;
};




#endif //DTFECHA_H
