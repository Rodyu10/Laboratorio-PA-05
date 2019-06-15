#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtCine{
  private:
    int NroCine;
    string Direccion;
  public:
    DtCine();
    DtCine(int,string);
    int getNroCine() const;
    string getDireccion() const;

    virtual ~DtCine();
};
