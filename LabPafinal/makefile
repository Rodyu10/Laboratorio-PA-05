#Compila todo
#Objetivo: Dependencia
#	Comando
CC=g++ -std=c++11
CFLAGS= -c -Wall
all: Lab


Lab: main.o Cine.o Credito.o Debito.o Funcion.o Pelicula.o Reserva.o Usuario.o DtFecha.o DtPelicula.o DtUsuario.o DtReserva.o DtFuncion.o DtCine.o DtCredito.o DtDebito.o ICollectible.o ICollection.o IIterator.o IDictionary.o IKey.o IOrederdKey.o
	$(CC) main.o Cine.o Credito.o Debito.o Funcion.o Pelicula.o Reserva.o Usuario.o DtFecha.o DtPelicula.o DtUsuario.o DtReserva.o DtFuncion.o DtCine.o DtCredito.o DtDebito.o ICollectible.o ICollection.o IIterator.o IDictionary.o IKey.o IOrederdKey.o -o Lab

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Cine.o: ./Clases/Source/Cine.cpp  ./Clases/Headers/Cine.h
	$(CC) $(CFLAGS) ./Clases/Source/Cine.cpp

Credito.o: ./Clases/Source/Credito.cpp ./Clases/Headers/Credito.h
	$(CC) $(CFLAGS) ./Clases/Source/Credito.cpp

Debito.o: ./Clases/Source/Debito.cpp ./Clases/Headers/Debito.h
	$(CC) $(CFLAGS) ./Clases/Source/Debito.cpp

Funcion.o: ./Clases/Source/Funcion.cpp ./Clases/Headers/Funcion.h
	$(CC) $(CFLAGS) ./Clases/Source/Funcion.cpp

Pelicula.o: ./Clases/Source/Pelicula.cpp ./Clases/Headers/Pelicula.h
	$(CC) $(CFLAGS) ./Clases/Source/Pelicula.cpp

Reserva.o: ./Clases/Source/Reserva.cpp ./Clases/Headers/Reserva.h
	$(CC) $(CFLAGS) ./Clases/Source/Reserva.cpp

Usuario.o: ./Clases/Source/Usuario.cpp ./Clases/Headers/Usuario.h
	$(CC) $(CFLAGS) ./Clases/Source/Usuario.cpp

DtFecha.o: ./Datatypes/Source/DtFecha.cpp ./Datatypes/Headers/DtFecha.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtFecha.cpp

DtPelicula.o: ./Datatypes/Source/DtPelicula.cpp ./Datatypes/Headers/DtPelicula.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtPelicula.cpp

DtUsuario.o: ./Datatypes/Source/DtUsuario.cpp ./Datatypes/Headers/DtUsuario.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtUsuario.cpp

DtFuncion.o: ./Datatypes/Source/DtFuncion.cpp ./Datatypes/Headers/DtFuncion.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtFuncion.cpp

DtReserva.o: ./Datatypes/Source/DtReserva.cpp ./Datatypes/Headers/DtReserva.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtReserva.cpp

DtCine.o: ./Datatypes/Source/DtCine.cpp ./Datatypes/Headers/DtCine.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtCine.cpp

DtCredito.o: ./Datatypes/Source/DtCredito.cpp ./Datatypes/Headers/DtCredito.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtCredito.cpp

DtDebito.o: ./Datatypes/Source/DtDebito.cpp ./Datatypes/Headers/DtDebito.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/DtDebito.cpp

ICollectible.o: ./Datatypes/Source/ICollectible.cpp ./Datatypes/Headers/ICollectible.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/ICollectible.cpp

ICollection.o: ./Interfaces/Source/ICollection.cpp ./Datatypes/Headers/ICollection.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/ICollection.cpp

IIterator.o: ./Interfaces/Source/IIterator.cpp ./Datatypes/Headers/IIterator.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/IIterator.cpp

IDictionary.o: ./Interfaces/Source/IDictionary.cpp ./Datatypes/Headers/IDictionary.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/IDictionary.cpp

IKey.o: ./Interfaces/Source/IKey.cpp ./Datatypes/Headers/IKey.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/IKey.cpp

IOrederdKey.o: ./Interfaces/Source/IOrderedKey.cpp ./Datatypes/Headers/IOrederedKey.h 
	$(CC) $(CFLAGS) ./Datatypes/Source/IOrderedKey.cpp

clean:
	rm -rf *o Lab
