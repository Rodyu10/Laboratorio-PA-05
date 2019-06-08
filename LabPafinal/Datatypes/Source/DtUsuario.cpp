#include <iostream>
#include <stdlib.h>

#include "../Headers/DtUsuario.h"

using namespace std;

DtUsuario::DtUsuario(){
}

DtUsuario::DtUsuario(string Nickname, string FotoPerfil, string Password){
  this->Nickname = Nickname;
  this->FotoPerfil = FotoPerfil;
  this->Password = Password;
}

string DtUsuario::getNickname() const {
  return this->Nickname;
}

string DtUsuario::getFotoPerfil() const {
  return this->FotoPerfil;
}

string DtUsuario::getPassword() const {
  return this->Password;
}

DtUsuario::~DtUsuario(){
}
