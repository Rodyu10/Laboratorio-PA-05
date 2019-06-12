#include <iostream>
#include <stdlib.h>

#include "../Headers/Comenta.h"

using namespace std;

Comenta::Comenta(){
}

Comenta::Comenta(string comentario){
  this->comentario = comentario;
  }


DtComenta Comenta::getComentario() const{
   return DtComenta(this->comentario);
}

string Comenta::getComentario() const{
  return this->comentario;
}

void Comenta::setComentario(string comentario){
  this->comentario = comentario;
}

Comenta::~Comenta(){
  // ELIMINAR Comenta
}
