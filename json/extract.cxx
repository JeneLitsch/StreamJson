#include "extract.hxx"

namespace {

	const json::Value & getValue(const auto & node, auto at, auto errorMSG) {
		const auto * value =  dynamic_cast<const json::Value *>(&node.get(at));
		if(value) {
			return *value;
		}
		throw std::runtime_error(errorMSG);
	}

	const json::Value & getValue(const json::Object & obj, const std::string_view key) {
		return getValue(obj, key, 
			std::string(key) + " is not a value");
	}

	const json::Value & getValue(const json::Array & arr, std::size_t idx) {
		return getValue(arr, idx, 
			"At pos " + std::to_string(idx) + " is not a value");
	}
}

const std::string & json::extract::string(
	const Object & obj, 
	const std::string_view key) {
	return getValue(obj, key).getString();
}

const std::string & json::extract::string(
	const Array & arr, 
	std::size_t idx) {
	return getValue(arr, idx).getString();
}

double json::extract::number(
	const Object & obj, 
	const std::string_view key) {
	return getValue(obj, key).getNumber();
}

double json::extract::number(
	const Array & arr, 
	std::size_t idx) {
	return getValue(arr, idx).getNumber();
}

bool json::extract::boolean(
	const Object & obj, 
	const std::string_view key) {
	return getValue(obj, key).getBool();
}

bool json::extract::boolean(
	const Array & arr, 
	std::size_t idx) {
	return getValue(arr, idx).getBool();
}

const json::Object & json::extract::object(
	const Object & obj, 
	const std::string_view key) {
	return getValue(obj, key).getObject();
}

const json::Object & json::extract::object(
	const Array & arr, 
	std::size_t idx) {
	return getValue(arr, idx).getObject();
}

const json::Array & json::extract::array(
	const Object & obj, 
	const std::string_view key) {
	return getValue(obj, key).getArray();
}

const json::Array & json::extract::array(
	const Array & arr, 
	std::size_t idx) {
	return getValue(arr, idx).getArray();
}



