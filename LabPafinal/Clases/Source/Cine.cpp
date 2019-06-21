#include "../Headers/Cine.h"

using namespace std;

Cine::Cine(){
}

Cine::Cine(int nro, string dir){
  this->NroCine = nro;
  this->Dir = dir;
  salas =new OrderedDictionary();
  funciones =new OrderedDictionary();
}

void Cine::agregarSalas(int nro, int cap){
    Integer* llave = new Integer(nro);
    if(!salas->member(llave)){
      Sala* s = new Sala(nro,cap);
      salas->add(llave,s);
      cout << "Sala agregada" << endl;
    }
    else{
      throw invalid_argument ("La sala ya existe");
    }
}

void Cine::listarSalas(ICollectible* obj){
    IIterator* i = salas->getIterator();
    if(i->hasCurrent()){
      while(i->hasCurrent()){
        Sala* s = (Sala*) i->getCurrent();
        cout << "Nro de Sala: " << s->getNroSala() << endl;
        cout <<"-----------------" << endl;
        cout << "Capacidad de Sala: " << s->getCapacidad() << endl;
        cout <<"-----------------" << endl;
        i->next();
        }
      }
      else{
        throw invalid_argument("No hay Salas");
      }
      delete i;
}

void Cine::agregarPelicula(string Titulo, ICollectible* peli){
  StringKey* llave = new StringKey(Titulo);
  if(peliculas->member(llave)){
      peliculas->add(llave,peli);
      return;
  }
  delete llave;
  throw invalid_argument("Este cine ya contiene esta pelicula");
}

void Cine::agregarFuncion(ICollectible* obj){
    int nroS;
    cout << "Elija la sala" << endl;
    cin >> nroS;
    Integer* llave = new Integer(nroS);
    if(salas->member(llave)){
      int nroF,h,d,m,a;
      cout << " Ingrese el numero de la funcion" << endl;
      cin >> nroF;
      cout << " Ingrese el dia" << endl;
      cin >> d;
      cout << " Ingrese el mes" << endl;
      cin >> m;
      cout << " Ingrese el anio" << endl;
      cin >> a;
      cout << "Ingrese el horario de la funcion" << endl;
      cin >> h;

      DtFecha *fecha = new DtFecha(d,m,a);
      Funcion * f= new Funcion(nroF, nroS, *fecha, h);

      Integer* key = new Integer(nroF);
      if(!funciones->member(key)){
        funciones->add(key,f);
        cout <<"Funcion agregada exitosamente" << endl;
      }
      else{
        throw invalid_argument("Ya existe la funcion");
      }
    }
    else{
        throw invalid_argument("Sala incorrecta");
    }
}

bool Cine::verificarPelicula(string Titulo){
  StringKey* llave = new StringKey(Titulo);
  if(!peliculas->member(llave))
  return true;
  else
  return false;
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
