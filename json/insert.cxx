#include "insert.hxx"

void json::insert::string(
	Object & obj,
	const std::string_view key,
	const std::string_view str) {
	obj.insert(key, std::make_unique<Value>(std::string(str)));
}

void json::insert::number(
	Object & obj,
	const std::string_view key,
	const double number) {
	obj.insert(key, std::make_unique<Value>(number));
}

void json::insert::boolean(
	Object & obj,
	const std::string_view key,
	const bool value) {
	obj.insert(key, std::make_unique<Value>(value));
}

void json::insert::array(
	Object & obj,
	const std::string_view key,
	std::unique_ptr<Array> && array) {
	obj.insert(key, std::move(array));
}


void json::insert::object(
	Object & obj,
	const std::string_view key,
	std::unique_ptr<Object> && object) {
	obj.insert(key, std::move(object));
}
