#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Interfaces/Headers/IDictionary.h"
using namespace std;

class Sala : public ICollectible{

  private:
      int NroSala, Capacidad;
  public:
      Sala();
      Sala(int,int);

      int getNroSala() const;
      int getCapacidad() const;

      void setNroSala(int);
      void setCapacidad(int);

      ~Sala();

};
