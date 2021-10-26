#include "Node.hxx"
#include <sstream>

bool json::match(std::istream & in, const std::string_view str) {
	for(char chr : str) {
		if(!match(in, chr)) return false; 
	}
	return true;
}

bool json::match(std::istream & in, char chr) {
	const bool matches = check(in, chr);
	if(matches) {
		in.ignore();
	}
	return matches;
}

bool json::check(std::istream & in, char chr) {
	in >> std::ws;
	return in.peek() == chr;
}

std::istream & json::operator>>(std::istream & in, Node & node) {
	node.readFromStream(in);
	return in;
}


std::ostream & json::operator<<(std::ostream & out, Node & node) {
	node.writeToStream(out);
	return out;
}

std::string json::readString(std::istream & in) {
	if(!match(in, '"')) {
		throw std::runtime_error("Missint \" before string");
	}
	std::stringstream ss;
	while(true) {
		if(in.eof()) throw std::runtime_error("Unterminated String");
		if(match(in, '"')) break;
		match(in, '\\');
		ss << static_cast<char>(in.get());
	}
	return ss.str();
}
