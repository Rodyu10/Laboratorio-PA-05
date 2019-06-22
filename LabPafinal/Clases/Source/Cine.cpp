#include "../Headers/Cine.h"

using namespace std;

Cine::Cine(){
}

Cine::Cine(int nro, string dir){
  this->NroCine = nro;
  this->Dir = dir;
  salas = new OrderedDictionary();
  funciones = new OrderedDictionary();
  peliculas = new OrderedDictionary();
}

void Cine::agregarSalas(int nro, int cap){
    Integer* llave = new Integer(nro);
    if(!salas->member(llave)){
      Sala* s = new Sala(nro,cap,false);
      salas->add(llave,s);
    }
    else{
      delete llave;
      throw invalid_argument ("La sala ya existe");
    }
}

void Cine::listarSalas(){
    IIterator* i = salas->getIterator();
    cout << "=================LISTA SALAS================"<<endl;
    while(i->hasCurrent()){
      Sala* s = (Sala*) i->getCurrent();
      cout << "Nro de Sala: " << s->getNroSala() << endl;
      cout << "Capacidad de Sala: " << s->getCapacidad() << endl;
      if(s->getOcupado())
      cout << "Estado: sala ocupada" << endl;
      else
      cout << "Estado: sala desocupada" << endl;
      cout << "============================================"<<endl;
      i->next();
    }
    delete i;
}

Sala* Cine::seleccionarSala(int NroSala){
  Integer* llave = new Integer(NroSala);
  if(!salas->member(llave)){
    delete llave;
    throw invalid_argument("Este cine no contiene este numero de sala");
  }
  Sala* sala = (Sala*) salas->find(llave);
  delete llave;
  return sala;
}

void Cine::agregarPelicula(string Titulo, ICollectible* peli){
  StringKey* llave = new StringKey(Titulo);
  if(!peliculas->member(llave)){
      peliculas->add(llave,peli);
  }
  else
  {
    delete llave;
    throw invalid_argument("Este cine ya contiene esta pelicula");
  }
}

void Cine::agregarFuncion(Pelicula* peli, int NroFuncion, int NroSala, DtFecha *fecha, DtHora *hora){
  Integer* llave = new Integer(NroFuncion);
  if(!funciones->member(llave)){
    Integer* llaveSala = new Integer(NroSala);
    Sala* sala = (Sala*) salas->find(llaveSala);
    if(!sala->getOcupado()){
        sala->setOcupado(true);
        DtFecha f = DtFecha(fecha->getDia(),fecha->getMes(),fecha->getAnio());
        DtHora h = DtHora(hora->getHora(),hora->getMinutos(),hora->getSegundos());
        Funcion* fun = new Funcion(NroFuncion,NroSala,f,h,peli);
        fun->AsociarSala(sala);
        fun->setPelicula(peli);
        funciones->add(llave,fun);
        cout << "Funcion agregada exitosamente" << endl << endl;
    }
    else{
      delete llave;
      throw invalid_argument("Esta sala esta ocupada");
    }
  }
  else{
    delete llave;
    throw invalid_argument("Ya existe una funcion con ese numero registrado");
  }
}

bool Cine::verificarPelicula(string Titulo){
  StringKey* llave = new StringKey(Titulo);
  if(!peliculas->member(llave)){
    delete llave;
    return true;
  }
  else{
    delete llave;
    return false;
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
