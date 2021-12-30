#pragma once
#include "Value.hxx"
#include "Array.hxx"
#include "Object.hxx"
namespace json::lookup {
	const std::string * string(const Object & obj, const std::string_view key);
	const std::string * string(const Array & arr, std::size_t idx);

	std::optional<double> number(const Object & obj, const std::string_view key);
	std::optional<double> number(const Array & arr, std::size_t idx);
	
	std::optional<bool> boolean(const Object & obj, const std::string_view key);
	std::optional<bool> boolean(const Array & arr, std::size_t idx);
	
	const Object * object(const Object & obj, const std::string_view key);
	const Object * object(const Array & arr, std::size_t idx);
	
	const Array * array(const Object & obj, const std::string_view key);
	const Array * array(const Array & arr, std::size_t idx);
}