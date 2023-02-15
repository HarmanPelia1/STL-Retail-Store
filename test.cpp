#include "util.h"
using namespace std; 

int main() {
	std::string line = "hello,my-name.is..Herman, i love cock";

	std::set<std::string> list = parseStringToWords(line);

	std::set<std::string>::iterator it;
	for(it = list.begin(); it != list.end(); it++)
		cout << *it << endl; 
}