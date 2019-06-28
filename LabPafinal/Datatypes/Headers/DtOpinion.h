#pragma once
#include <iostream>
#include <stdlib.h>
#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class DtOpinion: public ICollectible{

  private:
      float puntaje;
      string user;
  public:
      DtOpinion();
      DtOpinion(float, string);

      float getPuntaje() const;
      string getUser () const;

      ~DtOpinion();

};
