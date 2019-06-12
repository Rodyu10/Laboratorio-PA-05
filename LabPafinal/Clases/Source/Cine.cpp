#include <iostream>
#include <stdlib.h>

#include "../Headers/Cine.h"

using namespace std;

Cine::Cine(){

}

Cine::Cine(int nro, string dir){
  this->NroCine = nro;
  this->Dir = dir;
}

/*list Cine::getListaCines(){
  // MUESTRA TODOS LOS CINES
}*/
DtCine Cine::getCine() const{
  return DtCine (this->NroCine,this->Dir);
}

int Cine::getNroCine() const{
  return this->NroCine;
}

string Cine::getDir() const{
  return this->Dir;
}

void Cine::setNroCine(int nro){
  this->NroCine = nro;
}

void Cine::setDir(string dir){
  this->Dir = dir;
}

Cine::~Cine(){

}
