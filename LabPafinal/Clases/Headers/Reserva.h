#include <iostream>
#include <stdlib.h>

using namespace std;

class Reserva{
  private:
      int CantAsientos;
      float Costo;
  public:
      Reserva();
      Reserva(int, float);

      //Reserva create();
      //Reserva add();

      int getCantAsientos() const;
      float getCosto() const;

      void setCantAsientos(int);
      void setCosto(float);

      ~Reserva();
};
