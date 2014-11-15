/*
 * Nodo.cpp
 *
 *  Created on: 13/11/2014
 *      Author: joaquin
 */

#include "Nodo.h"
#include "NodoInterno.h"
#include "NodoHoja.h"

unsigned int Nodo::tamanioMaximoBloque;

Nodo::Nodo() {
	this->cantidadDeElementos = 0;
	this->nivel = 0;
	this->NumeroDeBloque = 0;
	this->tamanioMaximoBloque = TAMANIOBLOQUE_DEFAULT;
}


Nodo::~Nodo() {

}


unsigned int Nodo::getCantidadDeElementos(){
		return (this->cantidadDeElementos);
}


unsigned int Nodo::getNumeroDeBloque(){
	return this->NumeroDeBloque;
}


int Nodo::getTamanioUnderflow(){
	return tamanioMaximoBloque * 0.25;
}


int Nodo::getTamanioOverflow(){
	return tamanioMaximoBloque * 0.8;
}


void Nodo::setNumeroDeBloque(unsigned int numeroDeBloque){
	this->NumeroDeBloque = numeroDeBloque;
}


unsigned int Nodo::getNivel(){
		return(this->nivel);
}


void Nodo::setNivel(unsigned int nivel){
	this->nivel = nivel;
}


void Nodo::setCantidadDeElementos(unsigned int cantidad){
	this->cantidadDeElementos = cantidad;
}


Nodo* Nodo::cargar(ArchivoBloque* archivo, unsigned int indice){

	char* bloque = new char[archivo->getTamanoBloque()];
	archivo->leer(bloque, indice);
	unsigned int tamanioInt = sizeof(unsigned int);

	unsigned int nivel;
	memcpy((char*)&nivel,bloque, tamanioInt);

	if (nivel == 0){
		//Es hoja
		return NodoHoja::cargar(archivo, indice);
	}else {
		//Es interno
		return NodoInterno::cargar(archivo, indice);
	}
}


void Nodo::incrementarNivel(){this->nivel++;}


void Nodo::decrementarNivel(){this->nivel--;}


void Nodo::incrementarCantidadDeElementos(){
	this->setCantidadDeElementos((this->getCantidadDeElementos())+1);
}


void Nodo::decrementarCantidadDeElementos(){
	this->setCantidadDeElementos((this->getCantidadDeElementos())-1);;
}


//Redefinidos en los hijos:
void Nodo::persistir(ArchivoBloque*& archivo){}

int Nodo::tamanioOcupado(){return 0;}

bool Nodo::hayOverflow(){return 0;}

bool Nodo::hayUnderflow(){return 0;}

bool Nodo::estaVacio(){return 0;}



