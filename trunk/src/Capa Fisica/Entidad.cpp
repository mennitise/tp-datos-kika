#include "Entidad.h"
#include <cstdlib>

Entidad::Entidad(list<metaDataAtributo>* listaAtributos,string nombre, int ID,TipoArchivo tipoArchivo){
	this->listaAtributos = listaAtributos;
	this->nombre = nombre;
	this->ID = ID;
	this->ultimoIDInstancia = 0;
	int tam = 0;
	for(list<metaDataAtributo>::iterator it = listaAtributos->begin(); it != listaAtributos->end();it++){
		tam += it->cantidadBytes;
	}
	if (tipoArchivo == FIJO) this->archivo = new ArchivoRegistroFijo(nombre,tam);
	else if (tipoArchivo == VARIABLE) this->archivo = new ArchivoRegistroVariable(nombre);
	else if (tipoArchivo == DEBLOQUES) this->archivo = new ArchivoBloque(nombre,this->getTamanioMaxInstancia());
	this->tipoArchivo = tipoArchivo;
}

Entidad::~Entidad(){
	delete this->listaAtributos;
	delete this->archivo;
	this->instancias.clear();
}

list<metaDataAtributo>* Entidad::getListaAtributos(){
	return this->listaAtributos;
}

string Entidad::getNombre(){
	return this->nombre;
}

int Entidad::getID(){
	return this->ID;
}

void Entidad::crearInstancia(list<Atributo>* listaDatos){
	Instancia* instancia = new Instancia(this->listaAtributos);
	instancia->setListaAtributos(listaDatos);
	this->instancias.push_back(instancia);
	this->archivo->escribir(listaDatos,this->listaAtributos);
	++this->ultimoIDInstancia;
}

void Entidad::leerInstancias(){
	for (int i = 0; i < this->archivo->getCantidad(); i++) {
		list<Atributo>* listaDatosAtributos = this->archivo->leer(i,this->listaAtributos);
		if (listaDatosAtributos != NULL) { //Si es null no hay ninguna instancia en ese registro/bloque (para fijos y bloques)

			if ((listaDatosAtributos->size() % this->listaAtributos->size()) == 0) {	//Se leyo una cant entera de instancias
				int cantidadInstancias = listaDatosAtributos->size() / this->listaAtributos->size();
				list<Atributo>::iterator it = listaDatosAtributos->begin();
				for (int i = 0; i < cantidadInstancias; i++) {
					Instancia* instancia = new Instancia(this->listaAtributos);
					list<Atributo>* listaNueva = new list<Atributo>;
					for (unsigned int i = 0; i < this->listaAtributos->size() && it != listaDatosAtributos->end(); it++,i++) {
						listaNueva->push_back(*it);
					}
					instancia->setListaAtributos(listaNueva);
					this->instancias.push_back(instancia);
					if(this->ultimoIDInstancia < instancia->getID()) this->ultimoIDInstancia = instancia->getID();
				}
				delete listaDatosAtributos;
			}
		}
	}
}

void Entidad::listarInstancias(){
	for (unsigned int i = 0; i < this->instancias.size(); i++) {
		list<metaDataAtributo>::iterator it3 = this->listaAtributos->begin();
		for (list<Atributo>::iterator it2 = this->instancias[i]->getListaAtributos()->begin(); it2 != this->instancias[i]->getListaAtributos()->end();it2++,it3++){
			cout<<it3->nombre<<": ";
			if (it3->tipo == TEXTO) {
				cout<<it2->texto<<" ";
			} else {
				cout<<it2->entero<<" ";
			}
		}
		cout<<endl;
	}
}

void Entidad::eliminarInstancia(int id_instancia) {
	int encontrado = this->archivo->borrar(id_instancia);
	if (encontrado == 1) {
		for (unsigned int i = 0; i < this->instancias.size();i++) {
			if (this->instancias[i]->getID() == id_instancia){
				this->instancias.erase(this->instancias.begin() + i);
			}
		}
	} else {
		cout<<"Opcion ingresada es incorrecta"<<endl;
	}
}

void Entidad::eliminarInstancias(){
	// Borrar lista de instancias y el archivo.
	for(unsigned int i = 0; i < this->instancias.size(); i++){
		this->archivo->borrar(this->instancias[i]->getID());
	}
	this->instancias.clear();
}

void Entidad::modificarInstancia(int id_instancia, list<metaDataAtributo>* metaAtts, list<Atributo>* newAtts){

	Instancia* inst = this->getInstancia(id_instancia);
	this->archivo->modificarInstancia(id_instancia,newAtts,metaAtts);
	inst->setListaAtributos(newAtts);
}

int Entidad::getCantidadInstancias(){
	return this->instancias.size();
}

Instancia* Entidad::getInstancia(int id){
	for(unsigned int i = 0; i < this->instancias.size(); i++){
		if(this->instancias[i]->getID() == id){
			return this->instancias[i];
		}
	}
	return NULL;
}

int Entidad::getCantidad(){
	return this->archivo->getCantidad();
}

int Entidad::getUltimoIDInstancia(){
	return this->ultimoIDInstancia;
}


int Entidad::getTamanioMaxInstancia(){
	int tamanio = 0;
	for (list<metaDataAtributo>::iterator it = this->listaAtributos->begin(); it != this->listaAtributos->end();it++){
		if (it->tipo == TEXTO) {
			tamanio += it->cantidadBytes + 1; //+1 por el caracter separador
		} else {
			tamanio += it->cantidadBytes;
		}
	}
	return tamanio;
}

TipoArchivo Entidad::getTipoArchivo() {
	return this->tipoArchivo;
}

