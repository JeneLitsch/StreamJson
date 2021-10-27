#include "json/Json.hxx"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
	std::ifstream ifile("demo/test.json");
	std::ofstream ofile("demo/test2.json");
	auto json = json::init();
	ifile >> *json;
	ofile << *json;
	return 0;
}
