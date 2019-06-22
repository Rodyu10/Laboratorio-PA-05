#include "../Headers/Sistema.h"

using namespace std;

int Cant = 0;
float Suma = 0;

Sistema::Sistema(){
  usuarios=new OrderedDictionary();
  cines=new OrderedDictionary();
  peliculas=new OrderedDictionary();
}

Sistema* Sistema::instance = nullptr;

Sistema* Sistema::getInstance(){
    if(instance == nullptr){
      instance = new Sistema();
      instance->Precarga();
    }
    return instance;
}

void Sistema::RegistrarUsuario(string nickname, string fotodeperfil, string pass){
 StringKey* llave = new StringKey(nickname);
 if(!usuarios->member(llave)){
   Usuario* u=new Usuario(nickname,fotodeperfil,pass);
   usuarios->add(llave,u);
   cout << "Usuario registrado exitosamente" << endl;
 }
 else{
    delete llave;
    throw invalid_argument("El usuario ya existe");
 }
}

bool Sistema::VerificarSesion(string nickname, string pass){
  StringKey* llave = new StringKey(nickname);
  if(usuarios->member(llave)){
    Usuario* u=(Usuario*) usuarios->find(llave);
    if(u->verificarPass(pass)){
      delete llave;
      return true;
    }
    else{
      delete llave;
      throw invalid_argument("Password incorrecto");
    }
  }
  else{
    delete llave;
    throw invalid_argument("El usuario es incorrecto");
  }
}

void Sistema::IniciarSesion(string nickname, string pass){
  if(VerificarSesion(nickname,pass)){
    cout << "==========================================" << endl;
    cout << "    INICIO CORRECTAMENTE LA SESION" << endl;
    cout << "==========================================" << endl;
  }
}

void Sistema::AltaCine(int nro, string direc){
  Integer* llave = new Integer(nro);
  if(!cines->member(llave)){
    Cine* c=new Cine(nro, direc);
    cines->add(llave,c);
    string res = "Y";
    int aux = 1;
    while(aux == 1){
      if(res == "y" || res == "Y"){
        int nro,ca;
        cout << "Ingrese el numero de la Sala" << endl;
        cin >> nro;
        cout << "Ingrese la capacidad de la Sala" << endl;
        cin >> ca;
        c->agregarSalas(nro,ca);

        cout << "Desea agregar mas salas al cine (Y o N)?" << endl;
        cin >> res;
        system("clear");
      }
      else{
        aux=0;
      }
    }
  }
  else{
    delete llave;
    throw invalid_argument("El numero de cine ya existe");
  }
}

void Sistema::AltaFuncion(Cine* cine, Pelicula* peli, int NroSala){
  string f, d, m, num, h, min;
  int NroFuncion;
  cout << "Ingrese numero de la funcion" << endl;
  cin >> NroFuncion;
  cout << "Ingrese la fecha de la funcion: formato (DD/MM/AA)" << endl;
  cin >> f;
  d = f.substr(0,f.find("/"));
  f = f.substr(f.find("/")+1,f.length()-2);
  m = f.substr(0,f.find("/"));
  f = f.substr(f.find("/")+1,f.length()-2);
  DtFecha* fecha = new DtFecha(stoi(d),stoi(m),stoi(f));
  cout << "Ingrese la hora de la funcion: formato (HH:MM:SS)" << endl;
  cin >> num;
  h = num.substr(0,num.find(":"));
  num = num.substr(num.find(":")+1,num.length()-2);
  min = num.substr(0,num.find(":"));
  num = num.substr(num.find(":")+1,num.length()-2);
  DtHora* hora = new DtHora(stoi(h),stoi(min),stoi(num));
  cine->agregarFuncion(peli,NroFuncion,NroSala,fecha,hora);
  delete fecha;
  delete hora;
}

void Sistema::Control(){
  if(cines->isEmpty()){
    throw invalid_argument("Aun no hay cines ingresados");
  }
}

void Sistema::ComentarPelicula(string nick){
  ListarTitulos();
  string t;
  cout << "Elija la pelicula deseada" << endl;
  cin >> t;
  StringKey* llave = new StringKey(t);
  if(peliculas->member(llave)){
      Pelicula* aux = (Pelicula*) peliculas->find(llave);
      aux->ListarComentarios(aux);
      aux->agregarComentario(aux,nick);
  }
  else{
    delete llave;
    throw invalid_argument("Pelicula incorrecta");
  }
}

