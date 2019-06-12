#include <iostream>
#include <stdlib.h>

#include "../Headers/DtComenta.h"

using namespace std;

DtComenta::DtComenta(){
}

DtComenta::DtComenta(string comentario){
  this->comentario = comentario;
}

DtComenta DtComenta::getComentario() const{
   return DtComenta(this->comentario);
}

string DtComenta::getComentario() const{
  return this->comentario;
}

DtComenta::~DtComenta(){
  // ELIMINAR comentario
}
