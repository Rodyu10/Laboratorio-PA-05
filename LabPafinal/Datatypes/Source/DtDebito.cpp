#include "../Headers/DtDebito.h"

using namespace std;

DtDebito::DtDebito(){

}

DtDebito::DtDebito(int cantAsientos, float costo, string banco)
  :DtReserva(cantAsientos,costo){
    this->Banco = banco;
}

/*float Debito::getCosto(){
  return this->Costo*this->CantAsientos;
}*/

string DtDebito::getBanco(){
  return this->Banco;
}

DtDebito::~DtDebito(){

}
