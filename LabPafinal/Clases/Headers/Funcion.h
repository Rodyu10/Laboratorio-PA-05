#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Datatypes/Headers/DtFuncion.h"
#include "../../Datatypes/Headers/DtFecha.h"

using namespace std;

class Funcion : public ICollectible{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     int Horario;
     ICollection * reservas;
  public:
     Funcion();
     Funcion(int, int, DtFecha, int);

     //list getListaFunciones();
     DtFuncion getFuncion() const;

     int getNroFuncion();
     int getNroSala();
     DtFecha getFecha();
     int getHorario();

     void setNroFuncion(int);
     void setNroSala(int);
     void setFecha(DtFecha);
     void setHorario(int);

     ~Funcion();
};