void Sistema::PuntuarPelicula(string user){
  ListarTitulos();
  string t;
  cout << "Elija la pelicula deseada" << endl;
  cin >> t;
  StringKey* llave = new StringKey(t);
  if(peliculas->member(llave)){
      Pelicula* aux = (Pelicula*) peliculas->find(llave);
      float p,promedio;
      p = aux->agregarPuntaje(aux,user);
      Cant++;
      Suma = Suma + p;
      promedio = (float) Suma / Cant;
      aux->setPuntaje(promedio);
  }
  else{
    delete llave;
    throw invalid_argument("Pelicula incorrecta");
  }
}

void Sistema::AltaPelicula(string tit, string pos, string sinop, int cine){
  Integer* intllave = new Integer(cine);
  if(cines->member(intllave)){
      StringKey* llave = new StringKey(tit);
      if(!peliculas->member(llave)){
        Pelicula* p=new Pelicula(tit,pos,sinop,0);
        peliculas->add(llave,p);
      }
      Cine* c = (Cine*) cines->find(intllave);
      Pelicula* p=new Pelicula(tit,pos,sinop,0);
      c->agregarPelicula(tit,p);
      delete intllave;
  }
  else
  {
    delete intllave;
    throw invalid_argument("No existe el numero del cine seleccionado");
  }
}

void Sistema::Precarga(){
  Cine* c1=new Cine(1,"Alvariza");
  Integer* intllave = new Integer(c1->getNroCine());
  cines->add(intllave,c1);
  Cine *c2=new Cine(2,"PuntaShopping");
  intllave = new Integer(c2->getNroCine());
  cines->add(intllave,c2);
  Pelicula* p=new Pelicula("Austin Power vs Doctor Malito","123","123",0);
  StringKey* llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c1->agregarPelicula(p->getTitulo(),p);
  llave = new StringKey("Austin Power vs Doctor Malito la 2");
  p=new Pelicula("Austin Power vs Doctor Malito la 2","123","123",0);
  peliculas->add(llave,p);
  c2->agregarPelicula(p->getTitulo(),p);
  llave = new StringKey("Chuky");
  p=new Pelicula("Chuky","123","123",0);
  peliculas->add(llave,p);
  c1->agregarPelicula(p->getTitulo(),p);
  Usuario* u=new Usuario("root","123","123");
  StringKey* user = new StringKey(u->getNick());
  usuarios->add(user,u);
  c1->agregarSalas(1,50);
  c1->agregarSalas(2,33);
  c2->agregarSalas(1,66);
  c2->agregarSalas(2,33);
}

void Sistema::ListarPeliculas(){
  system("clear");
  IIterator* i=peliculas->getIterator();
  if(i->hasCurrent()){
      cout << "================LISTA PELICULAS==============="<<endl;
    while(i->hasCurrent()){
      Pelicula* p = (Pelicula*) i->getCurrent();
      cout << p->getTitulo() << endl;
      cout << "Poster: " << p->getPoster() << endl;
      cout << "Sinopsis: " << p->getSinopsis() << endl;
      cout << "Puntaje: " << p->getPuntaje() << endl;
      cout << "==============================================" << endl;
      i->next();
    }
    delete i;
  }
  else{
    delete i;
    throw invalid_argument("No hay peliculas registradas");
  }
}

 void Sistema::ListarTitulos(){
   system("clear");
   IIterator* i=peliculas->getIterator();
   if(i->hasCurrent()){
       cout << "=================LISTA TITULOS================"<<endl;
     while(i->hasCurrent()){
       Pelicula* p = (Pelicula*) i->getCurrent();
       cout << p->getTitulo() << endl;
       cout << "==============================================" << endl;
       i->next();
     }
     delete i;
   }
   else{
     delete i;
     throw invalid_argument("No hay peliculas registradas");
   }
}

void Sistema::ListarSalas(Cine* cine){
  system("clear");
  cine->listarSalas();
}

