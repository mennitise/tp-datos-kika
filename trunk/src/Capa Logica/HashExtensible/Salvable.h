#ifndef SALVABLE_H_
#define SALVABLE_H_

#include "../../Capa Fisica/Archivos/Bloques/Bloques.h"
#include "../../Capa Fisica/Excepciones/ExcepcionOverflowTamBloque.h"
#include <string>

using namespace std;

class Salvable {

private:
	ArchivoBloque* archivo;

public:
	Salvable(const string& ruta);
	virtual ~Salvable();

protected:
	void leerBloque(const int& numBloque,string* buffer)const;
	void escribirBloque(const string& bloque, const unsigned int& numBloque);
	const unsigned int getCantidadDeBloques ()const;
};

#endif /* SALVABLE_H_ */
