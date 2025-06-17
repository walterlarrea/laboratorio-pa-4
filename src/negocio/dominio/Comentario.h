
#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <set>
#include <string>

#include "Cliente.h"
#include "Producto.h"
#include "../dt/DTFecha.h"

using namespace std;

class Cliente;
class Producto;

class Comentario {
private:
    string texto;
    DTFecha* fecha;
    Cliente* cliente;
    Producto* producto;
    set<Comentario*> respuestas;

public:
    Comentario();
    Comentario(string texto, DTFecha* fecha);
    // getInfoComentario ?? TODO
    void eliminarRespuestas();
    void agregarRespuesta(Comentario* respuesta);
    ~Comentario(); // Sería el eliminarComentario()
};



#endif //COMENTARIO_H
