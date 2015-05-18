#ifndef USERINPUT_H_
#define USERINPUT_H_

#include <cctype>
#include <ctype.h>
#include <cstring>
#include <iostream>
//#include <regex>
#include <sstream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtof */
#include <string>

namespace std {

class UserInput {
public:
	UserInput();
	~UserInput();

	static int readInt(string input);
	static double readDouble(string input);
	static string readString(string input);
	static char readChar(string input);
	static float readFloat(string input);

};

} /* namespace std */
#endif /* USERINPUT_H_ */
