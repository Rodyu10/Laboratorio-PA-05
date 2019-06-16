#include "../Headers/DtFecha.h"

using namespace std;

DtFecha::DtFecha(){
}

DtFecha::DtFecha(int dia, int mes, int anio){
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
}

int DtFecha::getDia() const {
  return this->dia;
}

int DtFecha::getMes() const {
  return this->mes;
}

int DtFecha::getAnio() const {
  return this->anio;
}

DtFecha::~DtFecha(){
}
