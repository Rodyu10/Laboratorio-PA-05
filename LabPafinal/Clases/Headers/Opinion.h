#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtOpinion.h"

using namespace std;

class Opinion{

  private:
    float puntaje;
  public:
      Opinion();
      Opinion(float);

      float getPuntaje() const;

      void setPuntaje(float);

      ~Opinion();

};
