#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Sala.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
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
      IDictionary * peliculas;
  public:
      Cine();
      Cine(int, string);

      void agregarSalas(int, int);
      void ListarSalas();
      void ListarFunciones(Pelicula* peli);
      Sala* seleccionarSala(int NroSala);
      Funcion* seleccionarFuncion(int NroFuncion);
      void agregarFuncion(Pelicula * peli, int NroFuncion, int NroSala, DtFecha *fecha, DtHora *hora);
      void agregarPelicula(string Titulo, ICollectible* Peli);
      bool verificarPelicula(string Titulo);
      DtCine getCine() const;

      int getNroCine() const;
      string getDir() const;

      void setNroCine(int);
      void setDir(string);

      ~Cine();
};
