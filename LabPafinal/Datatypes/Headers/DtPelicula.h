#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtPelicula{

  private:
      string Titulo;
      string Poster;
      string Sinopsis;
      float Puntaje;
  public:
      DtPelicula();
      DtPelicula(string, string, string, float);

      //list getListaPeliculas();
      DtPelicula getPelicula() const;

      string getTitulo() const;
      string getPoster()const;
      string getSinopsis() const;
      float getPuntaje() const;

      virtual~DtPelicula();

};
