#include <iostream>
#include <stdlib.h>

#include "../../Datatypes/Headers/DtSala.h"

using namespace std;

class Sala{

  private:
      int NroSala, Capacidad;
  public:
      Sala();
      Sala(int,int);


      int NroSala() const;
      int getCapacidad()const;

      void setNroSala(int);
      void setCapacidad(int);
      
      ~Sala();

};
