
#include "MenuPpal.h"
#include <iostream>
#include "AltaUsuario.h"
#include "ListarUsuarios.h"
#include "ExpedienteUsuario.h"

#include "AltaProducto.h"
#include "AltaPromocion.h"
#include "ConsultarProducto.h"
#include "ConsultarPromocion.h"
#include "ListarProductos.h"

#include "DejarComentario.h"
#include "EliminarComentario.h"
#include "EnviarProducto.h"

#include "RealizarCompra.h"

using namespace std;

MenuPpal::MenuPpal() = default;

MenuPpal::~MenuPpal() = default;

void MenuPpal::mostrarMenu() {
  int op = 0;
  do {
    cout << endl << endl << "*** Menu principal ***" << endl;
    cout << "1) Alta Usuario" << endl;
    cout << "2) Listar Usuarios" << endl;
    cout << "3) Alta Producto" << endl;
    cout << "4) Consultar Producto" << endl;
    cout << "5) Craer Promocion" << endl;
    cout << "6) Consultar Promocion" << endl;
    cout << "7) Realizar Compra" << endl;
    cout << "8) Dejar Comentario" << endl;
    cout << "9) Eliminar Comentario" << endl;
    cout << "10) Enviar Producto" << endl;
    cout << "11) Expediente de Usuario" << endl;
    cout << "12) Listar Productos - No tiene CU" << endl;
    cout << "0) Salir " << endl;
    cout << "Ingrese una opcion: " << endl;


    cin >> op;
    switch (op) {
      case 0:
        break;
      case 1: {
        AltaUsuario altaUsuario;
        altaUsuario.altaUsuario();
      }
      break;
      case 2: {
        ListarUsuarios listarUsuarios;
        listarUsuarios.listarUsuarios();
      }
      break;
      case 3: {
        AltaProducto altaProducto;
        altaProducto.altaProducto();
      }
      break;
      case 4: {
        ConsultarProducto consultarProducto;
        consultarProducto.consultarProducto();
      }
      break;
      case 5: {
        AltaPromocion altaPromocion;
        altaPromocion.altaPromocion();
      }
      break;
      case 6: {
        ConsultarPromocion consultarPromocion;
        consultarPromocion.consultarPromocion();
      }
      break;
      case 7: {
        RealizarCompra realizarCompra;
        realizarCompra.realizarCompra();
      }
      break;
      case 8: {
        DejarComentario dejarComentario;
        dejarComentario.dejarComentario();
      }
      break;
      case 9: {
        EliminarComentario eliminarComentario;
        eliminarComentario.eliminarComentario();
      }
      break;
      case 10: {
        EnviarProducto enviarProducto;
        enviarProducto.enviarProducto();
      }
      break;
      case 11: {
        ExpedienteUsuario expedienteUsuario;
        expedienteUsuario.expedienteUsuario();
      }
      break;
      case 12: {
        ListarProductos listarProductos;
        listarProductos.listarProductos();
      }
      break;
      default:
        cout << "Opcion desconocida" << endl;
    }

  } while (op != 0);

  cout << "Fin del programa" << endl;
}