#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "./Usuario.h"

using namespace std;

class Reserva : public ICollectible{
  private:
      int CantAsientos;
      float Costo;
      Usuario* user;
  public:
      Reserva();
      Reserva(int, float);

      int getCantAsientos() const;
      float getCosto() const;
      Usuario* getUsuario() const;

      void setCantAsientos(int);
      void setCosto(float);
      void setUsuario(Usuario*);

      ~Reserva();
};
