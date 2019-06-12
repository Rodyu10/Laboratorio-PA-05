#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtComenta.h"

using namespace std;

class Comenta{

  private:
    string comentario;
  public:
      Comenta();
      Comenta(string);

      string getComentario() const;

      void setComentario(string);

      ~Comenta();

};
