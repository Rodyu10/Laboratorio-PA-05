#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtFinanciera : public ICollectible{
    private:
      string Financiera;
      float Descuento;
    public:
      DtFinanciera();
      DtFinanciera(string,float);

      string getFinanciera() const;
      float getDescuento() const;

      ~DtFinanciera();
};
