#pragma once
#include "Node.hxx"
#include "Array.hxx"
#include "Object.hxx"
#include "Value.hxx"
#include "Serializable.hxx"

namespace json {
	std::unique_ptr<Value> init();
}