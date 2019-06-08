#include <iostream>
#include <stdlib.h>

#include "./Reserva.h"

using namespace std;

class Credito: public Reserva{
    private:
        string Financiera;
        float Descuento;
    public:
      Credito();
      Credito(int, float, string, float);

      float getCosto() const;
      string getFinanciera();
      float getDescuento();

      void setFinanciera(string);
      void setDescuento(float);

      ~Credito();
};
