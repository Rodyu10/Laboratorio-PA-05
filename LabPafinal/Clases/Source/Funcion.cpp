#include "../Headers/Funcion.h"

using namespace std;

Funcion::Funcion(){
}

Funcion::Funcion(int nrofun, int nrosala, DtFecha fecha, DtHora horario){
  this->NroFuncion = nrofun;
  this->NroSala = nrosala;
  this->Fecha = fecha;
  this->Horario = horario;
  reservas = new List();
}

void Funcion::AsociarSala(Sala* sala){
  this->sala = sala;
}

bool Funcion::VerificarSalaFecha(int NroSala, DtFecha *fecha, DtHora *hora){
  if(this->sala->getNroSala()==NroSala){
    DtFecha fechaF = this->getFecha();
    DtHora horaF = this->getHorario();
    DtFecha fechaIng = DtFecha(fecha->getDia(),fecha->getMes(),fecha->getAnio());
    DtHora horaIng = DtHora(hora->getHora(),hora->getMinutos());
    if(fechaF==fechaIng && horaF==horaIng){
      cout << endl << "Ya existe una funcion asignada para esta hora y fecha en esta sala" << endl;
      return true;
    }
  }
  return false;
}

void Funcion::AltaReserva(Usuario* user, int cantAsientos, float costo, string nombreBF, float descuento, bool CrDe){
  if(CrDe){
  Debito* debito = new Debito(cantAsientos,costo,user,nombreBF);
  reservas->add(debito);
  }
  else{
  Credito* credito = new Credito(cantAsientos,costo,user,nombreBF,descuento);
  reservas->add(credito);
  }
}

int Funcion::getNroFuncion() const{
  return this->NroFuncion;
}

int Funcion::getNroSala() const{
  return this->NroSala;
}

DtFecha Funcion::getFecha() const{
  return this->Fecha;
}

DtHora Funcion::getHorario() const{
  return this->Horario;
}

Sala* Funcion::getSala() const{
  return this->sala;
}

void Funcion::setNroFuncion(int nrofun){
  this->NroFuncion = nrofun;
}

void Funcion::setNroSala(int nrosala){
  this->NroSala = nrosala;
}

void Funcion::setFecha(DtFecha fecha){
  this->Fecha = fecha;
}

void Funcion::setHorario(DtHora horario){
  this->Horario = horario;
}

void Funcion::setSala(Sala* sala){
  this->sala = sala;
}

Funcion::~Funcion(){
  IIterator* i = reservas->getIterator(); 
  while(i->hasCurrent()){
      Reserva* r = (Reserva*) i->getCurrent();
      delete r;
  }
  delete i;
  delete reservas;
}
