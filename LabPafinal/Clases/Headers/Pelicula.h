#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtPelicula.h"

using namespace std;

class Pelicula{

  private:
      string Titulo;
      string Poster;
      string Sinopsis;
      float Puntaje;
  public:
      Pelicula();
      Pelicula(string, string, string, float);

      //list getListaPeliculas();
      DtPelicula getPelicula() const;

      string getTitulo() const;
      string getPoster()const;
      string getSinopsis() const;
      float getPuntaje() const;

      void setTitulo(string);
      void setPoster(string);
      void setSinopsis(string);
      void setPuntaje(float);

      ~Pelicula();

};
