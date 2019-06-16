#include "../Headers/Comenta.h"

using namespace std;

Comenta::Comenta(){
}

Comenta::Comenta(string comentario){
  this->comentario = comentario;
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
