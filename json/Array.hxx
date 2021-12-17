#pragma once
#include "json/Node.hxx"
#include <vector>
namespace json {
	class Value;
	class Object;
	class Array : public Node {
	public:
		Array() = default;
		Array(Array &&) = default;
		virtual ~Array() = default;

		const Node & get(std::size_t idx) const;
		void push_back(std::unique_ptr<Node> && value);
		std::size_t size() const;

		// JSON 
		virtual void readFromStream(std::istream & in) override;
		virtual void writeToStream(std::ostream & out) const override;
	private:
		std::vector<std::unique_ptr<Node>> values;
	};

}