#include "insert.hxx"

namespace json::insert {
	void string(
		Object & obj,
		const std::string_view key,
		const std::string_view str) {
		obj.insert(key, std::make_unique<Value>(std::string(str)));
	}

	void string(
		Array & arr,
		const std::string_view str) {
		arr.push_back(std::make_unique<Value>(std::string(str)));
	}



	void number(
		Object & obj,
		const std::string_view key,
		const double number) {
		obj.insert(key, std::make_unique<Value>(number));
	}

	void number(
		Array & arr,
		const double number) {
		arr.push_back(std::make_unique<Value>(number));
	}

	
	
	void boolean(
		Object & obj,
		const std::string_view key,
		const bool value) {
		obj.insert(key, std::make_unique<Value>(value));
	}
	
	void boolean(
		Array & arr,
		const bool b) {
		arr.push_back(std::make_unique<Value>(b));
	}



	void array(
		Object & obj,
		const std::string_view key,
		Array && array) {
		auto && ptr = std::unique_ptr<Array>(new Array{std::move(array)});
		obj.insert(key, std::move(ptr));
	}

	void array(
		Array & arr,
		Array && array) {
		auto && ptr = std::unique_ptr<Array>(new Array{std::move(array)});
		arr.push_back(std::move(ptr));
	}


	void object(
		Object & obj,
		const std::string_view key,
		Object && object) {
		auto && ptr = std::unique_ptr<Object>(new Object{std::move(object)});
		obj.insert(key, std::move(ptr));
	}

	void object(
		Array & arr,
		Object && object) {
		auto && ptr = std::unique_ptr<Object>(new Object{std::move(object)});
		arr.push_back(std::move(ptr));
	}	
}

