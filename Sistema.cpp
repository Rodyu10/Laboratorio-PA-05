#include "../Headers/Sistema.h"

using namespace std;

Sistema::Sistema(){
  usuarios=new OrderedDictionary();
  cines=new OrderedDictionary();
  peliculas=new OrderedDictionary();
}

Sistema* Sistema::instance = nullptr;

Sistema* Sistema::getInstance(){
    if(instance == nullptr){
      instance = new Sistema();
    }
    return instance;
}

bool Sistema::esAdmin(string nick){
  StringKey* llave = new StringKey(nick);
  if(usuarios->member(llave)){
    Usuario* u = (Usuario*) usuarios->find(llave);
    if(u->getNick() =="root"){
      return true;
    }
    else{
      delete u;
      throw invalid_argument("El usuario no tiene permiso para acceder a esta funcion");
    }
  }
  return 0;
}

void Sistema::RegistrarUsuario(string nickname, string fotodeperfil, string pass){
 StringKey* llave = new StringKey(nickname);
 if(!usuarios->member(llave)){
   Usuario* u=new Usuario(nickname,fotodeperfil,pass);
   usuarios->add(llave,u);
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
      return true;
    }
    else{
      throw invalid_argument("Password incorrecto");
    }
  }
  else{
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
  }
  else{
    throw invalid_argument("El nro de cine ya existe");
  }
}

void Sistema::AltaPelicula(string tit, string pos, string sinop, float puntaj){
  StringKey* llave = new StringKey(tit);
  if(!peliculas->member(llave)){
    Pelicula* p=new Pelicula(tit,pos,sinop,puntaj);
    peliculas->add(llave,p);
  }
  else{
    throw invalid_argument("La pelicula ya existe");
  }
}

 void Sistema::ListarTitulos(){
   IIterator* i=peliculas->getIterator();
   if(i->hasCurrent()){
     while(i->hasCurrent()){
       Pelicula* p = (Pelicula*) i->getCurrent();
       cout << p->getTitulo() << endl;
       cout <<"-----------------" << endl;
       i->next();
     }
     delete i;
   }
   else{
     throw invalid_argument("No hay Peliculas");
   }
}

void Sistema::ListarCines(){
  IIterator* i=cines->getIterator();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      cout <<"Nro de Cine: " << c->getNroCine() << endl;
      cout <<"Direccion: " << c->getDir() << endl;
      cout <<"-----------------" << endl;
      i->next();
    }
    delete i;
  }
  else{
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

// void Sistema::SeleccionPelicula(Pelicula::Titulo){
//
// }

// void Sistema::SeleccionCine(Cine::NroCine){
//
// }

// void Sistema::ListarFunciones(Funcion::NroFuncion){
//
// }

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
