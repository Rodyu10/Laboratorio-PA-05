#pragma once
#include <iostream>
#include <stdlib.h>

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
