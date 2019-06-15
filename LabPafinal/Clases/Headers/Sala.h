#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtSala.h"
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class Sala : public ICollectible{

  private:
      int NroSala, Capacidad;
  public:
      Sala();
      Sala(int,int);

      DtSala getSala() const;

      int getNroSala() const;
      int getCapacidad()const;

      void setNroSala(int);
      void setCapacidad(int);

      ~Sala();

};
