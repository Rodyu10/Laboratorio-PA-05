#include "../Headers/DtCine.h"

using namespace std;

DtCine::DtCine(){
}

DtCine::DtCine(int NroCine, string Direccion){
  this->NroCine = NroCine;
  this->Direccion = Direccion;
}

int DtCine::getNroCine() const {
  return this->NroCine;
}

string DtCine::getDireccion() const {
  return this->Direccion;
}

DtCine::~DtCine(){
}
