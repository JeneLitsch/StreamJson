#include "json/Json.hxx"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
	std::stringstream ss{"{ \"a\" : 4, \"b\" : \"Hello World\" }"};
	std::ifstream file("demo/test.json");
	json::Object json;
	file >> json;
	std::cout << json << "\n";
	return 0;
}
