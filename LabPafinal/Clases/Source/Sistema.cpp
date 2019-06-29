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
      instance->Precarga();
    }
    return instance;
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
      delete llave;
      return true;
    }
    else{
      delete llave;
      return false;
    }
  }
  else{
    delete llave;
    throw invalid_argument("El usuario es incorrecto");
  }
}

void Sistema::AltaCine(Cine* cine){
  Integer* llave = new Integer(cine->getNroCine());
  cines->add(llave,cine);
}

void Sistema::Control(){
  if(cines->isEmpty()){
    throw invalid_argument("Aun no hay cines ingresados");
  }
}

void Sistema::ComentarPelicula(Pelicula* peli, string nick, string com){

  peli->agregarComentario(peli, nick, com);

}

void Sistema::agregarCom(Pelicula* peli, Comenta* co, string nick, string com){

  peli->agregaCom(peli, co, nick, com);

}

void Sistema::PuntuarPelicula(Pelicula* peli, string user, float puntaje){

  peli->AgregarPuntaje(peli, user, puntaje);

}

void Sistema::AltaPelicula(string Titulo, string Poster, string Sinopsis, int NroCine){
  Integer* intllave = new Integer(NroCine);
  StringKey* llave = new StringKey(Titulo);
  Pelicula* p = new Pelicula(Titulo,Poster,Sinopsis,0);
  if(!peliculas->member(llave)){
    peliculas->add(llave,p);
  }
  Cine* cine = (Cine*) cines->find(intllave);
  cine->agregarPelicula(Titulo,p);
  delete intllave;
}

void Sistema::Precarga(){
  Cine* c1=new Cine(1,300,"Alvariza");
  Integer* intllave = new Integer(c1->getNroCine());
  cines->add(intllave,c1);
  Cine *c2=new Cine(2,250,"PuntaShopping");
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
  c1->agregarFinanciera("BROU",20);
  c1->agregarFinanciera("Scotia",15);
}

ICollection* Sistema::ListarPeliculas(){
  system("clear");
  IIterator* i=peliculas->getIterator();
  ICollection * res = new List();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      Pelicula* p = (Pelicula*) i->getCurrent();
      DtPelicula* peli = new DtPelicula(p->getTitulo(),p->getPoster(),p->getSinopsis(),p->getPuntaje());
      res->add(peli);
      i->next();
    }
    delete i;
    return res;
  }
  else{
    delete i;
    throw invalid_argument("No hay peliculas registradas");
  }
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

ICollection* Sistema::ListarCines(string titulo){
  system("clear");
  IIterator* i=cines->getIterator();
  ICollection * res = new List();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      if(!c->verificarPelicula(titulo)){
        DtCine* cine = new DtCine(c->getNroCine(),c->getDir());
        res->add(cine);
      }
      i->next();
    }
    delete i;
    return res;
  }
  else{
    delete i;
    throw invalid_argument("No hay cines registrados");
  }
}

ICollection* Sistema::ListarCines(){
  system("clear");
  IIterator* i=cines->getIterator();
  ICollection * res = new List();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      DtCine* cine = new DtCine(c->getNroCine(),c->getDir());
      res->add(cine);
      i->next();
    }
    delete i;
    return res;
  }
  else{
    delete i;
    throw invalid_argument("No hay cines registrados");
  }
}

void Sistema::EliminarPelicula(Pelicula* peli){

 StringKey* llave = new StringKey(peli->getTitulo());
 peliculas->remove(llave);
 IIterator* i = cines->getIterator();
 while(i->hasCurrent()){
      Cine* c = (Cine*) i->getCurrent();
      if(c->verificarPelicula(peli->getTitulo())){
        c->EliminarPelicula(peli);
      }
      i->next();
     }
   delete i;
}

Pelicula* Sistema::SeleccionPelicula(string Titulo){
  StringKey* llave = new StringKey(Titulo);
  if(!peliculas->member(llave)){
    delete llave;
    throw invalid_argument("\nNo existe la película seleccionada");
  }
  Pelicula* peli = (Pelicula*) peliculas->find(llave);
  delete llave;
  return peli;
}

Cine* Sistema::SeleccionCine(int NroCine){
  Integer* llave = new Integer(NroCine);
  if(!cines->member(llave)){
    delete llave;
    throw invalid_argument("\nNo existe el cine seleccionado");
  }
  Cine* c = (Cine*) cines->find(llave);
  delete llave;
  return c;
}

Funcion* Sistema::SeleccionFuncion(Cine* cine, int NroFuncion){
 return cine->seleccionarFuncion(NroFuncion);
}

Usuario* Sistema::obtenerUsuario(string nick){
  StringKey* llave = new StringKey(nick);
  Usuario* user = (Usuario*) usuarios->find(llave);
  return user;
}
