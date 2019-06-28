#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class DtUsuario{
  private:
    string Nickname, FotoPerfil, Password;
  public:
    DtUsuario();
    DtUsuario(string,string,string);
    
    string getNickname() const;
    string getFotoPerfil() const;
    string getPassword() const;

    ~DtUsuario();
};
