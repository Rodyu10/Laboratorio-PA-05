#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Usuario.h"
#include "../../Clases/Headers/Cine.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
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
   bool esAdmin(string);
   void AltaCine(int,string);
   void AltaPelicula(string,string,string,int);
   void AltaFuncion(Cine* cine, Pelicula* peli, int NroSala);
   void ComentarPelicula(string);
   void PuntuarPelicula(string);
   void Precarga();
   void ListarTitulos();
   void ListarPeliculas();
   void ListarCines();
   void ListarCines(string Titulo);
   void VerInfoPelicula();
   void ListarFunciones(Cine* cine, Pelicula* peli);
   void ListarSalas(Cine* cine);
   void EliminarPelicula(string Titulo);
   void Eliminar2(string Titulo);
   void VerComentariosPuntaje();
   Pelicula* SeleccionPelicula(string Titulo);
   Cine* SeleccionCine(int NroCine);
   Sala* SeleccionSala(Cine* cine, int NroSala);
   Funcion* SeleccionFuncion(Cine* cine, int NroFuncion);
   void SeleccionTitulo(string Titulo);
   float PagaCredito(string NombreFinanciera, int CantAsientos);
   float PagaDebito(string NombreBanco, int CantAsientos);
   void CrearReserva();
   void Control();
   ~Sistema();
};
