#include "../Headers/Financiera.h"

using namespace std;

Financiera::Financiera(){
}

Financiera::Financiera(string financiera, float desc){
    this->financiera = financiera;
    this->Descuento = desc;
}

string Financiera::getFinanciera() const{
  return this->financiera;
}

float Financiera::getDescuento() const{
  return this->Descuento;
}

void Financiera::setFinanciera(string f){
  this->financiera = f;
}

void Financiera::setDescuento(float desc){
  this->Descuento = desc;
}

Financiera::~Financiera(){
}
