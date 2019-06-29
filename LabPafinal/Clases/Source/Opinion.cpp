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

string Opinion::getUser() const{
    return this->user;
}

void Opinion::setPuntaje(float puntaje){
  this->puntaje = puntaje;
}

void Opinion::setUser(string user){
  this->user = user;
}

Opinion::~Opinion(){

}
