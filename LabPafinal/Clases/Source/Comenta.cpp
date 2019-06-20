#include "../Headers/Comenta.h"

using namespace std;

Comenta::Comenta(){
}

Comenta::Comenta(string comentario){
  this->comentario = comentario;
  comentariosResp = new OrderedDictionary();
  }

string Comenta::getComentario() const{
  return this->comentario;
}

void Comenta::setComentario(string comentario){
  this->comentario = comentario;
}

void Comenta::agregarRespuesta(ICollectible* obj){
  string com;
  cout << "Ingrese la respuesta al comentario seleccionado" << endl;
  cin >> com;
  StringKey* llave = new StringKey(com);
  Comenta* c = new Comenta(com);
  comentariosResp->add(llave,c);
  cout << "Respuesta agregada" << endl;
}

Comenta::~Comenta(){
  // ELIMINAR Comenta
}
