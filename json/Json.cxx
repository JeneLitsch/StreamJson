#include "Json.hxx"

std::unique_ptr<json::Value> json::init() {
	return std::make_unique<Value>();
}
