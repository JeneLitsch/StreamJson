#pragma once
#include <unordered_map>
#include "json/Node.hxx"
namespace json {
	class Value;
	class Object : public Node {
	public:
		virtual ~Object() = default;
		virtual void readFromStream(std::istream & in) override;
		virtual void writeToStream(std::ostream & out) override;

		const Value & get(const std::string_view key) const;
		Value & get(const std::string_view key);
		
		void insert(const std::string_view key, std::unique_ptr<Value> && value);
		
		bool contains(const std::string_view key) const; 
	
	private:
		std::unordered_map<std::string, std::unique_ptr<Value>> dict;
	};
}