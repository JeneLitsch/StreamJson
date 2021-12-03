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

char nextChar(std::istream & in) {
	if(in.peek() == '\\') {
		in.ignore(); // ignore "\"
		switch (in.get()) {
		case '"':	return '"';
		case '\\':	return '\\';
		case '/':	return '/';
		case 'n':	return '\n';
		case 't':	return '\t';
		default:
			throw std::runtime_error("Invalid Escape sequence");
		}
	}
	return static_cast<char>(in.get());
}

std::string json::readString(std::istream & in) {
	if(!match(in, '"')) {
		throw std::runtime_error("Missing \" before string");
	}
	std::stringstream ss;
	while(true) {
		
		if(in.eof()) 
			throw std::runtime_error("Unterminated String");
		
		if(in.peek() == '\n' || in.peek() == '\t')
			throw std::runtime_error("Special character must be escapes");

		else if(in.peek() == '"') {
			in.ignore();
			break;
		}
		ss << nextChar(in);
	}
	return ss.str();
}

void json::writeString(std::ostream & out, std::string_view str) {
	out << "\"";
	for(char chr : str) {
		switch (chr) {
		case '"':  	out << "\\\"";	break;
		case '\\': 	out << "\\\\";	break;
		case '\n': 	out << "\\n";	break;
		case '\t': 	out << "\\t";	break;
		default:	out << chr;		break;
		}
	}
	out << "\"";
}
