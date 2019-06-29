#include "../Headers/DtFinanciera.h"

using namespace std;

DtFinanciera::DtFinanciera(){
}

DtFinanciera::DtFinanciera(string financiera, float desc){
    this->Financiera = financiera;
    this->Descuento = desc;
}

string DtFinanciera::getFinanciera() const{
  return this->Financiera;
}

float DtFinanciera::getDescuento() const{
  return this->Descuento;
}

DtFinanciera::~DtFinanciera(){
}
