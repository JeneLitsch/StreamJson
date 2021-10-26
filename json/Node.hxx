#pragma once
#include <memory>
#include <istream>
namespace json {
	class Node {
	public:
		virtual void readFromStream(std::istream & in) = 0;
		virtual void writeToStream(std::ostream & out) = 0;
	protected:
	};
	bool match(std::istream & in, char chr);
	bool match(std::istream & in, const std::string_view str);
	bool check(std::istream & in, char chr);
	std::string readString(std::istream & in);
	std::istream & operator>>(std::istream & in, Node & value);
	std::ostream & operator<<(std::ostream & out, Node & value);
}