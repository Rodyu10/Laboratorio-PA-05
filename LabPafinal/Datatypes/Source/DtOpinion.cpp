#include <iostream>
#include <stdlib.h>

#include "../Headers/DtOpinion.h"

using namespace std;

DtOpinion::DtOpinion(){
}

DtOpinion::DtOpinion(float puntaje){
  this->puntaje = puntaje;
}

DtOpinion DtOpinion::getPuntaje() const{
   return DtOpinion(this->puntaje);
}

float DtOpinion::getPuntaje() const{
  return this->puntaje;
}

DtOpinion::~DtOpinion(){
  // ELIMINAR opinion
}
