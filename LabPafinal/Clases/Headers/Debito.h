#pragma once
#include <iostream>
#include <stdlib.h>

#include "./Reserva.h"

using namespace std;

class Debito: public Reserva{
    private:
        string Banco;
    public:
      Debito();
      Debito(int, float, Usuario*, string);

      string getBanco();

      void setBanco(string);

      ~Debito();
};
