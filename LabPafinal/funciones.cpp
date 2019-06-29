#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

using namespace std;

void menu()
{
  cout << "====================================" << endl;
  cout << "           MENU PRINCIPAL" << endl;
  cout << "====================================" << endl;
  cout << "1-Registrar Usuario" << endl;
  cout << "2-Iniciar Sesion" << endl;
  cout << "0-Salir" << endl;
  cout << "====================================" << endl;
}

void menuDos()
{
  cout << "==========================================" << endl;
  cout << "               MENU USUARIO" << endl;
  cout << "==========================================" << endl;
  cout << "1-Alta Cine" << endl;
  cout << "2-Alta Funcion" << endl;
  cout << "3-Alta Pelicula" << endl;
  cout << "4-Crear Reserva" << endl;
  cout << "5-Puntuar Pelicula" << endl;
  cout << "6-Eliminar Pelicula" << endl;
  cout << "7-Comentar Pelicula" << endl;
  cout << "8-Ver informacion de Pelicula" << endl;
  cout << "9-Ver comentarios y puntaje de Pelicula" << endl;
  cout << "0-Volver al menu principal" << endl;
  cout << "==========================================" << endl;
}

int opcion()
{
    int op;
    do
    {
        cout << "Ingrese Opción: " << endl;
        cin >> op;
    }
    while ((op < 0) || (op > 2));
    return op;
}

int opcionDos()
{
    int op;
    do
    {
        cout << "Ingrese Opción: " << endl;
        cin >> op;
    }
    while ((op < 0) || (op > 9));
    return op;
}

void ListarPeliculas(ICollection* peliculas){
  IIterator* i = peliculas->getIterator();
    cout << "======================LISTA PELICULAS====================="<<endl;
  while(i->hasCurrent()){
    DtPelicula* p = (DtPelicula*) i->getCurrent();
    cout << p->getTitulo() << endl;
    cout << "Poster: " << p->getPoster() << endl;
    cout << "Sinopsis: " << p->getSinopsis() << endl;
    cout << "Puntaje: " << p->getPuntaje() << endl;
    cout << "==========================================================" << endl;
    peliculas->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete peliculas;
}

void ListarPuntaje(ICollection* puntajes){
  IIterator* i= puntajes->getIterator();
    cout << "================LISTA PUNTAJES==============="<<endl;
  while(i->hasCurrent()){
    DtOpinion* o = (DtOpinion*) i->getCurrent();
    cout << "Usuario: " << o->getUser() << endl;
    cout << "Puntaje: " << o->getPuntaje() << endl;
    cout << "==============================================" << endl;
    puntajes->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete puntajes;
}

int ChequeoUsuario(ICollection* puntajes, string user){
  IIterator* i= puntajes->getIterator();
  int aux = 0;
  while(i->hasCurrent()){
    DtOpinion* o = (DtOpinion*) i->getCurrent();
    if(o->getUser() == user){
      int aux = 1;
      return aux;
    }
    puntajes->remove(i->getCurrent());
    i->next();
  }
  delete puntajes;
  return aux;
}

void ListarTitulos(ICollection* peliculas){
  IIterator* i = peliculas->getIterator();
    cout << "=================LISTA TITULOS================"<<endl;
  while(i->hasCurrent()){
    DtPelicula* p = (DtPelicula*) i->getCurrent();
    cout << p->getTitulo() << endl;
    cout << "==============================================" << endl;
    peliculas->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete peliculas;
}

void ListarFinancieras(ICollection* financieras){
  IIterator* i = financieras->getIterator();
    cout << "==========LISTA FINANCIERAS ASOCIADAS========="<<endl;
  while(i->hasCurrent()){
    DtFinanciera* f = (DtFinanciera*) i->getCurrent();
    cout << "Nombre: "<< f->getFinanciera() << endl;
    cout << "Descuento: "<< f->getDescuento() << "%" << endl;
    cout << "==============================================" << endl;
    financieras->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete financieras;
}

void ListarCines(ICollection* cines){
  IIterator* i = cines->getIterator();
    cout << "==================LISTA CINES================="<<endl;
  while(i->hasCurrent()){
    DtCine* c = (DtCine*) i->getCurrent();
    cout << "Numero de cine: " << c->getNroCine() << endl;
    cout << "Direccion: " << c->getDireccion() << endl;
    cout << "==============================================" << endl;
    cines->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete cines;
}

void ListarSalas(ICollection* salas){
    IIterator* i = salas->getIterator();
      cout << "=================SALAS DE CINE=============="<<endl;
    while(i->hasCurrent()){
      DtSala* s = (DtSala*) i->getCurrent();
      cout << "Nro de Sala: " << s->getNroSala() << endl;
      cout << "Capacidad de Sala: " << s->getCapacidad() << endl;
      cout << "============================================"<<endl;
      salas->remove(i->getCurrent());
      i->next();
    }
    delete i;
    delete salas;
}

void ListarFunciones(ICollection* funciones){
  system("clear");
  IIterator* i = funciones->getIterator();
    cout << "=================LISTA FUNCIONES================"<<endl;
  while(i->hasCurrent()){
    DtFuncion* fun = (DtFuncion*) i->getCurrent();
    DtFecha fechaF = fun->getFecha();
    DtHora horaF = fun ->getHorario();
    cout << "Numero de Funcion: " << fun->getNroFuncion() << endl;
    cout << "Numero de Sala: " << fun->getNroSala() << endl;
    cout << "Fecha de la Funcion: " << fechaF.getDia() << "/" << fechaF.getMes() << "/" << fechaF.getAnio() << endl;
    if(horaF.getMinutos()==0)
    cout << "Hora de la Funcion: " << horaF.getHora() << ":" << "00" << endl;
    else
    cout << "Hora de la Funcion: " << horaF.getHora() << ":" << horaF.getMinutos() << endl;
    cout << "================================================"<<endl;
    funciones->remove(i->getCurrent());
    i->next();
  }
  delete i;
  delete funciones;
}
