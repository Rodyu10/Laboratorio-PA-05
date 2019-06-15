#pragma once
#include <iostream>
#include <stdlib.h>

#include "./DtReserva.h"

using namespace std;

class DtDebito: public DtReserva{
    private:
        string Banco;
    public:
      DtDebito();
      DtDebito(int, float, string);

      float getCosto() const;
      string getBanco();

      virtual~DtDebito();
};
