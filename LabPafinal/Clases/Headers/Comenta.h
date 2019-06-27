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
    string users;
  public:
      Comenta();
      Comenta(string, string);

      void ListarComentariosResp(Comenta * obj);
      void agregarRespuesta(ICollectible * obj,string nick);
      Comenta* BuscarRespuestas(ICollectible* objR, string com);
      string getUsers() const;
      string getComentario() const;

      void setComentario(string);

      ~Comenta();

};
