#pragma once
#include "json/Node.hxx"
#include <vector>
namespace json {
	class Value;
	class Array : public Node {
	public:
		Array() = default;
		virtual ~Array() = default;

		// C++ API
		const Value & operator[](std::size_t idx) const;
		std::size_t size() const;
		auto begin() { return this->values.begin(); }
		auto end() { return this->values.end(); }
		auto begin() const { return this->values.begin(); }
		auto cbegin() const { return this->values.cbegin(); }
		auto end() const { return this->values.end(); }
		auto cend() const { return this->values.cend(); }

		// JSON 
		virtual void readFromStream(std::istream & in) override;
		virtual void writeToStream(std::ostream & out) override;
	private:
		std::vector<std::unique_ptr<Value>> values;
	};

}