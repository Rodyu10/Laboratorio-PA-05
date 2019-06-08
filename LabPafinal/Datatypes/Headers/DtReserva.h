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

      //Reserva create();
      //Reserva add();

      int getCantAsientos() const;
      float getCosto() const;

      virtual~DtReserva();
};
