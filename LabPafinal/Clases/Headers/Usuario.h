#include <iostream>
#include <stdlib.h>


using namespace std;

class Usuario{

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
