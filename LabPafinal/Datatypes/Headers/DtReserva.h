#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Clases/Headers/Usuario.h"

using namespace std;

class DtReserva{
  private:
      int CantAsientos;
      float Costo;
      Usuario* user;
  public:
      DtReserva();
      DtReserva(int, float, Usuario*);

      int getCantAsientos() const;
      float getCosto() const;

      ~DtReserva();
};
