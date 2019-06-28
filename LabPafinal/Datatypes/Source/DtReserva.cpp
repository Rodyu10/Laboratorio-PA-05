#include "../Headers/DtReserva.h"

using namespace std;

DtReserva::DtReserva(){

}

DtReserva::DtReserva(int cant, float costo){
  this->CantAsientos = cant;
  this->Costo = costo;
}

int DtReserva::getCantAsientos() const{
  return this->CantAsientos;
}

float DtReserva::getCosto() const{
  return this->Costo;
}

DtReserva::~DtReserva(){
}
