#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Sala.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/ICollection.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"

using namespace std;

class Funcion : public ICollectible{

  private:
     int NroFuncion;
     int NroSala;
     DtFecha Fecha;
     DtHora Horario;
     Pelicula * pelicula;
     IDictionary * reservas;
     IDictionary * salas;
  public:
     Funcion();
     Funcion(int, int, DtFecha, DtHora, Pelicula*);

     int getNroFuncion() const;
     int getNroSala() const;
     DtFecha getFecha() const;
     DtHora getHorario() const;
     Pelicula* getPelicula() const;
     void AsociarSala(Sala* sala);

     void setPelicula(Pelicula*);
     void setNroFuncion(int);
     void setNroSala(int);
     void setFecha(DtFecha);
     void setHorario(DtHora);

     ~Funcion();
};
