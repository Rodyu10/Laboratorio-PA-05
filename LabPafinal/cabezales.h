#include <iostream>
#include <stdlib.h>


#include "./Clases/Headers/Sistema.h"
#include "./Clases/Headers/Cine.h"
#include "./Clases/Headers/Comenta.h"
#include "./Clases/Headers/Credito.h"
#include "./Clases/Headers/Funcion.h"
#include "./Clases/Headers/Opinion.h"
#include "./Clases/Headers/Sala.h"
#include "./Clases/Headers/Usuario.h"
#include "./Clases/Headers/Debito.h"
#include "./Clases/Headers/Pelicula.h"
#include "./Clases/Headers/Reserva.h"

#include "./Datatypes/Headers/DtCredito.h"
#include "./Datatypes/Headers/DtUsuario.h"
#include "./Datatypes/Headers/DtCine.h"
#include "./Datatypes/Headers/DtComenta.h"
#include "./Datatypes/Headers/DtDebito.h"
#include "./Datatypes/Headers/DtFuncion.h"
#include "./Datatypes/Headers/DtOpinion.h"
#include "./Datatypes/Headers/DtPelicula.h"
#include "./Datatypes/Headers/DtReserva.h"
#include "./Datatypes/Headers/DtSala.h"

#include "./Interfaces/Headers/ICollectible.h"
#include "./Interfaces/Headers/IIterator.h"
#include "./Interfaces/Headers/IKey.h"
#include "./Interfaces/Headers/ICollection.h"
#include "./Interfaces/Headers/IOrderedKey.h"
#include "./Interfaces/Headers/IDictionary.h"

#include "./Collections/List.h"
#include "./Collections/ListNode.h"
#include "./Collections/ListIterator.h"
#include "./Collections/OrderedDictionary.h"
#include "./Collections/OrderedDictionaryEntry.h"

#include "./String.h"
#include "./Integer.h"

#include "./funciones.cpp"

using namespace std;

void menu();
int opcion();
void menu2();
int opcion2();
void precarga();
