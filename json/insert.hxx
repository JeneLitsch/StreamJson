#pragma once
#include "Object.hxx"
#include "Array.hxx"
#include "Value.hxx"

namespace json::insert {
	void string(
		Object & obj,
		const std::string_view key,
		const std::string_view str);
	
	void number(
		Object & obj,
		const std::string_view key,
		const double number);
	
	void boolean(
		Object & obj,
		const std::string_view key,
		const bool value);
	
	void array(
		Object & obj,
		const std::string_view key,
		std::unique_ptr<Array> && array);
	
	void object(
		Object & obj,
		const std::string_view key,
		std::unique_ptr<Object> && object);
}