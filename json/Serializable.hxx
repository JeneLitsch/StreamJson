#pragma once
#include "Value.hxx"

namespace json {
	class Serializable {
	public:
		virtual void readJson(std::istream & in) = 0;
		virtual void writeJson(std::ostream & out) const = 0;
	};
	
	std::istream & operator>>(std::istream & in, Serializable & obj) {
		obj.readJson(in);
		return in;
	}	

	std::ostream & operator<<(std::ostream & out, const Serializable & obj) {
		obj.writeJson(out);
		return out;
	}
}