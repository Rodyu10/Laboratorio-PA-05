#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtFuncion.h"

using namespace std;

class Funcion{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     int Horario;
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
