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

int DtFuncion::getNroFuncion() const{
  return this->NroFuncion;
}

int DtFuncion::getNroSala() const{
  return this->NroSala;
}

DtFecha DtFuncion::getFecha() const{
  return this->Fecha;
}

DtHora DtFuncion::getHorario() const{
  return this->Horario;
}

DtFuncion::~DtFuncion(){
}
