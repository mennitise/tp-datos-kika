#ifndef ARCHIVO_REGISTRO_VARIABLE
#define ARCHIVO_REGISTRO_VARIABLE

#include "../Archivo.h"

using namespace std;

struct espacioInstancia{
	int inicio;
	int fin;
};

class ArchivoRegistroVariable: public Archivo {
private:

public:
	ArchivoRegistroVariable(string nombre);
	~ArchivoRegistroVariable();
	list<Atributo>* leer(int numero,list<tamanioYTipoAtributo>* listaTipoAtributos);
	void escribir(list<Atributo>* atributos, list<tamanioYTipoAtributo>* listaTipoAtributos);
	void borrar(int numero);
	int getCantidad();

private:
	vector<espacioInstancia> vectorMapaBits;
	int cantInstancias;
	int proximoEspacioLibre(int tamanioInstancia);
	void leerMapaBits();
	void escribirMapaBits();
};

#endif