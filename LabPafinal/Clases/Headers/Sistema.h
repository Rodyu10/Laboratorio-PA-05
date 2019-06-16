#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Usuario.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../String.h"
#include "../../Integer.h"

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
   bool VerificarSesion(string, string);
   void IniciarSesion(string,string);
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
   ~Sistema();
};
