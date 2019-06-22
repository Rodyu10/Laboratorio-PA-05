#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtHora{
  private:
    int Hora;
    int Minutos;
    int Segundos;
  public:
    DtHora();
    DtHora(int,int,int);
    int getHora() const;
    int getMinutos() const;
    int getSegundos() const;

    virtual ~DtHora();
};
