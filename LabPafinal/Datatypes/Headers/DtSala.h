#include <iostream>
#include <stdlib.h>

using namespace std;

class DtSala {

  private:
      int NroSala, Capacidad;
  public:
      DtSala();
      DtSala(int,int);

      int getNroSala() const;
      int getCapacidad()const;

      virtual ~DtSala();

};
