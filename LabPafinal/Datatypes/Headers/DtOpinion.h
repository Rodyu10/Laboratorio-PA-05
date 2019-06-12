#include <iostream>
#include <stdlib.h>

using namespace std;

class DtOpinion{

  private:
      float puntaje;
  public:
      DtOpinion();
      DtOpinion(float);

      float getPuntaje() const;

      virtual~DtOpinion();

};
