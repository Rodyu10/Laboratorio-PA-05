#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"

using namespace std;

class Opinion : public ICollectible{

  private:
    float puntaje;
  public:
      Opinion();
      Opinion(float);

      float getPuntaje() const;

      void setPuntaje(float);

      ~Opinion();

};
