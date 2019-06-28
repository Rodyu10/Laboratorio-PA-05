#include "../Headers/DtPelicula.h"

using namespace std;

DtPelicula::DtPelicula(){
}

DtPelicula::DtPelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->Titulo = titulo;
  this->Poster = poster;
  this->Sinopsis = sinopsis;
  this->Puntaje = puntaje;
}

string DtPelicula::getTitulo() const{
  return this->Titulo;
}

string DtPelicula::getPoster() const{
  return this->Poster;
}

string DtPelicula::getSinopsis() const{
  return this->Sinopsis;
}

float DtPelicula::getPuntaje() const{
  return this->Puntaje;
}

DtPelicula::~DtPelicula(){
}
