#include "../Headers/DtCredito.h"

using namespace std;

DtCredito::DtCredito(){
}

DtCredito::DtCredito(int cantAsientos, float costo, Usuario* user, string financiera, float desc)
  :DtReserva(cantAsientos,costo, user){
    this->Financiera = financiera;
    this->Descuento = desc;
}

string DtCredito::getFinanciera() const{
  return this->Financiera;
}

float DtCredito::getDescuento() const{
  return this->Descuento;
}

DtCredito::~DtCredito(){
}
