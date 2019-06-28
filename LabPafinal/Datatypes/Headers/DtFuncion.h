#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtFuncion: public ICollectible{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     DtHora Horario;
  public:
     DtFuncion();
     DtFuncion(int, int, DtFecha, DtHora);

     int getNroFuncion();
     int getNroSala();
     DtFecha getFecha();
     DtHora getHorario();

     ~DtFuncion();
};
