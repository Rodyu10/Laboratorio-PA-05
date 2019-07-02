#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Sala.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Financiera.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
#include "../../Datatypes/Headers/DtCine.h"
#include "../../Datatypes/Headers/DtSala.h"
#include "../../Datatypes/Headers/DtFinanciera.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Collections/List.h"
#include "../../Integer.h"

using namespace std;

class Cine : public ICollectible{

  private:
      int NroCine, PrecioEntrada;
      string Dir;
      IDictionary * funciones;
      IDictionary * salas;
      IDictionary * peliculas;
      IDictionary * financieras;
  public:
      Cine();
      Cine(int, int, string);

      void agregarSalas(int, int);
      bool agregarFinanciera(string, float);
      bool verificarFinanciera(string);
      float DescuentoFinanciera(string);
      ICollection* ListarSalas();
      ICollection* ListarFunciones(string Titulo);
      ICollection* ListarFinancieras();
      Sala* seleccionarSala(int NroSala);
      Funcion* seleccionarFuncion(int NroFuncion);
      int CantFunciones();
      void agregarFuncion(Pelicula * peli, int NroFuncion, int NroSala, DtFecha *fecha, DtHora *hora);
      void agregarPelicula(string Titulo, Pelicula* Peli);
      bool verificarPelicula(string Titulo);
      void EliminarPelicula(string Titulo, Pelicula* peli);

      int getNroCine() const;
      string getDir() const;
      int getPrecioEntrada() const;

      void setNroCine(int);
      void setDir(string);
      void setPrecioEntrada(int);

      ~Cine();
};
