//
// Created by Guillermina Rodriguez on 17/6/25.
//

#ifndef DTOVENDEDOR_H
#define DTOVENDEDOR_H
#include "../dt/DTFecha.h"
#include "DTOUsuario.h"
#include "DTOProducto.h"

class DTOProducto;

class DTOVendedor : public DTOUsuario {

private:
    string rut;
  //  map<string,DTOProducto*> productos;

public:
    DTOVendedor();
    DTOVendedor(string nickName, string password, DTFecha *fechaNacimiento, string rut);

    string getRut();
  //  void addProducto(Producto* producto);
   // map<string,Producto*> getProductos();
   string toString() const override;
    ~DTOVendedor();
};


#endif //DTOVENDEDOR_H
