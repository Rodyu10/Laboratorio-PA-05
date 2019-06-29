#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class Financiera: public ICollectible{
    private:
        string financiera;
        float Descuento;
    public:
      Financiera();
      Financiera(string, float);

      string getFinanciera() const;
      float getDescuento() const;

      void setFinanciera(string);
      void setDescuento(float);

      ~Financiera();
};
