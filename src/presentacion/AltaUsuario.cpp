//
// Created by Guillermina Rodriguez on 17/6/25.
//

#include <iostream>
#include <string>
#include "AltaUsuario.h"


using namespace std;

AltaUsuario::AltaUsuario() {
    this->iusuario = new IUsuarioController();
}

AltaUsuario::~AltaUsuario() {
    //El controlador solo dura lo que dura el caso de uso
    delete this->iusuario;
}

void AltaUsuario::altaUsuario() {
    string nick;

    cout << "--- Alta de Usuario ---" << endl;
    cout << "Ingrese nickname: ";
    cin >> nick;

    bool existe = this->iusuario->verificarNickname(nick);
    if (!existe) {
        DTOUsuario* nuevoU = registroUsuario (nick);
        this->iusuario->altaUsuario(nuevoU);

        cout << "Registro exitoso!" << endl;

    } else  {
        cout << "ERROR: Ya existe el usuario." << endl;
    }
}



DTOUsuario* AltaUsuario::registroUsuario(string nick) {
    string pass, ciudad, calle, rut;
    int tipo, dia, mes, anio, puerta;

    cout << "Ingrese contraseña: ";
    cin >> pass;
    while (pass.length() < 6) {
        cout << "Contraseña demasiado corta. Reintente: ";
        cin >> pass;
    }

    cout << "Fecha de nacimiento (dia mes año): ";
    cin >> dia >> mes >> anio;
    DTFecha* nac = new DTFecha(dia, mes, anio);

    cout << "Tipo (1 - Cliente, 2 - Vendedor): ";
    cin >> tipo;

    DTOUsuario* nuevo = nullptr;
    if (tipo == 1) {
        cout << "Ciudad: ";
        cin.ignore(); getline(cin, ciudad);
        cout << "Calle: ";
        getline(cin, calle);
        cout << "Puerta: ";
        cin >> puerta;
        DTDireccion* direc = new DTDireccion(calle, puerta);
        nuevo = new DTOCliente(nick, pass, nac, direc, ciudad);


    } else if (tipo == 2) {
        cout << "RUT: ";
        cin >> rut;
        while (rut.length() != 12) {
            cout << "RUT inválido. Ingrese 12 caracteres: ";
            cin >> rut;
        }
        nuevo = new DTOVendedor(nick, pass, nac, rut);

    } else {
        cout << "Tipo inválido. Cancelando..." << endl;
    }

    return nuevo;
}




