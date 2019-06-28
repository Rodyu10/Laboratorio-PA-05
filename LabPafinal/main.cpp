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
              cout << endl << "Usuario registrado exitosamente" << endl;
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
              do{
                cout << "Ingrese su contraseña, (S) para salir" << endl;
                cin >> pass;
                if(!sis->VerificarSesion(nick,pass) && (pass!="S" && pass!="s"))
                cout << "Contraseña incorrecta" << endl;
              }while(!sis->VerificarSesion(nick,pass) && (pass!="S" && pass!="s"));
              if(sis->VerificarSesion(nick,pass)){
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
                              string dir, op;
                              int NroCine=3, NroSala=1;
                              do{
                                cout << "Ingrese la direccion del cine, (S) para salir" << endl;
                                getchar();
                                getline(cin,dir);
                                if(dir!="S" && dir!="s"){
                                  Cine* cine = new Cine(NroCine,dir);
                                  string cap;
                                  do{
                                    cout << "Ingrese la capacidad de la sala, (S) para salir" << endl;
                                    cin >> cap;
                                    if(cap!="S" && cap!="s"){
                                      cine->agregarSalas(NroSala, stoi(cap));
                                      NroSala++;
                                    }
                                    if(NroSala==1)
                                    cout << "Debe ingresar al menos una sala" << endl;
                                  }while((cap!="S" && cap!="s") || NroSala==1);
                                  int precio;
                                  float descuento;
                                  cout << endl << "Ingrese el precio de entrada de este cine" << endl;
                                  cin >> precio;
                                  cine->setPrecioEntrada(precio);
                                  do{
                                    cout << endl << "Ingrese el nombre de la financiera asociada, (S) para salir" << endl;
                                    cin >> op;
                                    if(op!="S" && op!="s"){
                                      cout << "Ingrese el procentaje de descuento de la financiera" << endl;
                                      cin >> descuento;
                                      if(op!="S" && op!="s"){
                                        cine->agregarFinanciera(op,descuento);
                                        cout << "Financiera agregada exitosamente" << endl;
                                      }
                                    }
                                  }while((op!="S" && op!="s"));
                                  cout << "¿Confirma el alta de este cine? (Y) o (N)" << endl;
                                  cin >> op;
                                  if(op=="Y" || op=="y"){
                                    sis->AltaCine(cine);
                                    cout << "Cine agregado exitosamente" << endl << endl;
                                    NroCine ++;
                                  }
                                  else{
                                    delete cine;
                                    cout << "Operacion cancelada" << endl << endl;
                                  }
                                  NroSala=1;
                                }
                              }while(dir!="S" && dir!="s");
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
                                ICollection* peliculas = sis->ListarPeliculas();
                                ListarPeliculas(peliculas);
                                cout << "Ingrese el titulo de la pelicula" << endl;
                                getchar();
                                getline(cin,t);
                                Pelicula* peli = sis->SeleccionPelicula(t);
                                ICollection* cines = sis->ListarCines(peli->getTitulo());
                                ListarCines(cines);
                                cout << "Ingrese el numero  del cine" << endl;
                                cin >> nro;
                                Cine* cine = sis->SeleccionCine(nro);
                                if(cine->verificarPelicula(peli->getTitulo()))
                                throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");

                                bool ingresarMas=true;
                                while(ingresarMas){
                                  ICollection* salas = cine->ListarSalas();
                                  ListarSalas(salas);
                                  cout << "Ingrese el numero  de la sala" << endl;
                                  cin >> nroSala;
                                  Sala* sala = cine->seleccionarSala(nroSala);
                                  string f, d, m, num, h, min;
                                  int NroFuncion=cine->CantFunciones()+1;
                                  do{
                                    cout << endl << "Ingrese la fecha de la funcion: formato (DD/MM/AAAA)" << endl;
                                    cin >> f;
                                    d = f.substr(0,f.find("/"));
                                    f = f.substr(f.find("/")+1,f.length()-2);
                                    m = f.substr(0,f.find("/"));
                                    f = f.substr(f.find("/")+1,f.length()-2);
                                  }while(stoi(d)>31 || stoi(d)<0 || stoi(m)>12 || stoi(m)<0 || stoi(f)<2019);
                                  DtFecha* fecha = new DtFecha(stoi(d),stoi(m),stoi(f));
                                  do{
                                    cout << endl << "Ingrese la hora de la funcion: formato (HH:MM)" << endl;
                                    cin >> num;
                                    h = num.substr(0,num.find(":"));
                                    num = num.substr(num.find(":")+1,num.length()-2);
                                    min = num.substr(0,num.find(":"));
                                  }while(stoi(h)>=24 || stoi(h)<=0 || stoi(min)>59 || stoi(m)<0);
                                  DtHora* hora = new DtHora(stoi(h),stoi(min));
                                  cine->agregarFuncion(peli,NroFuncion,sala->getNroSala(),fecha,hora);
                                  cout << "Funcion agregada exitosamente" << endl << endl;
                                  NroFuncion++;
                                  delete fecha;
                                  delete hora;
                                  cout << "¿Desea ingresar otra funcion para esta pelicula? (Y) o (N)" << endl;
                                  cin >> t;
                                  if(t=="N" || t=="n")
                                  ingresarMas=false;
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
                                ICollection* cines = sis->ListarCines();
                                ListarCines(cines);
                                cout << "Ingrese el numero del cine" << endl;
                                cin >> cine;
                                sis->SeleccionCine(cine);
                                sis->AltaPelicula(t,p,s,cine);
                                cout << "Pelicula agrega exitosamente" << endl;
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
                            ICollection* peliculas = sis->ListarPeliculas();
                            ListarTitulos(peliculas);
                            string pelicula;
                            cout << "Ingrese el título de la película, (S) para salir" << endl;
                            getchar();
                            getline(cin,pelicula);
                            if(pelicula!="s" && pelicula!="S")
                            {
                                Pelicula* peli = sis->SeleccionPelicula(pelicula);
                                cout << endl << "==============================================" << endl;
                                cout << endl << "Poster: " << peli->getPoster() << endl;
                                cout << "Sinopsis:" << peli->getSinopsis() << endl;
                                cout << endl << "==============================================" << endl;
                                string op;
                                cout << endl<<"¿Desea ver los cines para esta pelicula? (Y) o (N) para salir" << endl;
                                cin >> op;
                                if(op!="n" && op!="N")
                                {
                                    ICollection* cines = sis->ListarCines(pelicula);
                                    ListarCines(cines);
                                    cout << "Seleccione el numero del cine, (S) para salir" << endl;
                                    cin >> op;
                                    if(op!="s" && op!="S")
                                    {
                                        int nroCine = stoi(op);
                                        int NroFuncion, cantAsientos;
                                        string pago;
                                        Cine* cine = sis->SeleccionCine(nroCine);
                                        if(cine->verificarPelicula(peli->getTitulo()))
                                        throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");

                                        ICollection* funciones = peli->ListarFunciones();
                                        ListarFunciones(funciones);
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
                                    throw invalid_argument("\nSe canceló la opeación");
                                }
                                else
                                throw invalid_argument("\nSe canceló la opeación");
                            }
                            else
                            throw invalid_argument("\nSe canceló la opeación");
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
                            bool repetir=true;
                            while(repetir){
                              ICollection* peliculas = sis->ListarPeliculas();
                              ListarTitulos(peliculas);
                              string pelicula;
                              cout << "Ingrese el título de la película, (S) para salir" << endl;
                              getchar();
                              getline(cin,pelicula);
                              if(pelicula!="s" && pelicula!="S")
                              {
                                  Pelicula* peli = sis->SeleccionPelicula(pelicula);
                                  cout << endl << "==============================================" << endl;
                                  cout << "Poster: " << peli->getPoster() << endl;
                                  cout << "Sinopsis:" << peli->getSinopsis() << endl;
                                  cout << "==============================================" << endl;
                                  string op;
                                  cout << endl<<"¿Desea ver los cines para esta pelicula? (Y) o (N) para salir" << endl;
                                  cin >> op;
                                  if(op!="n" && op!="N")
                                  {
                                      ICollection* cines = sis->ListarCines(pelicula);
                                      ListarCines(cines);
                                      cout << "Seleccione el numero del cine, (S) para salir" << endl;
                                      cin >> op;
                                      if(op!="s" && op!="S")
                                      {
                                          int nroCine = stoi(op);
                                          Cine* cine = sis->SeleccionCine(nroCine);
                                          if(cine->verificarPelicula(peli->getTitulo()))
                                          throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");

                                          ICollection* funciones = peli->ListarFunciones();
                                          ListarFunciones(funciones);
                                          string t;
                                          cout << "¿Desea ver informacion de otra pelicula? (Y) o (N)" << endl;
                                          cin >> t;
                                          if(t=="N" || t=="n")
                                          repetir=false;
                                      }
                                      else
                                      throw invalid_argument("\nSe canceló la opeación");
                                  }
                                  else
                                  throw invalid_argument("\nSe canceló la opeación");
                              }
                              else
                              throw invalid_argument("\nSe canceló la opeación");
                            }
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
                    getchar();
                    system("clear");
                    menuDos ();
                    opc = opcionDos();
                }
              }
            }catch(exception &e){
            cout << e.what() << endl;
            }
          }
          break;
        }
      cout << endl << "Presione enter para continuar" << endl;
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
