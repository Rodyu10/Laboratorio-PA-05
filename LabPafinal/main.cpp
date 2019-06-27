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
              cout << "Ingrese su nombre de usuario" << endl;
              getchar();
              getline(cin,nick);
              cout << "Ingrese su foto de perfil" << endl;
              getchar();
              getline(cin,foto);
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
              cout << "Ingrese su usuario" << endl;
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
                            cout << "==========================================================" << endl;
                            cout << "                       ALTA CINE" << endl;
                            cout << "==========================================================" << endl;
                            if(sis->esAdmin(nick)){
                              string dir;
                              int nro;
                              cout << "Ingrese el numero del cine" << endl;
                              cin >> nro;
                              cout << "Ingrese la direccion del cine" << endl;
                              getchar();
                              getline(cin,dir);
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
                            cout << "==========================================================" << endl;
                            cout << "                     ALTA FUNCION" << endl;
                            cout << "==========================================================" << endl;
                            if(sis->esAdmin(nick)){
                                sis->Control();
                                string t;
                                int nro, nroSala;
                                sis->ListarPeliculas();
                                cout << "Ingrese el titulo de la pelicula" << endl;
                                getchar();
                                getline(cin,t);
                                Pelicula* peli = sis->SeleccionPelicula(t);
                                sis->ListarCines(peli->getTitulo());
                                cout << "Ingrese el numero  del cine" << endl;
                                cin >> nro;
                                Cine* cine = sis->SeleccionCine(nro);
                                if(cine->verificarPelicula(peli->getTitulo()))
                                throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");
                                bool ingresarMas=true;
                                while(ingresarMas){
                                  sis->ListarSalas(cine);
                                  cout << "Ingrese el numero  de la sala" << endl;
                                  cin >> nroSala;
                                  sis->SeleccionSala(cine,nroSala);
                                  sis->AltaFuncion(cine,peli,nroSala);
                                  cout << "¿Desea ingresar otra funcion para esta pelicula? (Y) o (N)" << endl;
                                  cin >> t;
                                  if(t=="N" || t=="n"){
                                    ingresarMas=false;
                                  }
                                }
                              }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                      case 3:{
                            try{
                              cout << "==========================================================" << endl;
                              cout << "                    ALTA PELICULA" << endl;
                              cout << "==========================================================" << endl;
                              if(sis->esAdmin(nick)){
                                string t,p,s;
                                int cine;
                                cout << "Ingrese el titulo de la pelicula" << endl;
                                getchar();
                                getline(cin,t);
                                cout << "Ingrese el poster de la pelicula" << endl;
                                getchar();
                                getline(cin,p);
                                cout << "Ingrese la sinopsis de la pelicula" << endl;
                                getchar();
                                getline(cin,s);
                                cout << "Ingrese el numero del cine" << endl;
                                cin >> cine;
                                sis->AltaPelicula(t,p,s,cine);
                              }
                            }
                            catch(exception &e){
                            cout << e.what() << endl;
                            }
                          }
                          break;
                    case 4:{
                          try{
                            cout << "===========================================================" << endl;
                            cout << "                       CREAR RESERVA" << endl;
                            cout << "===========================================================" << endl;
                            sis->ListarTitulos();
                            string pelicula;
                            cout << "Ingrese el título de la película, (S) para salir" << endl;
                            getchar();
                            getline(cin,pelicula);
                            if(pelicula!="s" || pelicula!="S")
                            {
                                Pelicula* peli = sis->SeleccionPelicula(pelicula);
                                cout << endl << "Poster: " << peli->getPoster() << endl;
                                cout << "Sinopsis:" << peli->getSinopsis() << endl;
                                string op;
                                cout << endl<<"¿Desea ver infomacion adicional? (Y) o (N) para salir" << endl;
                                cin >> op;
                                if(op!="n" || op!="N")
                                {
                                    sis->ListarCines(pelicula);
                                    cout << "Seleccione el numero del cine, (S) para salir" << endl;
                                    cin >> op;
                                    if(op!="s" || op!="S")
                                    {
                                        int nroCine = stoi(op);
                                        int NroFuncion, cantAsientos;
                                        string pago;
                                        Cine* cine = sis->SeleccionCine(nroCine);
                                        if(cine->verificarPelicula(peli->getTitulo()))
                                        throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");
                                        sis->ListarFunciones(cine,peli);
                                        cout << "Ingrese el numero de la funcion, (S) para salir" << endl;
                                        cin >> NroFuncion;
                                        sis->SeleccionFuncion(cine,NroFuncion);
                                        cout << "¿Cuantos asientos desea reservar?" << endl;
                                        cin >> cantAsientos;
                                        cout << "¿Desea pagar en credito o debito? (C) o (D)" << endl;
                                        cin >> pago;
                                        if(pago=="C" || pago =="c"){
                                          cout << "Ingrese el nombre de la financiera" << endl;
                                          cin >> pago;
                                        }
                                        else{
                                          cout << "Ingrese el nombre del banco" << endl;
                                          cin >> pago;
                                        }
                                    }
                                    else
                                    throw invalid_argument("Se canceló la opeación");
                                }
                                else
                                throw invalid_argument("Se canceló la opeación");
                            }
                            else
                            throw invalid_argument("Se canceló la opeación");
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 5:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            PUNTUAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->PuntuarPelicula(nick);
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 6:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            ELIMINAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            if(sis->esAdmin(nick)){
                              string t;
                              cout << "Ingrese el titulo de la pelicula que desea eliminar" << endl;
                              getchar();
                              getline(cin,t);
                              sis->EliminarPelicula(t);
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 7:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            COMENTAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->ComentarPelicula(nick);
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 8:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "        VER INFORMACION DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->VerInfoPelicula();
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                        break;
                    case 9:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "  VER COMENTARIOS Y PUNTAJES DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->VerComentariosPuntaje();
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          }
                        }
                      break;
                  }
                    cout << "Presione enter para continuar" << endl;
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
