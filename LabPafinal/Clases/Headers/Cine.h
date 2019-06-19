#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Sala.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtCine.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Collections/OrderedDictionary.h"
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
      void listarSalas(ICollectible* obj);
      void agregarFuncion(ICollectible* obj);
      DtCine getCine() const;

      int getNroCine() const;
      string getDir() const;

      void setNroCine(int);
      void setDir(string);

      ~Cine();
};
