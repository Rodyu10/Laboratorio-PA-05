#include <iostream>
#include <stdlib.h>

#include "./DtReserva.h"

using namespace std;

class DtCredito: public DtReserva{
    private:
        string Financiera;
        float Descuento;
    public:
      DtCredito();
      DtCredito(int, float, string, float);

      float getCosto() const;
      string getFinanciera();
      float getDescuento();

      virtual~DtCredito();
};
