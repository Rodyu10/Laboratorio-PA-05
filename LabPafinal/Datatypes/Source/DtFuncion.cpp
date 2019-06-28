#include "../Headers/DtFuncion.h"

using namespace std;

DtFuncion::DtFuncion(){

}

DtFuncion::DtFuncion(int nrofun, int nrosala, DtFecha fecha, DtHora horario){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
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

DtHora DtFuncion::getHorario(){
  return this->Horario;
}

DtFuncion::~DtFuncion(){
}
