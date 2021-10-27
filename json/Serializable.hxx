#pragma once
#include "Value.hxx"

namespace json {
	class Serializable {
	public:
		virtual void readJson(const json::Value & value) = 0;
		virtual std::unique_ptr<Value> writeJson() const = 0;
	};
}