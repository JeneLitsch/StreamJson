#include "Array.hxx"
#include "Value.hxx"
#include "Object.hxx"
#include <iostream>

json::Array::Array(std::istream & in) {
	in >> *this;
}

void json::Array::readFromStream(std::istream & in) {
	this->values.clear();
	if(!match(in, '[')) {
		throw std::runtime_error("Array mmust begin with [");
	}
	if(match(in, ']')) {
		return;
	}
	else while (true) {
		std::unique_ptr<Value> && value = std::make_unique<Value>(in);
		this->values.push_back(std::move(value));
		if(in.eof()) {
			throw std::runtime_error("Unterminated Array");
		}
		if(match(in, ']')) break;
		if(!match(in, ',')) {
			throw std::runtime_error("Expectd comma between elements in array");
		}
	}
}

void json::Array::writeToStream(std::ostream & out) {
	out << "[";
	bool first = true;
	for(const auto & element : this->values) {
		if(first) {
			first = false;
		}
		else {
			out << ", ";
		}
		out << *element;
	}
	out << "]";
}

const json::Value & json::Array::operator[](std::size_t idx) const {
	return *this->values[idx];
}

std::size_t json::Array::size() const {
	return this->values.size();
}