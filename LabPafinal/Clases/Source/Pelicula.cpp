#include "../Headers/Pelicula.h"

using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->Titulo = titulo;
  this->Poster = poster;
  this->Sinopsis = sinopsis;
  this->Puntaje = puntaje;
  funciones =new OrderedDictionary();
  comentarios =new OrderedDictionary();
  opiniones =new OrderedDictionary();
}

void Pelicula::ListarComentarios(ICollectible * obj){
  IIterator* i = comentarios->getIterator();
  if(i->hasCurrent()){
    cout << "========== LISTA COMENTARIOS =========="<<endl;
    while(i->hasCurrent()){
      Comenta* com = (Comenta*) i->getCurrent();
      cout << com->getUsers()<< ": " << "   "<< com->getComentario() << endl;
      cout <<"------------------------------------------------------" << endl;
      StringKey* llave = new StringKey (com->getComentario());
      Comenta* c =(Comenta*) comentarios->find(llave);
      c->ListarComentariosResp(c,com->getComentario());
      delete llave;
      i->next();
    }
    delete i;
  }
  else{
    delete i;
    cout << endl <<  "La pelicula no tiene comentarios aun" << endl;
  }
}

ICollection* Pelicula::ListarFunciones(){
  system("clear");
  IIterator* i = funciones->getIterator();
  ICollection* res = new List();
  if(!funciones->isEmpty()){
      while(i->hasCurrent()){
        Funcion* fun = (Funcion*) i->getCurrent();
        DtFecha fechaF = fun->getFecha();
        int dia,mes,anio;
        time_t fecha = time(NULL);
        struct tm *tiempo = localtime(&fecha);
        dia = tiempo->tm_mday;
        mes = tiempo->tm_mon + 1;
        anio= tiempo->tm_year + 1900;
        DtFecha fechaActual = DtFecha(dia,mes,anio);
        if(fechaActual<fechaF){
          DtFuncion* funcion = new DtFuncion(fun->getNroFuncion(),fun->getNroSala(),fun->getFecha(),fun->getHorario());
          res->add(funcion);
        }
        i->next();
      }
      delete i;
      return res;
  }
  else{
    delete i;
    throw invalid_argument("================================================\nNo hay funciones para esta pelicula\n================================================");
  }
}

void Pelicula::agregarComentario(Pelicula * peli, string nick, string com){

  StringKey* key = new StringKey(com);
  Comenta* c = new Comenta(com,nick);
  comentarios->add(key,c);
}

ICollectible* Pelicula::buscoComentario(Pelicula* peli, string com){
  ICollectible* co = BuscarComentario(peli,com);
  return co;
}

void Pelicula::agregaCom(Pelicula* peli, Comenta* co, string nick, string com){
  co->agregarRespuesta(co, nick, com);
}

void Pelicula::AsociarFuncion(Funcion* funcion){
  Integer* llave = new Integer(funcion->getNroFuncion());
  funciones->add(llave,funcion);
}

Comenta* Pelicula::BuscarComentario(ICollectible * objP, string com){
  StringKey* llave = new StringKey(com);
  if (comentarios->member(llave)){
    Comenta* c = (Comenta*) comentarios->find(llave);
    delete llave;
    return c;
  }
  else{
    if(!comentarios->isEmpty()){
      IIterator* i = comentarios->getIterator();
      if(i->hasCurrent()){
        while(i->hasCurrent()){
          Comenta* come = (Comenta*) i->getCurrent();
          StringKey* llave = new StringKey (come->getComentario());
          Comenta* c =(Comenta*) comentarios->find(llave);
          Comenta* res = NULL;
          res = c->BuscarRespuestas(c,com);
          if(res != NULL){
             return res;
            }
          delete llave;
          i->next();
          }
          delete i;
      }
    }
    else{
      delete llave;
      return 0;
    }
  }
  return 0;
}

