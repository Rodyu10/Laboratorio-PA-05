#include "../Headers/Funcion.h"

using namespace std;

Funcion::Funcion(){

}

Funcion::Funcion(int nrofun, int nrosala, DtFecha fecha, DtHora horario){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
  reservas = new OrderedDictionary();
  peliculas = new OrderedDictionary();
  salas = new OrderedDictionary();
}

void Funcion::AsociarSalaPelicula(Sala* sala, Pelicula* peli){
  Integer* llaveSala = new Integer(sala->getNroSala());
  StringKey* llave = new StringKey(peli->getTitulo());
  salas->add(llaveSala,sala);
  peliculas->add(llave,peli);
}

int Funcion::getNroFuncion() const{
  return this->NroFuncion;
}

int Funcion::getNroSala() const{
  return this->NroSala;
}

DtFecha Funcion::getFecha() const{
  return this->Fecha;
}

DtHora Funcion::getHorario() const{
  return this->Horario;
}

void Funcion::setNroFuncion(int nrofun){
  this->NroFuncion = nrofun;
}

void Funcion::setNroSala(int nrosala){
  this->NroSala = nrosala;
}

void Funcion::setFecha(DtFecha fecha){
  this->Fecha = fecha;
}

void Funcion::setHorario(DtHora horario){
  this->Horario = horario;
}

Funcion::~Funcion(){
  // eliminar una funcion especifica de una pelicula
}
