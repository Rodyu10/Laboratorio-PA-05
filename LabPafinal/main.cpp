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
              cout << "Ingrese su contraseña" << endl;
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
              cout << "Ingrese su contraseña" << endl;
              cin >> pass;
              sis->IniciarSesion(nick,pass);

              getchar();
              getchar();
              system("clear");
              menuDos();
              int opc = opcionDos();
                while (opc!=0)
                {
                  system("clear");
                  switch(opc)
                  {
                    case 1:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "               ALTA CINE" << endl;
                            cout << "==========================================" << endl;
                            if(sis->esAdmin(nick)){
                              string dir;
                              int nro;
                              cout << " Ingrese el numero del cine" << endl;
                              cin >> nro;
                              cout << "Ingrese la direccion del cine" << endl;
                              cin >> dir;
                              sis->AltaCine(nro,dir);
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 2:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "              ALTA FUNCION" << endl;
                            cout << "==========================================" << endl;
                            if(sis->esAdmin(nick)){
                              // CODE
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 3:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "              CREAR RESERVA" << endl;
                            cout << "==========================================" << endl;
                            // CODE
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 4:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            PUNTUAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            // CODE
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 5:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            ELIMINAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            if(sis->esAdmin(nick)){
                              string t;
                              cout << "Ingrese el titulo de la pelicula que desea eliminar" << endl;
                              cin >> t;
                              sis->EliminarPelicula(t);
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 6:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            COMENTAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            // CODE
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 7:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "        VER INFORMACION DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            // CODE
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 8:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "  VER COMENTARIOS Y PUNTAJES DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            // CODE
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                      break;
                    case 9:{
                            try{
                              cout << "==========================================" << endl;
                              cout << "               ALTA PELICULA" << endl;
                              cout << "==========================================" << endl;
                              if(sis->esAdmin(nick)){
                                string t,p,s;
                                float prom =0;

                                cout << "Ingrese el titulo de la pelicula" << endl;
                                cin >> t;
                                cout << "Ingrese el poster de la pelicula" << endl;
                                cin >> p;
                                cout << "Ingrese la sinopsis de la pelicula" << endl;
                                cin >> s;
                                sis->AltaPelicula(t,p,s,prom);
                              }
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
                    menuDos ();
                    opc = opcionDos();
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
