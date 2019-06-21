#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Usuario.h"
#include "../../Clases/Headers/Cine.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Datatypes/Headers/DtFecha.h"
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
   void AltaCine(int,string);
   void AltaPelicula(string,string,string,float);
   void AltaFuncion();
   void ComentarPelicula();
   void PuntuarPelicula(string);
   void precarga();
   void ListarTitulos();
   void EliminarPelicula(string Titulo);
   void ListarPeliculas();
   Pelicula* SeleccionPelicula(string Titulo);
   bool esAdmin(string);
   void ListarCines();
   void ListarCines(string Titulo);
   Cine* SeleccionCine(int NroCine);
   void ListarFunciones(int NroFuncion);
   float PagaCredito(string NombreFinanciera, int CantAsientos);
   float PagaDebito(string NombreBanco, int CantAsientos);
   void CrearReserva();
   void Eliminar2(string Titulo);
   void SeleccionTitulo(string Titulo);
   ~Sistema();
};
