#include "../Headers/DtComenta.h"

using namespace std;

DtComenta::DtComenta(){
}

DtComenta::DtComenta(string comentario){
  this->comentario = comentario;
}

string DtComenta::getComentario() const{
  return this->comentario;
}

DtComenta::~DtComenta(){
}
