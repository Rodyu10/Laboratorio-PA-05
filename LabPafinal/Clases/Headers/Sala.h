#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Datatypes/Headers/DtSala.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Interfaces/Headers/IDictionary.h"
using namespace std;

class Sala : public ICollectible{

  private:
      int NroSala, Capacidad;
      bool Ocupado;
  public:
      Sala();
      Sala(int,int,bool);

      DtSala getSala() const;

      int getNroSala() const;
      int getCapacidad() const;
      bool getOcupado() const;

      void setNroSala(int);
      void setCapacidad(int);
      void setOcupado(bool);

      ~Sala();

};
