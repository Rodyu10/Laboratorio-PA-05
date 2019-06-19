#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

using namespace std;

void menu()
{
  cout << "====================================" << endl;
  cout << "           MENU PRINCIPAL" << endl;
  cout << "====================================" << endl;
  cout << "1-Registrar Usuario" << endl;
  cout << "2-Iniciar Sesion" << endl;
  cout << "0-Salir" << endl;
  cout << "====================================" << endl;
}

void menuDos()
{
  cout << "====================================" << endl;
  cout << "            MENU USUARIO" << endl;
  cout << "====================================" << endl;
  cout << "1-Alta Cine" << endl;
  cout << "2-Alta Funcion" << endl;
  cout << "3-Crear Reserva" << endl;
  cout << "4-Puntuar Pelicula" << endl;
  cout << "5-Eliminar Pelicula" << endl;
  cout << "6-Comentar Pelicula" << endl;
  cout << "7-Ver informacion de Pelicula" << endl;
  cout << "8-Ver comentarios y puntaje de Pelicula" << endl;
  cout << "9-Alta Pelicula" << endl;
  cout << "0-Volver al menu principal" << endl;
  cout << "====================================" << endl;
}

int opcion()
{
    int op;
    do
    {
        cout << "Ingrese Opción: " << endl;
        cin >> op;
    }
    while ((op < 0) || (op > 2));
    return op;
}

int opcionDos()
{
    int op;
    do
    {
        cout << "Ingrese Opción: " << endl;
        cin >> op;
    }
    while ((op < 0) || (op > 9));
    return op;
}
