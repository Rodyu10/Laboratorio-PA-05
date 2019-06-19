#include "../Headers/Cine.h"

using namespace std;

Cine::Cine(){

}

Cine::Cine(int nro, string dir){
  this->NroCine = nro;
  this->Dir = dir;
}

void Cine::agregarSalas(int nro, int cap){
  cout << " AACAAAAAA" << endl;
    Integer* llave = new Integer(nro);
    if(!salas->member(llave)){
      cout << " AACAAAAAA2222" << endl;
      Sala* s = new Sala(nro,cap);
      salas->add(llave,s);
      cout << " AACAAAAA45454545554A" << endl;
    }
    else{
      throw invalid_argument ("La sala ya existe");
    }
}

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
