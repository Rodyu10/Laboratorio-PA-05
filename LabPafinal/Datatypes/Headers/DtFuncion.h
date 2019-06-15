#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtFecha.h"

using namespace std;

class DtFuncion{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     int Horario;
  public:
     DtFuncion();
     DtFuncion(int, int, DtFecha, int);

     //list getListaFunciones();
     DtFuncion getFuncion() const;

     int getNroFuncion();
     int getNroSala();
     DtFecha getFecha();
     int getHorario();

     virtual~DtFuncion();
};
