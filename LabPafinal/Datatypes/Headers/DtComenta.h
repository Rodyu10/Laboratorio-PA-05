#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtComenta{

  private:
      string comentario;
  public:
      DtComenta();
      DtComenta(string);

      string getComentario() const;

      virtual~DtComenta();

};
