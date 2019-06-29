#pragma once
#include <iostream>
#include <stdlib.h>

#include "../../Clases/Headers/Usuario.h"
#include "../../Clases/Headers/Cine.h"
#include "../../Clases/Headers/Pelicula.h"
#include "../../Clases/Headers/Funcion.h"
#include "../../Clases/Headers/Comenta.h"
#include "../../Datatypes/Headers/DtFecha.h"
#include "../../Datatypes/Headers/DtHora.h"
#include "../../Interfaces/Headers/IDictionary.h"
#include "../../Interfaces/Headers/IKey.h"
#include "../../Collections/OrderedDictionary.h"
#include "../../Collections/List.h"
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
   bool esAdmin(string);
   void AltaCine(Cine* cine);
   void AltaPelicula(string,string,string,int);
   void Precarga();
   ICollection* ListarPeliculas();
   ICollection* ListarCines();
   ICollection* ListarCines(string titulo);
   void EliminarPelicula(Pelicula* peli);
   Pelicula* SeleccionPelicula(string Titulo);
   Cine* SeleccionCine(int NroCine);
   Funcion* SeleccionFuncion(Cine* cine, int NroFuncion);
   Usuario* obtenerUsuario(string nick);
   Pelicula* verificarPelicula(string Titulo);
   int CantCines();
   void Control();
   ~Sistema();
};
