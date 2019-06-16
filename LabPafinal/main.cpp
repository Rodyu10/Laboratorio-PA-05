#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

#include "./cabezales.h"

using namespace std;

int main(){
  system("clear");
  menu();
  Sistema* sis = Sistema::getInstance();
  int op = opcion();
    while (op!=0)
    {
      system("clear");
      switch(op)
      {
        case 1:{
            try{
              cout << "==========================================" << endl;
              cout << "             REGISTRAR USUARIO" << endl;
              cout << "==========================================" << endl;
              string nick,foto,pass;
              cout << " Ingrese su nombre de usuario" << endl;
              cin >> nick;
              cout << "Ingrese su foto de perfil" << endl;
              cin >> foto;
              cout << "Ingrese su contrasenia" << endl;
              cin >> pass;
              sis->RegistrarUsuario(nick,foto,pass);
            }
            catch(exception &e){
            cout << e.what() << endl;
            }
          }
          break;
          case 2:{
            try{
              cout << "==========================================" << endl;
              cout << "             INICIAR SESION" << endl;
              cout << "==========================================" << endl;
              string nick,pass;
              cout << " Ingrese su usuario" << endl;
              cin >> nick;
              cout << "Ingrese su contrasenia" << endl;
              cin >> pass;
              sis->IniciarSesion(nick,pass);

              getchar();
              getchar();
              system("clear");
              menu2();
              int opc = opcion2();
                while (opc!=0)
                {
                  system("clear");
                  switch(opc)
                  {
                    case 1:{
                        try{
                            cout << "LISTA PELIS" << endl;
                        }
                        catch(exception &e){
                        cout << e.what() << endl;
                        }
                      }
                      break;
                    case 2:{
                        try{
                            cout << "LISTA CINES" << endl;
                        }
                        catch(exception &e){
                        cout << e.what() << endl;
                        }
                      }
                      break;
                    }
                    cout << "Presione enter para continuar" << endl;
                    getchar();
                    getchar();
                    system("clear");
                    menu2 ();
                    op = opcion2();
                }
            }catch(exception &e){
            cout << e.what() << endl;
            }
          }
          break;
        }
      cout << "Presione enter para continuar" << endl;
      getchar();
      getchar();
      system("clear");
      menu ();
      op = opcion();
  }
system("clear");
cout << "======================================================" << endl;
cout << " Gracias por utilizar nuestro programa, hasta pronto!" << endl;
cout << "======================================================" << endl;
return 0;
}
