#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Usuario.h"

using namespace std;
class Pelicula;
class Opinion : public ICollectible{

  private:
    float puntaje;
    string user;
  public:
      Opinion();
      Opinion(float, string);

      float getPuntaje() const;
      string getUser ();
      void setPuntaje(float);

      ~Opinion();

};
