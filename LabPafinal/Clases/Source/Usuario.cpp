#include "../Headers/Usuario.h"

using namespace std;

Usuario::Usuario(){

}

Usuario::Usuario(string nickname, string fotoperfil, string contrasenia){
  this->nickname = nickname;
  this->fotoperfil = fotoperfil;
  this->contrasenia = contrasenia;
}

bool Usuario::verificarPass(string pass){
  if(this->contrasenia == pass){
    return true;
  }
  else{
    return false;
  }
}

string Usuario::getNick() const {
  return this->nickname;
}

string Usuario::getUrl() const{
  return this->fotoperfil;
}

string Usuario::getPass() const{
  return this->contrasenia;
}

void Usuario::setNick(string nick){
  this->nickname = nick;
}
void Usuario::setUrl(string url){
  this->fotoperfil = url;
}

void Usuario::setPass(string pass){
  this->contrasenia = pass;
}

Usuario::~Usuario(){
}
