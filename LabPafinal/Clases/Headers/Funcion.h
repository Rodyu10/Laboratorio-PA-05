#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Sala.h"
#include "../../Integer.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
#include "../../Datatypes/Headers/DtFuncion.h"

using namespace std;

class Funcion : public ICollectible{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     DtHora Horario;
     IDictionary * reservas;
     Sala * sala;
  public:
     Funcion();
     Funcion(int, int, DtFecha, DtHora);

     int getNroFuncion() const;
     int getNroSala() const;
     DtFecha getFecha() const;
     DtHora getHorario() const;
     void AsociarSala(Sala* sala);
     bool VerificarSalaFecha(int NroSala,DtFecha *fecha, DtHora *hora);

     void setNroFuncion(int);
     void setNroSala(int);
     void setFecha(DtFecha);
     void setHorario(DtHora);

     ~Funcion();
};
