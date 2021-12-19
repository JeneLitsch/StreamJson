#pragma once
#include <optional>
#include "Object.hxx"
#include "Array.hxx"
#include "Value.hxx"

namespace json::extract {
	const std::string & string(const Object & obj, const std::string_view key);
	const std::string & string(const Array & arr, const std::size_t idx);
	
	double number(const Object & obj, const std::string_view key);
	double number(const Array & arr, const std::size_t idx);
	
	bool boolean(const Object & obj, const std::string_view key);
	bool boolean(const Array & arr, const std::size_t idx);
	
	const Object & object(const Object & obj, const std::string_view key);
	const Object & object(const Array & arr, const std::size_t idx);
	
	const Array & array(const Object & obj, const std::string_view key);
	const Array & array(const Array & arr, const std::size_t idx);
}