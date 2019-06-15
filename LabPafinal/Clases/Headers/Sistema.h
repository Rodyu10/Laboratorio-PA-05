#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/IDictionary.h"

using namespace std;

class Sistema  {
 private:
    static Sistema* instance;
    Sistema();
    IDictionary* usuarios;
    IDictionary* peliculas;
    IDictionary* cines;
 public:
   static Sistema* getInstance();
   void ListarTitulos();
   void RegistrarUsuario(string, string, string);

};
