
#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Producto.h"
#include "Usuario.h"

class Producto;

class Vendedor : public Usuario {

private:
    string rut;
    map<string,Producto*> productos;

public:
    Vendedor();
    Vendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut);

    void addProducto(Producto* producto);
    map<string,Producto*> getProductos();

    ~Vendedor();
};



#endif //VENDEDOR_H
