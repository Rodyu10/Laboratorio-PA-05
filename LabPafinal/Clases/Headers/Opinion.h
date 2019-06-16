#pragma once
#include <iostream>
#include <stdlib.h>

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
