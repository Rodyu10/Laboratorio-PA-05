#include "../Headers/DtReserva.h"

using namespace std;

DtReserva::DtReserva(){

}

DtReserva::DtReserva(int cant, float costo){
  this->CantAsientos = cant;
  this->Costo = costo;
}

/*Reserva::Reserva create(){

}
Reserva::Reserva add(){

}*/

int DtReserva::getCantAsientos() const{
  return this->CantAsientos;
}

float DtReserva::getCosto() const{
  return this->Costo;
}

DtReserva::~DtReserva(){
  // eliminar reserva de una funcion y peli especifica ?
}
