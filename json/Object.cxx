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
		std::unique_ptr<Value> && value = std::make_unique<Value>(in);
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

const json::Value & json::Object::get(const std::string_view key) const {
	return *this->dict.at(std::string(key));
}

json::Value & json::Object::get(const std::string_view key) {
	return *this->dict.at(std::string(key));
}

void json::Object::insert(
	const std::string_view key,
	std::unique_ptr<Value> && value) {
	this->dict.insert({std::string(key), std::move(value)});
}

bool json::Object::contains(const std::string_view key) const {
	return this->dict.contains(std::string(key));
}