#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Collections/List.h"
#include "../../Datatypes/Headers/DtPelicula.h"
#include "../../Datatypes/Headers/DtOpinion.h"
#include "../../Clases/Headers/Comenta.h"
#include "../../Clases/Headers/Opinion.h"
#include "../../Clases/Headers/Funcion.h"
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
      ICollection* ListarFunciones();
      void agregarComentario(Pelicula * peli, string nick);
      ICollection* ListarPuntajes(Pelicula* peli);
      void AgregarPuntaje(Pelicula* peli, string user, float puntaje);
      void MostrarComentariosPuntajes(ICollectible* obj, string t, float p, int cant);
      Comenta* BuscarComentario(ICollectible * objC, string com);
      void AsociarFuncion(Funcion* funcion);
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
