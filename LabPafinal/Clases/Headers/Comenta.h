#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../String.h"

using namespace std;

class Comenta : public ICollectible{

  private:
    string comentario;
    IDictionary * comentariosResp;
  public:
      Comenta();
      Comenta(string);

      void agregarRespuesta(ICollectible * obj);
      string getComentario() const;

      void setComentario(string);

      ~Comenta();

};