bool Sistema::esAdmin(string nick){
  StringKey* llave = new StringKey(nick);
  if(usuarios->member(llave)){
    Usuario* u = (Usuario*) usuarios->find(llave);
    if(u->getNick() =="root"){
      delete llave;
      return true;
    }
    else{
      delete llave;
      throw invalid_argument("El usuario no tiene permiso para acceder a esta funcion");
    }
  }
  return false;
}

void Sistema::VerComentariosPuntaje(){
  IIterator* i=peliculas->getIterator();
  if(i->hasCurrent()){
      cout << "===============LISTA FUNCIONES================" << endl;
    while(i->hasCurrent()){
      Pelicula* p = (Pelicula*) i->getCurrent();
      cout << p->getTitulo() << endl;
      cout << p->getPoster() << endl;
      cout << "==============================================" << endl;
      i->next();
    }
    string t;
    cout << "Elija la pelicula deseada" << endl;
    cin >> t;
    StringKey* llave = new StringKey(t);
    if(peliculas->member(llave)){
        Pelicula* aux = (Pelicula*) peliculas->find(llave);
        float p = aux-> getPuntaje();
        aux->MostrarComentariosPuntajes(aux,t,p,Cant);
    }
    delete llave;
    delete i;
  }
  else{
    delete i;
    throw invalid_argument("No hay Peliculas");
  }
}

void Sistema::ListarCines(){
  system("clear");
  IIterator* i=cines->getIterator();
  if(i->hasCurrent()){
      cout << "=================LISTA CINES==================" << endl;
    while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      cout <<"Nro de Cine: " << c->getNroCine() << endl;
      cout <<"Direccion: " << c->getDir() << endl;
      cout << "==============================================" << endl;
      i->next();
    }
    delete i;
  }
  else{
    delete i;
    throw invalid_argument("No hay Cines");
  }
}

void Sistema::ListarCines(string Titulo){
  system("clear");
  IIterator* i=cines->getIterator();
  if(i->hasCurrent()){
    cout << "==========LISTA CINES=========="<<endl;
    while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      if(!c->verificarPelicula(Titulo))
      {
        cout <<"Nro de Cine: " << c->getNroCine() << endl;
        cout <<"Direccion: " << c->getDir() << endl << endl;
      }
      i->next();
    }
    delete i;
  }
  else{
    delete i;
    throw invalid_argument("No hay Cines");
  }
}

void Sistema::EliminarPelicula(string Titulo){
   StringKey* llave = new StringKey(Titulo);
   if(!peliculas->member(llave)){
     throw invalid_argument("No existe la pelicula");
     delete llave;
   }
   else{
   Pelicula* p = (Pelicula*) peliculas->find(llave);
   peliculas->remove(llave);
   cout << "Pelicula eliminada" << endl;
   delete p;
   }
}

Pelicula* Sistema::SeleccionPelicula(string Titulo){
  StringKey* llave = new StringKey(Titulo);
  if(!peliculas->member(llave)){
    delete llave;
    throw invalid_argument("No existe la película seleccionada");
  }
  Pelicula* peli = (Pelicula*) peliculas->find(llave);
  delete llave;
  return peli;
}

Cine* Sistema::SeleccionCine(int NroCine){
  Integer* llave = new Integer(NroCine);
  if(!cines->member(llave)){
    delete llave;
    throw invalid_argument("No existe el cine seleccionado");
  }
  Cine* c = (Cine*) cines->find(llave);
  delete llave;
  return c;
}

Sala* Sistema::SeleccionSala(Cine* cine, int NroSala){
  Sala* sala = cine->seleccionarSala(NroSala);
  return sala;
}

void Sistema::ListarFunciones(int NroFuncion){

}

// float Sistema::PagaCredito(string NombreFinanciera, int CantAsientos){
//
// }
//
// float Sistema::PagaDebito(string NombreBanco, int CantAsientos){
//
// }
//
// void Sistema:CrearReserva(){
//
// }
//
// void Sistema::Eliminar2(string Titulo){
//   IKey* key = new KeyInteger(Titulo);
//   ICollectible* /*F*/ = /*Funciones*/->find(key);
//   delete key;
//   if(p==NULL){
//     throw invalid_argument("No hay Peliculas");
//   }
//   /*Funciones*/->remove(key);
//   delete /*F*/;
// }
//
// void Sistema::SeleccionTitulo(string Titulo){
//
// }
