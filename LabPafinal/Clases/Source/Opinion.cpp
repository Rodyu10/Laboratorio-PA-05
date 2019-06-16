#include "../Headers/Opinion.h"

using namespace std;

Opinion::Opinion(){
}

Opinion::Opinion(float puntaje){
  this->puntaje = puntaje;
  }

float Opinion::getPuntaje() const{
  return this->puntaje;
}

void Opinion::setPuntaje(float puntaje){
  this->puntaje = puntaje;
}

Opinion::~Opinion(){
  // ELIMINAR Opinion
}
