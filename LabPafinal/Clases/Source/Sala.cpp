#include "../Headers/Sala.h"

using namespace std;

Sala::Sala(){
}

Sala::Sala(int NroSala, int Capacidad){
  this->NroSala = NroSala;
  this->Capacidad = Capacidad;
}

int Sala::getNroSala() const{
  return this->NroSala;
}

int Sala::getCapacidad() const{
  return this->Capacidad;
}


void Sala::setNroSala(int NroSala){
  this->NroSala = NroSala;
}

void Sala::setCapacidad(int Capacidad){
  this->Capacidad = Capacidad;
}


Sala::~Sala(){
}
