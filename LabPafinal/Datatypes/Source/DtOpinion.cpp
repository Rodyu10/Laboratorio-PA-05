#include "../Headers/DtOpinion.h"

using namespace std;

DtOpinion::DtOpinion(){
}

DtOpinion::DtOpinion(float puntaje, string user){
  this->puntaje = puntaje;
  this->user = user;
}

float DtOpinion::getPuntaje() const{
  return this->puntaje;
}

string DtOpinion::getUser() const{
    return this->user;
}

DtOpinion::~DtOpinion(){
}
