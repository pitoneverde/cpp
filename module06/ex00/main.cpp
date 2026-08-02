#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	// std::string has implicit constructor from const char*
	ScalarConverter::convert(argv[1]);
	return 0;
}
