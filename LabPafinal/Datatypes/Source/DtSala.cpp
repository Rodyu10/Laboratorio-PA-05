#include "../Headers/DtSala.h"

using namespace std;

DtSala::DtSala(){
}

DtSala::DtSala(int NroSala, int Capacidad){
  this->NroSala = NroSala;
  this->Capacidad = Capacidad;
}

int DtSala::getNroSala() const{
  return this->NroSala;
}

int DtSala::getCapacidad() const{
  return this->Capacidad;
}

DtSala::~DtSala(){
}
