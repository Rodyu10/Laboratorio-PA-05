#include "../Headers/Pelicula.h"

using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->Titulo = titulo;
  this->Poster = poster;
  this->Sinopsis = sinopsis;
  this->Puntaje = puntaje;
  comentarios =new OrderedDictionary();
}

void Pelicula::ListarComentarios(ICollectible * obj){
  IIterator* i = comentarios->getIterator();
  if(i->hasCurrent()){
    cout << "==========LISTA COMENTARIOS=========="<<endl;
    while(i->hasCurrent()){
      Comenta* com = (Comenta*) i->getCurrent();
      cout <<"Comentario: "<< com->getComentario() << endl;
      cout <<"-----------------" << endl;
      i->next();
    }
    delete i;
  }
  else{
    cout << "La pelicula no tiene comentarios aun" << endl;
  }
}

void Pelicula::agregarComentario(ICollectible * obj){
  string com;
  cout <<"Elija un comentario si lo desea, de lo contrario presione 'N' " << endl;
  cin >> com;
  StringKey* llave = new StringKey(com);
  if(com == "N" || com == "n"){
    cout << "Ingrese un nuevo comentario" << endl;
    cin >> com;
    StringKey* key = new StringKey(com);
    Comenta* c = new Comenta(com);
    comentarios->add(key,c);
    cout << "Comentario agregado" << endl;
  }
  else {
    if(comentarios->member(llave)){
    Comenta* c = (Comenta*) comentarios->find(llave);
    c->agregarRespuesta(c);
    }
    else{
      cout << "Comentario incorrecto" << endl;
    }
  }
}

DtPelicula Pelicula::getPelicula() const{
   return DtPelicula(this->Titulo, this->Poster, this->Sinopsis, this->Puntaje);
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

Pelicula::~Pelicula(){
  // ELIMINAR PELICULA FUNCION
}
