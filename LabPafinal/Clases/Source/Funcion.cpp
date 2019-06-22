#include "../Headers/Funcion.h"

using namespace std;

Funcion::Funcion(){

}

Funcion::Funcion(int nrofun, int nrosala, DtFecha fecha, DtHora horario, Pelicula* pelicula){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
  this->pelicula = pelicula;
  reservas = new OrderedDictionary();
  salas = new OrderedDictionary();
}

void Funcion::AsociarSala(Sala* sala){
  Integer* llaveSala = new Integer(sala->getNroSala());
  salas->add(llaveSala,sala);
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

Pelicula* Funcion::getPelicula() const{
  return this->pelicula;
}

void Funcion::setPelicula(Pelicula* peli){
  this->pelicula = peli;
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
