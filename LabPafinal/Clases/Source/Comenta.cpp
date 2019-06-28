#include "../Headers/Comenta.h"

using namespace std;

Comenta::Comenta(){
}

Comenta::Comenta(string comentario, string user){
  this->comentario = comentario;
  this->users = user;
  comentariosResp = new OrderedDictionary();
  }

string Comenta::getComentario() const{
  return this->comentario;
}

string Comenta::getUsers() const{
  return this->users;
}

void Comenta::setComentario(string comentario){
  this->comentario = comentario;
}

void Comenta::ListarComentariosResp(ICollectible * obj, string c){
  if(!comentariosResp->isEmpty()){
    IIterator* i = comentariosResp->getIterator();
    if(i->hasCurrent()){
      cout<<"\t ======= Respuesta a: "<<c<<" ==========="<<endl;
      while(i->hasCurrent()){
        Comenta* com = (Comenta*) i->getCurrent();
        StringKey* llave = new StringKey (com->getComentario());
        cout <<"\t "  << com->getUsers()<< ":" << "   "<< com->getComentario() << endl;
        cout <<"\t ----------------------------------" << endl;
        Comenta* c =(Comenta*) comentariosResp->find(llave);
        c->ListarComentariosResp(c,com->getComentario());
        delete llave;
        i->next();
      }
      cout <<"\t ===== Fin de respuestas a: "<<c<<" =====" << endl;
      delete i;
    }
  }
}

void Comenta::agregarRespuesta(ICollectible* obj, string nick, string com){

  StringKey* llave = new StringKey(com);
  Comenta* c = new Comenta(com,nick);
  comentariosResp->add(llave,c);
}

Comenta* Comenta::BuscarRespuestas(ICollectible* objC, string com){
  StringKey* llave = new StringKey(com);
  if (comentariosResp->member(llave)){
    Comenta* c = (Comenta*) comentariosResp->find(llave);
    return c;
  }
  else{
    if(!comentariosResp->isEmpty()){
      IIterator* i = comentariosResp->getIterator();
      if(i->hasCurrent()){
        while(i->hasCurrent()){
          Comenta* come = (Comenta*) i->getCurrent();
          StringKey* llave = new StringKey (come->getComentario());
          Comenta* c =(Comenta*) comentariosResp->find(llave);
          Comenta* res = NULL;
          res = c->BuscarRespuestas(c,com);
          if(res != NULL){
             return res;
            }
          delete llave;
          i->next();
        }
        delete i;
      }
    }
  }
  return 0;
}

Comenta::~Comenta(){
  // ELIMINAR Comenta
}
