#include <iostream>
#include <stdlib.h>

#include "../Headers/Usuario.h"

using namespace std;

Usuario::Usuario(){

}

Usuario::Usuario(string nickname, string fotoperfil, string contrasenia){
  this->nickname = nickname;
  this->fotoperfil = fotoperfil;
  this->contrasenia = contrasenia;
}

bool Usuario::verificarPass(){
 // VERIFICA QUE LA PASS SEA CORRECTA
 return 0;
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
