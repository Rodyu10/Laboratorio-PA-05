#include <iostream>
#include <stdlib.h>

#include "../Headers/DtSala.h"

using namespace std;

DtSala::DtSala(){
}

DtSala::DtSala(int NroSala, int Capacidad){
  this->NroSala = NroSala;
  this->Capacidad = Capacidad;
}

DtSala DtSala::getNroSala() const{
   return DtSala(this->NroSala, this->Capacidad);
}

int DtSala::getNroSala() const{
  return this->NroSala;
}

int DtSala::getCapacidad() const{
  return this->Capacidad;
}

DtSala::~DtSala(){
  // ELIMINAR Sala
}
