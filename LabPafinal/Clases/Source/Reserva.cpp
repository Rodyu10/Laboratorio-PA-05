#include <iostream>
#include <stdlib.h>

#include "../Headers/Reserva.h"

using namespace std;

Reserva::Reserva(){

}

Reserva::Reserva(int cant, float costo){
  this->CantAsientos = cant;
  this->Costo = costo;
}

/*Reserva::Reserva create(){

}
Reserva::Reserva add(){

}*/

int Reserva::getCantAsientos() const{
  return this->CantAsientos;
}

float Reserva::getCosto() const{
  return this->Costo;
}

void Reserva::setCantAsientos(int cant){
  this->CantAsientos = cant;
}

void Reserva::setCosto(float costo) {
    this->Costo = costo;
}

Reserva::~Reserva(){
  // eliminar reserva de una funcion y peli especifica ?
}
