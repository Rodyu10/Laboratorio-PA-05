#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtCine: public ICollectible{
  private:
    int NroCine;
    string Direccion;
  public:
    DtCine();
    DtCine(int,string);

    int getNroCine() const;
    string getDireccion() const;

    ~DtCine();
};
