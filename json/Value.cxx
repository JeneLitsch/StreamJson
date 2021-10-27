#include "Value.hxx"
#include "Array.hxx"
#include "Object.hxx"
#include <sstream>
#include <iostream>

json::Value::Value(bool value){
	this->value = value;
}

json::Value::Value(int value){
	this->value = static_cast<double>(value);
}

json::Value::Value(long value){
	this->value = static_cast<double>(value);
}

json::Value::Value(float value){
	this->value = static_cast<double>(value);
}

json::Value::Value(double value){
	this->value = value;
}

json::Value::Value(const std::string & value){
	this->value = value;
}

json::Value::Value(std::nullptr_t){
	this->value = {};
}

json::Value::Value(std::unique_ptr<Array> && value){
	this->value = std::move(value);
}

json::Value::Value(std::unique_ptr<Object> && value){
	this->value = std::move(value);
}

bool json::Value::isNull() const {
	return std::holds_alternative<std::monostate>(this->value);
}

bool json::Value::getBool() const {
	return std::get<bool>(this->value);
}

double json::Value::getNumber() const {
	return std::get<double>(this->value);
}

const std::string & json::Value::getString() const {
	return std::get<std::string>(this->value);
}

const json::Array & json::Value::getArray() const {
	return *std::get<std::unique_ptr<Array>>(this->value);
}

const json::Object & json::Value::getObject() const {
	return *std::get<std::unique_ptr<Object>>(this->value);
}

void json::Value::readFromStream(std::istream & in) {
	in >> std::ws;
	if(check(in, '{')) {
		auto && object = std::make_unique<Object>(); 
		in >> *object; 
		this->value = std::move(object); 
	}
	
	else if(check(in, '[')) {
		auto && array = std::make_unique<Array>(); 
		in >> *array; 
		this->value = std::move(array); 
	}
	
	else if(in.peek() == '"') {
		this->value = readString(in);
	}
	
	else if(std::isdigit(in.peek()) || match(in, '-') || match(in, '-')) {
		double number;
		in >> number;
		this->value = number;
	}
	
	else if(match(in, "true")) {
		this->value = true;
	}

	else if(match(in, "false")) {
		this->value = false;
	}

	else if(match(in, "null")) {
		this->value = std::monostate();
	}

	else {
		throw std::runtime_error("Error while parsing");
	}
}


void json::Value::writeToStream(std::ostream & out) {
	struct Vistor {
		void operator()(bool b) { 
			out << std::boolalpha << b;
		};
		
		void operator()(double value) {
			out << value;
		}; 
		
		void operator()(const std::string & value) {
			writeString(out, value);
		};
		
		void operator()(const std::monostate &) {
			out << "null";
		};

		void operator()(const std::unique_ptr<Array> & array) {
			out << *array;
		};

		void operator()(const std::unique_ptr<Object> & object) {
			out << *object;
		};
		
		std::ostream & out;
	} vistor{out};

	std::visit(vistor, this->value);
}
