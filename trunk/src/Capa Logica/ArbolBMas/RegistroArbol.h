/*
 * RegistroArbol.h
 *
 *  Created on: 13/11/2014
 *      Author: joaquin
 */

#ifndef REGISTROARBOL_H_
#define REGISTROARBOL_H_

#include <iostream>
#include "string.h"
#include <list>
#include "Clave.h"

using namespace std;


class RegistroArbol {

private:

	Clave clave;
	string valor;

public:


	RegistroArbol();
	RegistroArbol(Clave, string);
	virtual ~RegistroArbol();

	int agregar(Clave, string);
	int borrar(Clave , string);
	bool existe(string);
	int persistir (char* bloque);
	RegistroArbol* hidratar(char* bloque);

	void mostrar();
	void setClave(string clave);
	void setValor(string valor);
	Clave getClaveEntera();
	string getClave();
	string getValor();
	int getTamanioClave();
	int getTamanioValor();
	int cantidadDeBytesOcupados();
};



#endif /* REGISTROARBOL_H_ */
