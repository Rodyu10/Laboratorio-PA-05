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
   void RegistrarUsuario(string, string, string);
   ~Sistema();
   void agregarUsuario(string nickname, string fotoperfil, string Pass);
   void IniciarSesion(string Nickname, string Pass);
   void ListarTitulos();
   void Eliminar(string Titulo);
   void ListarPeliculas();
   void SeleccionPelicula(string Titulo);
   void ListarCines();
   void SeleccionCine(int NroCine);
   void ListarFunciones(int NroFuncion);
   float PagaCredito(string NombreFinanciera, int CantAsientos);
   float PagaDebito(string NombreBanco, int CantAsientos);
   void CrearReserva();
   void Eliminar2(string Titulo);
   void SeleccionTitulo(string Titulo);
};
