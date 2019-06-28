#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtReserva{
  private:
      int CantAsientos;
      float Costo;
  public:
      DtReserva();
      DtReserva(int, float);

      int getCantAsientos() const;
      float getCosto() const;

      ~DtReserva();
};