ICollection* Pelicula::ListarPuntajes(Pelicula* peli){
  IIterator* i= opiniones->getIterator();
  ICollection * res = new List();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      DtOpinion* o = (DtOpinion*) i->getCurrent();
      DtOpinion* op = new DtOpinion(o->getPuntaje(), o->getUser());
      res->add(op);
      i->next();
      }
      delete i;
      return res;
    }
    return 0;
}

void Pelicula::AgregarPuntaje(Pelicula* peli, string user, float puntaje){
  IIterator* i= opiniones->getIterator();
  if(i->hasCurrent()){
    while(i->hasCurrent()){
      Opinion* o = (Opinion*) i->getCurrent();
      if(o->getUser() == user){
        o->setPuntaje(puntaje);
      }
      i->next();
    }
    delete i;
    getchar();
    Opinion* op = new Opinion(puntaje,user);
    StringKey* llave = new StringKey(user);
    opiniones->add(llave,op);
  }
  else{
    getchar();
    Opinion* op = new Opinion(puntaje,user);
    StringKey* llave = new StringKey(user);
    opiniones->add(llave,op);
  }
}

ICollection* Pelicula::ObtenerFunciones(){
  IIterator* i = funciones->getIterator();
  ICollection* res = new List();
  while(i->hasCurrent()){
    Funcion* fun = (Funcion*) i->getCurrent();
    res->add(fun);
    i->next();
  }
  delete i;
  return res;
}

string Pelicula::getTitulo() const{
  return this->Titulo;
}

string Pelicula::getPoster() const{
  return this->Poster;
}

string Pelicula::getSinopsis() const{
  return this->Sinopsis;
}

float Pelicula::getPuntaje() const{
  return this->Puntaje;
}

void Pelicula::setTitulo(string titulo){
  this->Titulo = titulo;
}

void Pelicula::setPoster(string poster){
  this->Poster = poster;
}

void Pelicula::setSinopsis(string sinopsis){
  this->Sinopsis = sinopsis;
}

void Pelicula::setPuntaje(float puntaje){
  this->Puntaje = puntaje;
}

ICollection* Pelicula::ObtenerComentarios(Pelicula * peli){
  IIterator* i = comentarios->getIterator();
  ICollection* res = new List();
  while(i->hasCurrent()){
    Comenta* com = (Comenta*) i->getCurrent();
    res->add(com);
    i->next();
  }
  delete i;
  return res;
}

void Pelicula::EliminarPelicula(Pelicula* peli){
  ICollection* ListaOpi = peli->ListarPuntajes(peli);
  if(ListaOpi != NULL){
    IIterator* i = ListaOpi->getIterator();
    while(i->hasCurrent()){
      Opinion* o = (Opinion*) i->getCurrent();
      StringKey* llave = new StringKey(o->getUser());
      opiniones->remove(llave);
      i->next();
    }
    delete i;
  }
  ICollection* ListaCom = peli->ObtenerComentarios(peli);
  if (ListaCom != NULL){
    IIterator* i = ListaCom->getIterator();
    while(i->hasCurrent()){
      Comenta* com = (Comenta*) i->getCurrent();
      StringKey* llave = new StringKey (com->getComentario());
      Comenta* c =(Comenta*) comentarios->find(llave);
      comentarios->remove(llave);
      c->EliminoComentariosResp(c,com->getComentario());
      delete llave;
      i->next();
    }
    delete i;
  }
}

Pelicula::~Pelicula(){
  IIterator* i = funciones->getIterator();
  IIterator* ii = comentarios->getIterator();
  IIterator* iii = opiniones->getIterator();
  if (i->hasCurrent()) {
    while(i->hasCurrent()){
        Funcion* f = (Funcion*) i->getCurrent();
        delete f;
        i->next();
    }
  }
  if(iii->hasCurrent()){
    while(iii->hasCurrent()){
        Opinion* o = (Opinion*) iii->getCurrent();
        delete o;
        iii->next();
    }
  }
  while(ii->hasCurrent()){
      Comenta* c = (Comenta*) ii->getCurrent();
      delete c;
      ii->next();
  }
  delete i;
  delete ii;
  delete iii;
  delete funciones;
  delete opiniones;
  delete comentarios;
}
