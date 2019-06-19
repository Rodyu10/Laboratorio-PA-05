#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Datatypes/Headers/DtCine.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Clases/Headers/Sala.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Integer.h"

using namespace std;

class Cine : public ICollectible{

  private:
      int NroCine;
      string Dir;
      IDictionary * funciones;
      IDictionary * salas;
  public:
      Cine();
      Cine(int, string);

      void agregarSalas(int, int);
      DtCine getCine() const;

      int getNroCine() const;
      string getDir() const;

      void setNroCine(int);
      void setDir(string);

      ~Cine();
};
