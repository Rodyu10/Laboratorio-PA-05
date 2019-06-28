#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtHora{
  private:
    int Hora;
    int Minutos;
  public:
    DtHora();
    DtHora(int,int);
    
    int getHora() const;
    int getMinutos() const;

    bool operator==(DtHora hora);

    ~DtHora();
};
