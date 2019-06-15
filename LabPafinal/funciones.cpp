#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

using namespace std;

void menu()
{
  cout << "====================================" << endl;
  cout << "                MENU" << endl;
  cout << "====================================" << endl;
  cout << "1-Registrar Usuario" << endl;
  cout << "2-Iniciar Sesion" << endl;
  cout << "0-Salir" << endl;
  cout << "====================================" << endl;
}

void menu2()
{
  cout << "====================================" << endl;
  cout << "                MENU2" << endl;
  cout << "====================================" << endl;
  cout << "1-Listar Titulos" << endl;
  cout << "2-Listar Cines" << endl;
  cout << "0-Salir" << endl;
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

int opcion2()
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
