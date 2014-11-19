/*
 * AdminIndicesSecundarios.cpp
 *
 *  Created on: 17/11/2014
 *      Author: joaquin
 */


#include "AdminIndicesSecundarios.h"
#include "../Capa Logica/ArbolBMas/ArbolBMas.h"

void AdministradorIndices::listar_indices(){

}

void AdministradorIndices::eliminar_indice(int x){

}
 void AdministradorIndices::crear_indice(Entidad* entidad){
	 cout << "Ingrese el nombre del indice secundario: " << endl;
	 string nombre;	 cin >> nombre;
	 cout << "Ingrese el tipo de estructura para el indice secundario:" << endl;
	 cout << "1 - Arbol B+" << endl;
	 cout << "2 - Hash" << endl;
	 int tipo; cin >> tipo;
	 //VALIDAR SI INGRESA HASH O ARBOL

	 ArbolBMas* estructura = new ArbolBMas(nombre);
	 cout << "Ingrese los atributos que formaran parte del indice:" << endl;
	 entidad->listarAtributos();
	 int x; cin >> x;
	 metaDataAtributo* atributo = entidad->getAtributo(x);
	 //PEDIR MAS ATRIBUTOS
	 cout<<":O"<<endl;
	 for (int i = 1; i <= entidad->getUltimoIDInstancia(); ++i) {
		bool error;
		Instancia* nuevaInstancia = entidad->getInstancia(i,error);
		if (!error) {
			Atributo* atributoInstancia = nuevaInstancia->getAtributo(x);
			if (atributo->tipo == TEXTO) {
				cout<<":O"<<endl;
				estructura->agregarValor(*(new Clave(atributoInstancia->texto)),StringUtil::int2string(i));
				estructura->persistir();
			} else {
				estructura->agregarValor(*(new Clave(StringUtil::int2string(atributoInstancia->entero))),StringUtil::int2string(i));
				estructura->persistir();
			}
		}
	 }
	estructura->mostrarArbol();

}