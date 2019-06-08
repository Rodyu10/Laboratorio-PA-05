#include <iostream>
#include <stdlib.h>

using namespace std;

class Cine{

  private:
      int NroCine;
      string Dir;
  public:
      Cine();
      Cine(int, string);

      //list getListaCines();
      //DtCine getCine();

      int getNroCine() const;
      string getDir() const;

      void setNroCine(int);
      void setDir(string);

      ~Cine();
};
