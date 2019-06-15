#include <iostream>
#include <stdlib.h>

#include "../Headers/Sistema.h"
#include "../../String.h"

using namespace std;

/*void Sistema::RegistrarUsuario(string nickname, string fotodeperfil, string pass){
  IKey* key = new IKeyString(nickname);
  if(Usuario->member(Key)){
    Usuario->add(Key.new Usuario(nickname,fotodeperfil,pass));
  }
  else{
    delete Key;
    throw invalid_argument("El usuario ya existe");
  }
}*/

/*void Sistema::IniciarSesion(string Nickname, string Pass){
  String* key = new String(Nickname);
  Usuarios* U = new Usuarios(Nickname, Pass);
  Usuarios->add(U,key);
}*/

// void Sistema::agregarUsuario(string nickname, string fotoperfil, string Pass){
//   String* Key = new String(nickname);
//   if(!Usuario->member(Key)){
//     Usuarios->add(Key,new Usuario(nickname,fotoperfil,Pass));
//   }
//   else{
//     delete Key;
//     throw invalid_argument("El usuario ya existe");
//   }
// }


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
