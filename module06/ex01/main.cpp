#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;
	data.id = 42;
	data.name = "Forty-Two";
	data.value = 42.42;

	Data* original = &data;

	uintptr_t raw = Serializer::serialize(original);
	Data*	back = Serializer::deserialize(raw);

	std::cout << "Original: " << original << std::endl;
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "Deserialized: " << back << std::endl;

	if (original == back) {
		std::cout << "Pointers are equal!" << std::endl;
		std::cout << "Data contents: {" << back->id << ", " << back->name << ", " << back->value << "}" << std::endl; 
	} else {
		std::cout << "Pointers differ! Instant fail!" << std::endl;
	}
	return 0;
}
