#include <iostream>
#include <stdlib.h>

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

/*list Pelicula::getListaPeliculas(){
  // MUESTRA TODAS LAS PELICULAS
}*/

DtPelicula DtPelicula::getPelicula() const{
   return DtPelicula(this->Titulo, this->Poster, this->Sinopsis, this->Puntaje);
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
  // ELIMINAR PELICULA FUNCION
}
