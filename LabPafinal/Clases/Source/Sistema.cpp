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
  Cine* c1=new Cine(1,180,"Alvariza");
  Integer* intllave = new Integer(c1->getNroCine());
  cines->add(intllave,c1);
  Cine *c2=new Cine(2,250,"Movie Portones");
  intllave = new Integer(c2->getNroCine());
  cines->add(intllave,c2);
  Cine* c3=new Cine(3,300,"LifeCinemas");
  intllave = new Integer(c3->getNroCine());
  cines->add(intllave,c3);

  Pelicula* p=new Pelicula("Toy Story 4",
  "https://toystoryposter.com/images/toystory.jpg","Woody siempre ha tenido claro cuál es su labor\nen el mundo, y cuál es su prioridad: cuidar a\nsu dueño, ya sea Andy o Bonnie. Pero cuando Bonnie\nañade Forky, un nuevo y reluciente juguete a su\nhabitación, arranca una nueva aventura que servirá\npara que los viejos y nuevos amigos le enseñen a Woody\nlo grande que puede ser el mundo para un juguete.",0);
  StringKey* llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c1->agregarPelicula(p->getTitulo(),p);
  p=new Pelicula("Toy Story 4",
  "https://toystoryposter.com/images/toystory.jpg","Woody siempre ha tenido claro cuál es su labor\nen el mundo, y cuál es su prioridad: cuidar a\nsu dueño, ya sea Andy o Bonnie. Pero cuando Bonnie\nañade Forky, un nuevo y reluciente juguete a su\nhabitación, arranca una nueva aventura que servirá\npara que los viejos y nuevos amigos le enseñen a Woody\nlo grande que puede ser el mundo para un juguete.",0);
  llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c2->agregarPelicula(p->getTitulo(),p);
  p=new Pelicula("John Wick","https://johnposter.com/images/johnwick.jpg","La ciudad de Nueva York se convierte en el patio\nacribillado a balazos de un exasesino mientras él elimina\na los gánsteres que destruyeron todo lo que él quería.",0);
  llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c2->agregarPelicula(p->getTitulo(),p);
  p=new Pelicula("Chuky","https://chukyposter.com/images/chuky.jpg","Mediante un ritual de vudú, el alma de un asesino\nmoribundo trasmigra a un muñeco. Una madre compra el\nmuñeco para su hijo, sin saber que está arrojando a sus\nhijos a los brazos de un ser infernal.",0);
  llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c1->agregarPelicula(p->getTitulo(),p);
  p=new Pelicula("Chuky","https://chukyposter.com/images/chuky.jpg","Mediante un ritual de vudú, el alma de un asesino\nmoribundo trasmigra a un muñeco. Una madre compra el\nmuñeco para su hijo, sin saber que está arrojando a sus\nhijos a los brazos de un ser infernal.",0);
  llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c2->agregarPelicula(p->getTitulo(),p);
  p=new Pelicula("Chuky","https://chukyposter.com/images/chuky.jpg","Mediante un ritual de vudú, el alma de un asesino\nmoribundo trasmigra a un muñeco. Una madre compra el\nmuñeco para su hijo, sin saber que está arrojando a sus\nhijos a los brazos de un ser infernal.",0);
  llave = new StringKey(p->getTitulo());
  peliculas->add(llave,p);
  c3->agregarPelicula(p->getTitulo(),p);

  c1->agregarSalas(1,50);
  c1->agregarSalas(2,40);
  c2->agregarSalas(1,66);
  c2->agregarSalas(2,33);
  c2->agregarSalas(3,55);
  c3->agregarSalas(1,60);

  c1->agregarFinanciera("Citibank",10);
  c1->agregarFinanciera("ITAU",50);

  c2->agregarFinanciera("BROU",20);
  c2->agregarFinanciera("Scotia",15);
  c2->agregarFinanciera("ITAU",50);

  c3->agregarFinanciera("Santander",30);

  Usuario* u=new Usuario("root","123","123");
  StringKey* user = new StringKey(u->getNick());
  usuarios->add(user,u);
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

int Sistema::CantCines(){
  return cines->getSize();
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

Pelicula* Sistema::verificarPelicula(string Titulo){
  StringKey* llave = new StringKey(Titulo);
  if(peliculas->member(llave)){
    Pelicula* peli = (Pelicula*) peliculas->find(llave);
    delete llave;
    return peli;
  }
  else{
    delete llave;
    return nullptr;
  }
}
