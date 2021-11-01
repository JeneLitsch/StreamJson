#include "Object.hxx"
#include "Value.hxx"
#include "Array.hxx"

void json::Object::readFromStream(std::istream & in) {
	this->dict.clear();
	if(!match(in, '{')) {
		throw std::runtime_error("Object mmust begin with {");
	}
	if(match(in, '}')) {
		return;
	}
	else while (true) {
		std::string key = readString(in);
		if(!match(in, ':')) {
			throw std::runtime_error("Expected : between and value");
		}
		std::unique_ptr<Value> && value = std::make_unique<Value>();
		in >> *value;
		this->dict.insert({key, std::move(value)});
		if(in.eof()) {
			throw std::runtime_error("Unterminated Object");
		}
		if(match(in, '}')) break;
		if(!match(in, ',')) {
			throw std::runtime_error("Expectd comma between elements in object");
		}
	}
}

void json::Object::writeToStream(std::ostream & out) {
	out << "{";
	bool first = true;
	for(const auto & pair : this->dict) {
		if(first) {
			first = false;
		}
		else {
			out << ", ";
		}
		writeString(out, pair.first);
		out << " : " << *pair.second;
	}
	out << "}";
}

const json::Node & json::Object::get(const std::string_view key) const {
	return *this->dict.at(std::string(key));
}

json::Node & json::Object::get(const std::string_view key) {
	return *this->dict.at(std::string(key));
}

void json::Object::insert(
	const std::string_view key,
	std::unique_ptr<Node> && value) {
	this->dict.insert({std::string(key), std::move(value)});
}

void json::Object::insert(
	const std::string_view key,
	const char * str) {
	this->insert(key, std::string(str));
}

void json::Object::insert(
	const std::string_view key,
	const std::string & str) {
	this->insert(key, std::make_unique<Value>(str));
}

void json::Object::insert(
	const std::string_view key,
	const std::string_view & str) {
	this->insert(key, std::string(str));
}

void json::Object::insert(
	const std::string_view key,
	const double number) {
	this->insert(key, std::make_unique<Value>(number));
}

void json::Object::insert(
	const std::string_view key,
	const bool value) {
	this->insert(key, std::make_unique<Value>(value));
}
