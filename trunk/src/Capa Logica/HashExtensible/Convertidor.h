#ifndef CONVERTIDOR_H_
#define CONVERTIDOR_H_

#include <string>
#include <sstream>

using namespace std;

class Convertidor {

public:
	static int stringToInt(const string& valor);
	static string intToString(const int& valor);

};

#endif /* CONVERTIDOR_H_ */
