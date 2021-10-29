#pragma once
#include "Value.hxx"

namespace json {
	class Printable {
	public:
		virtual std::unique_ptr<Node> toJson() const = 0;
	};

	class Readable {
	public:
		virtual void fromJson(const json::Node & value) = 0;
	};

	class Serializable : public Printable, public Readable {};
}