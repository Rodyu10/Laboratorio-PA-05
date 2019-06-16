#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Datatypes/Headers/DtCine.h"

using namespace std;

class Cine : public ICollectible{

  private:
      int NroCine;
      string Dir;
      IDictionary * funciones;
  public:
      Cine();
      Cine(int, string);

      //list getListaCines();
      DtCine getCine() const;

      int getNroCine() const;
      string getDir() const;

      void setNroCine(int);
      void setDir(string);

      ~Cine();
};
