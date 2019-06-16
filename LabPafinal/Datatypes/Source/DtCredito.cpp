#include "../Headers/DtCredito.h"

using namespace std;

DtCredito::DtCredito(){

}

DtCredito::DtCredito(int cantAsientos, float costo, string financiera, float desc)
  :DtReserva(cantAsientos,costo){
    this->Financiera = financiera;
    this->Descuento = desc;
}

/*float Credito::getCosto(){
  return ((this->Costo*this->CantAsientos)*this->Descuento)/100;
}*/

string DtCredito::getFinanciera(){
  return this->Financiera;
}

float DtCredito::getDescuento(){
  return this->Descuento;
}

DtCredito::~DtCredito(){

}
