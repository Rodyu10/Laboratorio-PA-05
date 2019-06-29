#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Sala.h"
#include "../../Clases/Headers/Usuario.h"
#include "../../Clases/Headers/Reserva.h"
#include "../../Clases/Headers/Credito.h"
#include "../../Clases/Headers/Debito.h"
#include "../../Integer.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Collections/List.h"
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
     Sala * sala;
     ICollection * reservas;
  public:
     Funcion();
     Funcion(int, int, DtFecha, DtHora);

     void AsociarSala(Sala* sala);
     void AltaReserva(Usuario* user, int cantAsientos, float costo, string nombreBF, float descuento, bool CrDe);
     bool VerificarSalaFecha(int NroSala,DtFecha *fecha, DtHora *hora);

     int getNroFuncion() const;
     int getNroSala() const;
     DtFecha getFecha() const;
     DtHora getHorario() const;
     Sala* getSala() const;

     void setNroFuncion(int);
     void setNroSala(int);
     void setFecha(DtFecha);
     void setHorario(DtHora);
     void setSala(Sala*);

     ~Funcion();
};
