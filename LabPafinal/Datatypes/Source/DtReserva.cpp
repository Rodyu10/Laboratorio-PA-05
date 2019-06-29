#include "../Headers/DtReserva.h"

using namespace std;

DtReserva::DtReserva(){

}

DtReserva::DtReserva(int cant, float costo, Usuario* user){
  this->CantAsientos = cant;
  this->Costo = costo;
  this->user = user;
}

int DtReserva::getCantAsientos() const{
  return this->CantAsientos;
}

float DtReserva::getCosto() const{
  return this->Costo;
}

DtReserva::~DtReserva(){
}
