#include "lookup.hxx"
#include "extract.hxx"
namespace json::lookup {

	const std::string * string(const Object & obj, const std::string_view key) {
		try { return &extract::string(obj, key); }
		catch(...) { return nullptr; }
	}


	std::optional<double> number(const Object & obj, const std::string_view key) {
		try { return extract::number(obj, key); }
		catch(...) { return {}; }
	}


	std::optional<bool> boolean(const Object & obj, const std::string_view key) {
		try { return extract::boolean(obj, key); }
		catch(...) { return {}; }
	}


	const Object * object(const Object & obj, const std::string_view key) {
		try { return &extract::object(obj, key); }
		catch(...) { return nullptr; }
	}


	const Array * array(const Object & obj, const std::string_view key) {
		try { return &extract::array(obj, key); }
		catch(...) { return nullptr; }
	}



	const std::string * string(const Array & arr, std::size_t idx) {
		try { return &extract::string(arr, idx); }
		catch(...) { return nullptr; }
	}


	std::optional<double> number(const Array & arr, std::size_t idx) {
		try { return extract::number(arr, idx); }
		catch(...) { return {}; }
	}


	std::optional<bool> boolean(const Array & arr, std::size_t idx) {
		try { return extract::boolean(arr, idx); }
		catch(...) { return {}; }
	}


	const Object * object(const Array & arr, std::size_t idx) {
		try { return &extract::object(arr, idx); }
		catch(...) { return nullptr; }
	}


	const Array * array(const Array & arr, std::size_t idx) {
		try { return &extract::array(arr, idx); }
		catch(...) { return nullptr; }
	}

}