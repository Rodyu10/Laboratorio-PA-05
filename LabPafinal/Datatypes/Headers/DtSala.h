#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtSala : public ICollectible{

  private:
      int NroSala, Capacidad;
  public:
      DtSala();
      DtSala(int,int);

      int getNroSala() const;
      int getCapacidad()const;

      ~DtSala();

};
