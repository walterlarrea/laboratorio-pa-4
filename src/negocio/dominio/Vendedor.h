
#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Producto.h"
#include "Usuario.h"

class Producto;
class Promocion;

class Vendedor : public Usuario {

private:
    string rut;
    map<string,Producto*> productos;
    set<Promocion*> promociones;

public:
    Vendedor();
    Vendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut);

    string getRut();
    void addProducto(Producto* producto);
    map<string,Producto*> getProductos();
    set<Promocion*> getPromociones();
    void addPromocion(Promocion* promocion);

    ~Vendedor();
};



#endif //VENDEDOR_H
