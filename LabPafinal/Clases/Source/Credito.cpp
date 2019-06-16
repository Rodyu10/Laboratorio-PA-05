#include "../Headers/Credito.h"

using namespace std;

Credito::Credito(){

}

Credito::Credito(int cantAsientos, float costo, string financiera, float desc)
  :Reserva(cantAsientos,costo){
    this->Financiera = financiera;
    this->Descuento = desc;
}

/*float Credito::getCosto(){
  return ((this->Costo*this->CantAsientos)*this->Descuento)/100;
}*/

string Credito::getFinanciera(){
  return this->Financiera;
}

float Credito::getDescuento(){
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
