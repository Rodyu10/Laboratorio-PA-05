#include "../Headers/DtDebito.h"

using namespace std;

DtDebito::DtDebito(){
}

DtDebito::DtDebito(int cantAsientos, float costo, Usuario* user, string banco)
  :DtReserva(cantAsientos,costo, user){
    this->Banco = banco;
}

string DtDebito::getBanco() const{
  return this->Banco;
}

DtDebito::~DtDebito(){
}
