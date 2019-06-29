#pragma once
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
      Credito(int, float, Usuario*, string, float);

      string getFinanciera() const;
      float getDescuento() const;

      void setFinanciera(string);
      void setDescuento(float);

      ~Credito();
};
