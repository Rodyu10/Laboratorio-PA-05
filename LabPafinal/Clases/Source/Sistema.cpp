#include <iostream>
#include <stdlib.h>

#include "../Headers/Sistema.h"

using namespace std;

Sistema::Sistema(){
  usuarios=new OrderedDictionary();
}

Sistema* Sistema::instance = nullptr;

Sistema* Sistema::getInstance(){
    if(instance == nullptr){
      instance = new Sistema();
    }
    return instance;
}

void Sistema::RegistrarUsuario(string nickname, string fotodeperfil, string pass){
 StringKey* llave = new StringKey(nickname);
 if(!usuarios->member(llave)){
   Usuario* u=new Usuario(nickname,fotodeperfil,pass);
   usuarios->add(llave,u);
 }
 else{
    delete llave;
    throw invalid_argument("El usuario ya existe");
 }
}

bool Sistema::VerificarSesion(string nickname, string pass){
  StringKey* llave = new StringKey(nickname);
  if(usuarios->member(llave)){
    Usuario* u=(Usuario*) usuarios->find(llave);
    if(u->getPass()==pass){
      return true;
    }
    else{
      throw invalid_argument("Password incorrecto");
    }
  }
  else{
    throw invalid_argument("El usuario es incorrecto");
  }
}

void Sistema::IniciarSesion(string nickname, string pass){
  if(VerificarSesion(nickname,pass)){
    cout << "==========================================" << endl;
    cout << "    INICIO CORRECTAMENTE LA SESION" << endl;
    cout << "==========================================" << endl;
  }
}

// void Sistema::ListarTitulos(Pelicula::Titulo){
//   IKey* key = new KeyInteger(Titulo);
//   ICollectible* p = Peliculas->find(key);
//   delete key;
//   if(p==NULL){
//     throw invalid_argument("No hay Peliculas");
//   }
//   Peliculas->add(key);
// }
//
// void Sistema::Eliminar(Pelicula::Titulo){
//   IKey* key = new KeyInteger(Titulo);
//   ICollectible* p = Peliculas->find(key);
//   delete key;
//   if(p==NULL){
//     throw invalid_argument("No hay Peliculas");
//   }
//   Peliculas->remove(key);
//   delete p;
// }

/*void Sistema::ListarPeliculas(DtPelicula::DtPelicula){
  //Dudas
}*/

// void Sistema::SeleccionPelicula(Pelicula::Titulo){
//
// }

// void Sistema::ListarCines(DtCine::DtCine){
//
// }

// void Sistema::SeleccionCine(Cine::NroCine){
//
// }

// void Sistema::ListarFunciones(Funcion::NroFuncion){
//
// }

// float Sistema::PagaCredito(string NombreFinanciera, int CantAsientos){
//
// }
//
// float Sistema::PagaDebito(string NombreBanco, int CantAsientos){
//
// }
//
// void Sistema:CrearReserva(){
//
// }
//
// void Sistema::Eliminar2(string Titulo){
//   IKey* key = new KeyInteger(Titulo);
//   ICollectible* /*F*/ = /*Funciones*/->find(key);
//   delete key;
//   if(p==NULL){
//     throw invalid_argument("No hay Peliculas");
//   }
//   /*Funciones*/->remove(key);
//   delete /*F*/;
// }
//
// void Sistema::SeleccionTitulo(string Titulo){
//
// }
