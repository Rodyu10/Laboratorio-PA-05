#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

#include "./cabezales.h"

using namespace std;

int Cant = 0;
float Suma = 0;

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
              cout << endl << "Ingrese su foto de perfil" << endl;
              getchar();
              getline(cin,foto);
              cout << endl << "Ingrese su contraseña" << endl;
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
                cout << endl <<"Ingrese su contraseña, (S) para salir" << endl;
                cin >> pass;
                if(!sis->VerificarSesion(nick,pass) && (pass!="S" && pass!="s"))
                cout << "Contraseña incorrecta" << endl;
              }while(!sis->VerificarSesion(nick,pass) && (pass!="S" && pass!="s"));
              if(sis->VerificarSesion(nick,pass)){
                Usuario* user = sis->obtenerUsuario(nick);
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
                            if(sis->esAdmin(nick)){
                              string dir, op;
                              bool repetir=true;
                              while(repetir){
                              cout << "==========================================================" << endl;
                              cout << "                       ALTA CINE" << endl;
                              cout << "==========================================================" << endl;
                              int NroCine=sis->CantCines()+1, NroSala=1;
                                cout << "Ingrese la direccion del cine, (S) para salir" << endl;
                                getchar();
                                getline(cin,dir);
                                sis->verificarCine(dir);
                                if(dir!="S" && dir!="s"){
                                  int precio;
                                  cout << endl << "Ingrese el precio de entrada de este cine" << endl;
                                  cin >> precio;
                                  Cine* cine = new Cine(NroCine,precio,dir);
                                  string cap;
                                  do{
                                    cout << endl << "Ingrese la capacidad de la sala " << NroSala << ", (S) para salir" << endl;
                                    cin >> cap;
                                    if(cap!="S" && cap!="s"){
                                      cine->agregarSalas(NroSala, stoi(cap));
                                      NroSala++;
                                    }
                                    if(NroSala==1)
                                    cout << "Debe ingresar al menos una sala" << endl;
                                  }while((cap!="S" && cap!="s") || NroSala==1);
                                  float descuento;
                                  NroSala=1;
                                  do{
                                    cout << endl << "Ingrese el nombre de la financiera asociada " << NroSala << ", (S) para salir" << endl;
                                    getchar();
                                    getline(cin,op);
                                    if(op!="S" && op!="s"){
                                      cout <<"Ingrese el procentaje de descuento de la financiera" << endl;
                                      cin >> descuento;
                                      if(op!="S" && op!="s"){
                                        if(cine->agregarFinanciera(op,descuento)){
                                          NroSala++;
                                          cout << "Financiera agregada exitosamente" << endl;
                                        }
                                        else
                                        cout << "Esta financiera ya se encuentra asociada al cine" << endl;
                                      }
                                    }
                                  }while((op!="S" && op!="s"));
                                  cout << endl << "¿Confirma el alta de este cine? (S) o (N)" << endl;
                                  cin >> op;
                                  if(op=="S" || op=="s"){
                                    sis->AltaCine(cine);
                                    cout << "Cine agregado exitosamente" << endl << endl;
                                    NroCine ++;
                                  }
                                  else{
                                    delete cine;
                                    cout << "Operacion cancelada" << endl << endl;
                                  }
                                  system("clear");
                                }
                                else
                                repetir=false;
                              }
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
                            sis->Control();
                            if(sis->esAdmin(nick)){
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
                                  cout << "¿Desea ingresar otra funcion para esta pelicula? (S) o (N)" << endl;
                                  cin >> t;
                                  if(t=="N" || t=="n")
                                  ingresarMas=false;
                                }
                              }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          getchar();
                          }
                        }
                        break;
                      case 3:{
                            try{
                              cout << "==========================================================" << endl;
                              cout << "                    ALTA PELICULA" << endl;
                              cout << "==========================================================" << endl;
                              sis->Control();
                              if(sis->esAdmin(nick)){
                                string t,p,s;
                                int cine;
                                cout << "Ingrese el titulo de la pelicula" << endl;
                                getchar();
                                getline(cin,t);
                                Pelicula* peli = sis->verificarPelicula(t);
                                if(!peli){
                                  cout << endl << "Ingrese el poster de la pelicula" << endl;
                                  getline(cin,p);
                                  cout << endl << "Ingrese la sinopsis de la pelicula" << endl;
                                  getline(cin,s);
                                }
                                else{
                                  p = peli->getPoster();
                                  s = peli->getSinopsis();
                                }
                                  ICollection* cines = sis->ListarCines();
                                  ListarCines(cines);
                                  cout << "Ingrese el numero del cine" << endl;
                                  cin >> cine;
                                  sis->SeleccionCine(cine);
                                  sis->AltaPelicula(t,p,s,cine);

                                cout << endl <<"Pelicula agregada exitosamente" << endl;
                              }
                            }
                            catch(exception &e){
                            cout << e.what() << endl;
                            }
                            getchar();
                          }
                          break;
                    case 4:{
                          try{
                            cout << "===========================================================" << endl;
                            cout << "                       CREAR RESERVA" << endl;
                            cout << "===========================================================" << endl;
                            sis->Control();
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
                                  cout << endl << "==============================================================" << endl;
                                  cout << "Poster: " << peli->getPoster() << endl;
                                  cout << "Sinopsis: " << peli->getSinopsis() << endl;
                                  cout << "==============================================================" << endl;
                                  string op;
                                  cout << endl << "¿Desea ver los cines para esta pelicula? (S) o (N)" << endl;
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
                                          string nombreBF;
                                          Cine* cine = sis->SeleccionCine(nroCine);
                                          if(cine->verificarPelicula(peli->getTitulo()))
                                          throw invalid_argument("\nEl cine seleccionado no contiene la pelicula elegida");
                                          ICollection* funciones = cine->ListarFunciones(peli->getTitulo());
                                          ListarFunciones(funciones);
                                          cout << "Ingrese el numero de la funcion, (S) para salir" << endl;
                                          cin >> NroFuncion;
                                          Funcion* funcion = sis->SeleccionFuncion(cine,NroFuncion);
                                          cout << endl << "¿Cuantos asientos desea reservar?" << endl;
                                          cin >> cantAsientos;
                                          cout << endl << "¿Desea pagar en credito o debito? (C) o (D)" << endl;
                                          cin >> nombreBF;
                                          bool CrDe=true;
                                          float costo=0, descuento=0;
                                          costo = cine->getPrecioEntrada()*cantAsientos;
                                          if(nombreBF=="C" || nombreBF =="c"){
                                            ICollection* financieras = cine->ListarFinancieras();
                                            ListarFinancieras(financieras);
                                            cout << "Ingrese el nombre de la financiera" << endl;
                                            getchar();
                                            getline(cin,nombreBF);
                                            if(cine->verificarFinanciera(nombreBF)){
                                              cout << endl << "Tiene descuento de " << cine->DescuentoFinanciera(nombreBF) << "%" << endl;
                                              descuento = costo*(cine->DescuentoFinanciera(nombreBF)/100);
                                            }
                                            else{
                                              cout << "Esta financiera no esta asociada al cine" << endl;
                                              cout << "Por lo tanto no se obtiene un descuento" << endl;
                                            }
                                            CrDe=false;
                                          }
                                          else{
                                            cout << endl << "Ingrese el nombre del banco" << endl;
                                            getchar();
                                            getline(cin,nombreBF);
                                          }
                                          cout << "Cantidad de asientos: " << cantAsientos << endl;
                                          cout << "Precio de la entrada: " << cine->getPrecioEntrada() << endl;
                                          cout << "Precio total: " << costo << endl;
                                          costo=costo-descuento;
                                          cout << "Total a pagar con descuento: " << costo << endl;
                                          cout << endl << "¿Desea crear la reserva? (S) o (N)" << endl;
                                          cin >> op;
                                          if(op=="S" || op=="s"){
                                            funcion->AltaReserva(user,cantAsientos,costo,nombreBF,cine->DescuentoFinanciera(nombreBF), CrDe);
                                            cout << "Reserva creada exitosamente" << endl;
                                          }
                                      }
                                  }
                                  string res;
                                  cout << endl << "¿Desea crear una reserva para otra pelicula? (S) o (N)" << endl;
                                  cin >> res;
                                  if(res=="n" || res=="N")
                                  repetir=false;
                              }
                              else
                              repetir=false;
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          getchar();
                          }
                        }
                        break;
                    case 5:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "            PUNTUAR PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->Control();
                            ICollection* peliculas = sis->ListarPeliculas();
                            ListarTitulos(peliculas);
                            string t;
                            cout << "Seleccione la pelicula deseada" << endl;
                            getchar();
                            getline(cin,t);
                            Pelicula* peli = sis->SeleccionPelicula(t);
                            float promedio;
                            ICollection* lista = peli->ListarPuntajes(peli);
                            if(lista != 0){
                              ListarPuntaje(lista);
                              ICollection* lista2 = peli->ListarPuntajes(peli);
                              int chequeo = ChequeoUsuario(lista2, nick);
                               if(chequeo == 1){
                                  //REMPLAZA PUNTAJE SI YA HABIA PUNTUADO;
                                  float pr = 0;
                                  while (pr<1 || pr>5){
                                    cout << "Ingrese el puntaje para remplazar" << endl;
                                    cin >> pr;
                                  }
                                  peli->AgregarPuntaje(peli,nick,pr);
                                  peli->setPuntaje(pr);
                                  }
                              else{
                                  // PUNTUACION NUEVA SI YA HAY PUNTAJES
                                  float pr = 0;
                                  while (pr<1 || pr>5){
                                    cout << "Ingrese el nuevo puntaje" << endl;
                                    cin >> pr;
                                  }
                                  peli->AgregarPuntaje(peli,nick,pr);
                                  Cant++;
                                  Suma = Suma + pr;
                                  promedio = (float) Suma / Cant;
                                  peli->setPuntaje(promedio);
                                  }
                              }
                          else{
                            // PUNTUACION NUEVA
                            cout << endl << "La pelicula no contiene ningun puntaje aun" << endl;
                            float pr = 0;
                            while (pr<1 || pr>5){
                              cout << "Ingrese el nuevo puntaje" << endl;
                              cin >> pr;
                            }
                            peli->AgregarPuntaje(peli,nick,pr);
                            Cant++;
                            Suma = Suma + pr;
                            promedio = (float) Suma / Cant;
                            peli->setPuntaje(promedio);
                            cout <<"Su puntaje ha sido agregado" << endl;
                              }
                          }
                            catch(exception &e){
                            cout << e.what() << endl;
                            getchar();
                            }
                          }
                        break;
                    case 6:{
                          try{
                            cout << "======================================================" << endl;
                            cout << "                 ELIMINAR PELICULA" << endl;
                            cout << "======================================================" << endl;
                            sis->Control();
                            if(sis->esAdmin(nick)){
                              ICollection* peliculas = sis->ListarPeliculas();
                              ListarTitulos(peliculas);
                              string pelicula, op;
                              cout << "Ingrese el título de la película" << endl;
                              getchar();
                              getline(cin,pelicula);
                              Pelicula* peli = sis->SeleccionPelicula(pelicula);
                              cout << endl << "¿Esta seguro que desea borrar esta pelicula? (S) o (N)" << endl;
                              cin >> op;
                              if(op=="S" || op=="s"){
                                sis->EliminarPelicula(peli);
                                cout << endl <<"Pelicula eliminada" << endl;
                              }
                              else
                              cout << endl <<"Operacion cancelada" << endl;
                            }
                            getchar();
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
                            sis->Control();
                            ICollection* peliculas = sis->ListarPeliculas();
                            ListarTitulos(peliculas);
                            string t;
                            cout << "Seleccione la pelicula deseada" << endl;
                            getchar();
                            getline(cin,t);
                            Pelicula* peli = sis->SeleccionPelicula(t);
                            peli->ListarComentarios(peli);
                            string com;
                            cout <<"Elija un comentario si lo desea, de lo contrario presione 'N' " << endl;
                            getline(cin,com);
                            if(com == "N" || com == "n"){
                              cout << endl << "Ingrese un nuevo comentario" << endl;
                              getline(cin,com);
                              peli->agregarComentario(peli, nick, com);
                              cout << endl << "Comentario agregado" << endl;
                            }
                            else {
                              Comenta* co = peli->BuscarComentario(peli,com);
                              if(co!=NULL){
                                string res;
                                cout << endl << "Ingrese la respuesta al comentario seleccionado" << endl;
                                getline(cin,res);
                                peli->agregaCom(peli, co, nick, res);
                                cout << endl << "Respuesta agregada" << endl;
                                }
                                else{
                                  throw invalid_argument("El comentario ingresado es incorrecto");
                                }
                              }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          getchar();
                          }
                        }
                        break;
                    case 8:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "        VER INFORMACION DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->Control();
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
                                  cout << endl << "==============================================================" << endl;
                                  cout << "Poster: " << peli->getPoster() << endl;
                                  cout << "Sinopsis:" << peli->getSinopsis() << endl;
                                  cout << "==============================================================" << endl;
                                  string op;
                                  cout << endl<<"¿Desea ver los cines para esta pelicula? (S) o (N) para salir" << endl;
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

                                          ICollection* funciones = cine->ListarFunciones(peli->getTitulo());
                                          ListarFunciones(funciones);
                                      }
                                  }
                                  string t;
                                  cout << endl << "¿Desea ver informacion de otra pelicula? (S) o (N)" << endl;
                                  cin >> t;
                                  if(t=="N" || t=="n")
                                  repetir=false;
                              }
                              else
                              throw invalid_argument("\nSe cancelo la operacion");
                            }
                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          getchar();
                          }
                        }
                        break;
                    case 9:{
                          try{
                            cout << "==========================================" << endl;
                            cout << "  VER COMENTARIOS Y PUNTAJES DE PELICULA" << endl;
                            cout << "==========================================" << endl;
                            sis->Control();
                            ICollection* peliculas = sis->ListarPeliculas();
                            ListarTitulos(peliculas);
                            string t;
                            cout << "Seleccione la pelicula deseada" << endl;
                            getchar();
                            getline(cin,t);
                            Pelicula* peli = sis->SeleccionPelicula(t);
                            system("clear");
                            cout << peli->getTitulo() << endl;
                            cout << "Puntaje promedio: "<< peli->getPuntaje() <<  " (" << Cant << " usuarios)"<< endl;
                            cout << "=================================" << endl;
                            peli->ListarComentarios(peli);
                            cout << "=================================" << endl;
                            ICollection* lista = peli->ListarPuntajes(peli);
                            if(lista != 0){
                              cout << " PUNTAJES " << endl;
                              ListarPuntaje(lista);
                            }

                          }
                          catch(exception &e){
                          cout << e.what() << endl;
                          getchar();
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
