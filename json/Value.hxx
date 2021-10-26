#pragma once
#include <variant>
#include <concepts>
#include "json/Node.hxx"
namespace json {
	class Object;
	class Array;
	class Value : public Node {
	public:
		Value(std::istream & in);
		Value(bool value);
		Value(int value);
		Value(long value);
		Value(float value);
		Value(double value);
		Value(const std::string & value);
		Value(std::nullptr_t);
		Value(std::unique_ptr<Array> && value);
		Value(std::unique_ptr<Object> && value);

		bool isNull() const;
		bool getBool() const;
		double getNumber() const;
		const std::string & getString() const;
		const Array & getArray() const;
		const Object & getObject() const;

		virtual void readFromStream(std::istream & in) override;
		virtual void writeToStream(std::ostream & out) override;

	private:
		std::variant<
			std::monostate,
			bool,
			double,
			std::string,
			std::unique_ptr<Object>, 
			std::unique_ptr<Array>> value; 
	};
}