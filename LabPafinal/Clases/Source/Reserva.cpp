#include "../Headers/Reserva.h"

using namespace std;

Reserva::Reserva(){
}

Reserva::Reserva(int cant, float costo, Usuario* user){
  this->CantAsientos = cant;
  this->Costo = costo;
  this->user = user;
}

int Reserva::getCantAsientos() const{
  return this->CantAsientos;
}

float Reserva::getCosto() const{
  return this->Costo;
}

Usuario* Reserva::getUsuario() const{
  return this->user;
}

void Reserva::setCantAsientos(int cant){
  this->CantAsientos = cant;
}

void Reserva::setCosto(float costo) {
    this->Costo = costo;
}

void Reserva::setUsuario(Usuario* user){
  this->user = user;
}

Reserva::~Reserva(){
}
