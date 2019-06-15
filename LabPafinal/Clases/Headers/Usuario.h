#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Interfaces/Headers/ICollectible.h"

using namespace std;

class Usuario : public ICollectible{

  private:

    string nickname;
    string fotoperfil;
    string contrasenia;

  public:

    Usuario();
    Usuario(string,string,string);

    bool verificarPass();

    string getNick() const;
    string getUrl() const;
    string getPass() const;

    void setNick(string);
    void setUrl(string);
    void setPass(string);

    ~Usuario();

};
