#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtPelicula : public ICollectible{

  private:
      string Titulo;
      string Poster;
      string Sinopsis;
      float Puntaje;
  public:
      DtPelicula();
      DtPelicula(string, string, string, float);

      string getTitulo() const;
      string getPoster()const;
      string getSinopsis() const;
      float getPuntaje() const;

      ~DtPelicula();

};
