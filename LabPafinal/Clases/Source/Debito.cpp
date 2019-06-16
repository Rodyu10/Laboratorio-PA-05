#include "../Headers/Debito.h"

using namespace std;

Debito::Debito(){

}

Debito::Debito(int cantAsientos, float costo, string banco)
  :Reserva(cantAsientos,costo){
    this->Banco = banco;
}

/*float Debito::getCosto(){
  return this->Costo*this->CantAsientos;
}*/

string Debito::getBanco(){
  return this->Banco;
}

void Debito::setBanco(string banco){
  this->Banco = banco;
}

Debito::~Debito(){

}
