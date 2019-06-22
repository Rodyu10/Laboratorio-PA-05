#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtFecha{
  private:
    int dia, mes, anio;
  public:
    DtFecha();
    DtFecha(int,int,int);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    bool operator<(DtFecha fecha);
    bool operator==(DtFecha fecha);
    virtual ~DtFecha();
};
