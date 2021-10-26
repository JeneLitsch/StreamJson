#include "json/Json.hxx"
#include <iostream>
#include <sstream>
int main() {
	std::stringstream ss{"{ \"a\" : 4, \"b\" : 42 }"};
	json::Object json;
	ss >> json;
	std::cout << json << "\n";
	return 0;
}
