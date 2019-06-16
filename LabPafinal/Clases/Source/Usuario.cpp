#include <iostream>
#include <stdlib.h>

#include "../Headers/Usuario.h"
#include "../../Interfaces/Headers/ICollectible.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/IIterator.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Interfaces/Headers/IOrderedKey.h"
#include "../../Interfaces/Headers/ICollection.h"

using namespace std;

Usuario::Usuario(){

}

Usuario::Usuario(string nickname, string fotoperfil, string contrasenia){
  this->nickname = nickname;
  this->fotoperfil = fotoperfil;
  this->contrasenia = contrasenia;
}

bool Usuario::verificarPass(string nick, string pass){
  
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
