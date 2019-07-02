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
    string users;
    IDictionary * comentariosResp;
  public:
      Comenta();
      Comenta(string, string);

      void ListarComentariosResp(ICollectible * obj, string c);
      void EliminoComentariosResp(ICollectible * obj, string c);
      void agregarRespuesta(ICollectible * obj,string nick, string com);
      Comenta* BuscarRespuestas(ICollectible* objR, string com);

      string getUsers() const;
      string getComentario() const;

      void setComentario(string);
      void setUsers(string);

      ~Comenta();
};
