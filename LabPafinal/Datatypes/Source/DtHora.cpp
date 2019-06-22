#include "../Headers/DtHora.h"

using namespace std;

DtHora::DtHora(){
}

DtHora::DtHora(int horas, int minutos){
  this->Hora = horas;
  this->Minutos = minutos;
}

int DtHora::getHora() const {
  return this->Hora;
}

int DtHora::getMinutos() const {
  return this->Minutos;
}

bool DtHora::operator==(DtHora hora){
    if(this->Hora==hora.getHora() && this->Minutos==hora.getMinutos())
    return true;
    else
    return false;
}

DtHora::~DtHora(){
}
