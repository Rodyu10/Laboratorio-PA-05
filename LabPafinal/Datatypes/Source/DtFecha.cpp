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

bool DtFecha::operator<(DtFecha fecha){
    if(this->anio < fecha.getAnio()){
        return true;
    }else if (this->anio == fecha.getAnio()){
        if(this->mes < fecha.getMes()){
            return true;
        }else if (this->mes == fecha.getMes()){
            if(this->dia < fecha.getDia())
                return true;
        }
    }
    return false;
}

bool DtFecha::operator==(DtFecha fecha){
  if(this->anio==fecha.getAnio() && this->mes==fecha.getMes() && this->dia==fecha.getDia())
  return true;
  else
  return false;
}

DtFecha::~DtFecha(){
}
