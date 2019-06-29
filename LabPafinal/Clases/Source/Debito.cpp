#include "../Headers/Debito.h"

using namespace std;

Debito::Debito(){

}

Debito::Debito(int cantAsientos, float costo, Usuario* user, string banco)
  :Reserva(cantAsientos,costo, user){
    this->Banco = banco;
}

string Debito::getBanco(){
  return this->Banco;
}

void Debito::setBanco(string banco){
  this->Banco = banco;
}

Debito::~Debito(){
}
