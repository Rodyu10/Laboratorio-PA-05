#include "../Headers/DtFuncion.h"

using namespace std;

DtFuncion::DtFuncion(){

}

DtFuncion::DtFuncion(int nrofun, int nrosala, DtFecha fecha, int horario){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
}

/*list DtFuncion::getListaFunciones(){

}*/

DtFuncion DtFuncion::getFuncion() const{
  return DtFuncion (this->NroFuncion,this->NroSala,this->Fecha,this->Horario);
}

int DtFuncion::getNroFuncion(){
  return this->NroFuncion;
}

int DtFuncion::getNroSala(){
  return this->NroSala;
}

DtFecha DtFuncion::getFecha(){
  return this->Fecha;
}

int DtFuncion::getHorario(){
  return this->Horario;
}

DtFuncion::~DtFuncion(){
  // eliminar una funcion especifica de una pelicula
}
