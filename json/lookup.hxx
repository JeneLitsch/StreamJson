#pragma once
#include "Value.hxx"
#include "Array.hxx"
#include "Object.hxx"
namespace json::lookup {
	const std::string * string(const Object & obj, const std::string_view key);
	std::optional<double> number(const Object & obj, const std::string_view key);
	std::optional<bool> boolean(const Object & obj, const std::string_view key);
	const Object * object(const Object & obj, const std::string_view key);
	const Array * array(const Object & obj, const std::string_view key);
}