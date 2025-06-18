//
// Created by walte on 14/06/2025.
//

#ifndef ECATPRODUCTO_H
#define ECATPRODUCTO_H

#include<map>
#include<string>

using namespace std;

class ECatProducto {
private:
  int valor;
  static map<int, string>* categorias;

public:
  ECatProducto();
  ECatProducto(int valor);

  int getValor();
  void setValor(int valor);
  string getNombre();
  string toString();

  static bool verificarCategoria(int valor);
  static string getNombre(int valor);
  static map<int, string>* getCategorias();

  ~ECatProducto();
};



#endif //ECATPRODUCTO_H
