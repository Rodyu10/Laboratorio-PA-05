#include "../Headers/DtHora.h"

using namespace std;

DtHora::DtHora(){
}

DtHora::DtHora(int horas, int minutos, int segundos){
  this->Hora = horas;
  this->Minutos = minutos;
  this->Segundos = segundos;
}

int DtHora::getHora() const {
  return this->Hora;
}

int DtHora::getMinutos() const {
  return this->Minutos;
}

int DtHora::getSegundos() const {
  return this->Segundos;
}

DtHora::~DtHora(){
}
