#include "../Headers/Credito.h"

using namespace std;

Credito::Credito(){

}

Credito::Credito(int cantAsientos, float costo, Usuario* user, string financiera, float desc)
  :Reserva(cantAsientos,costo, user){
    this->Financiera = financiera;
    this->Descuento = desc;
}

string Credito::getFinanciera() const{
  return this->Financiera;
}

float Credito::getDescuento() const{
  return this->Descuento;
}

void Credito::setFinanciera(string f){
  this->Financiera = f;
}

void Credito::setDescuento(float desc){
  this->Descuento = desc;
}

Credito::~Credito(){
}
