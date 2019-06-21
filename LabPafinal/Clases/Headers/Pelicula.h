#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Datatypes/Headers/DtPelicula.h"
#include "../../Clases/Headers/Comenta.h"
#include "../../Clases/Headers/Opinion.h"
#include "../../Clases/Headers/Usuario.h"
#include "../../String.h"
#include "../../Integer.h"

using namespace std;

class Pelicula : public ICollectible{

  private:
      string Titulo;
      string Poster;
      string Sinopsis;
      float Puntaje;
      IDictionary* funciones;
      IDictionary* opiniones;
      IDictionary* comentarios;
  public:
      Pelicula();
      Pelicula(string, string, string, float);

      DtPelicula getPelicula() const;

      void ListarComentarios(ICollectible * obj);
      void agregarComentario(ICollectible * obj, string nick);
      float agregarPuntaje(ICollectible * obj, string);
      void MostrarComentariosPuntajes(ICollectible* obj, string t, float p, int cant);
      string getTitulo()const;
      string getPoster()const;
      string getSinopsis() const;
      float getPuntaje() const;

      void setTitulo(string);
      void setPoster(string);
      void setSinopsis(string);
      void setPuntaje(float);

      ~Pelicula();

};
