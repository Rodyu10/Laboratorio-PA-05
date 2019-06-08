#include <iostream>
#include <stdlib.h>

#include "../Headers/Funcion.h"

using namespace std;

Funcion::Funcion(){

}

Funcion::Funcion(int nrofun, int nrosala, DtFecha fecha, int horario){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
}

/*list Funcion::getListaFunciones(){

}*/

DtFuncion Funcion::getFuncion() const{
  return DtFuncion (this->NroFuncion,this->NroSala,this->Fecha,this->Horario);
}

int Funcion::getNroFuncion(){
  return this->NroFuncion;
}

int Funcion::getNroSala(){
  return this->NroSala;
}

DtFecha Funcion::getFecha(){
  return this->Fecha;
}

int Funcion::getHorario(){
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

void Funcion::setHorario(int horario){
  this->Horario = horario;
}

Funcion::~Funcion(){
  // eliminar una funcion especifica de una pelicula
}
