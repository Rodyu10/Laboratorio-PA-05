#include "../Headers/Sala.h"

using namespace std;

Sala::Sala(){
}

Sala::Sala(int NroSala, int Capacidad, bool ocupado){
  this->NroSala = NroSala;
  this->Capacidad = Capacidad;
  this->Ocupado = ocupado;
}


DtSala Sala::getSala() const{
   return DtSala(this->NroSala, this->Capacidad);
}

int Sala::getNroSala() const{
  return this->NroSala;
}

int Sala::getCapacidad() const{
  return this->Capacidad;
}

bool Sala::getOcupado() const{
  return this->Ocupado;
}

void Sala::setNroSala(int NroSala){
  this->NroSala = NroSala;
}

void Sala::setCapacidad(int Capacidad){
  this->Capacidad = Capacidad;
}

void Sala::setOcupado(bool ocupado){
  this->Ocupado = ocupado;
}

Sala::~Sala(){
  // ELIMINAR Sala
}
