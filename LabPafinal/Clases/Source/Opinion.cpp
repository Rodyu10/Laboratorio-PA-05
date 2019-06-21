#include "../Headers/Opinion.h"

using namespace std;

Opinion::Opinion(){
}

Opinion::Opinion(float puntaje, string u){
  this->puntaje = puntaje;
  this->user = u;
  }

float Opinion::getPuntaje() const{
  return this->puntaje;
}

string Opinion::getUser(){
    return this->user;
}

void Opinion::setPuntaje(float puntaje){
  this->puntaje = puntaje;
}

Opinion::~Opinion(){
  // ELIMINAR Opinion
}
