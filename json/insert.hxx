#pragma once
#include "Object.hxx"
#include "Array.hxx"
#include "Value.hxx"

namespace json::insert {
	void string(
		Object & obj,
		const std::string_view key,
		const std::string_view str);

	void string(
		Array & arr,
		const std::string_view str);
	


	void number(
		Object & obj,
		const std::string_view key,
		const double number);
	
	void number(
		Array & arr,
		const double number);



	void boolean(
		Object & obj,
		const std::string_view key,
		const bool value);
	
	void boolean(
		Array & arr,
		const bool value);



	void array(
		Object & obj,
		const std::string_view key,
		Array && array);
	
	void array(
		Array & arr,
		Array && array);



	void object(
		Object & obj,
		const std::string_view key,
		Object && object);

	void object(
		Array & arr,
		Object && object);	
}