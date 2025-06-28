//
// Created by Walter on 27/06/2025.
//

#ifndef DTOCOMPRACLIENTE_H
#define DTOCOMPRACLIENTE_H
#include "../dt/DTFecha.h"


class DTOCompraCliente {
private:
  DTFecha* fechaCompra;
  string nickCliente;
  string codigoCompra;
  double montoFinal;

public:
  DTOCompraCliente();
  DTOCompraCliente(DTFecha* fechaCompra, string nickCliente, string codCompra, double montoFinal);
  ~DTOCompraCliente();

  DTFecha* getFechaCompra();
  string getNickCliente();
  string getCodigoCompra();
  double getMontoFinal();

  string toString();
};



#endif //DTOCOMPRACLIENTE_H
