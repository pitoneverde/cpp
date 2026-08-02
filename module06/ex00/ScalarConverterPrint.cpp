#include "ScalarConverter.hpp"

// nan is the only value not equal to itself
static bool isNan(double val) {return val != val;}

static bool isInf(double val) {
	return val == std::numeric_limits<double>::infinity()
		|| val == -std::numeric_limits<double>::infinity();
}

static bool isWhole(double val) {
	double intPart;
	return modf(val, &intPart) == .0;
}

void ScalarConverter::printConversions(const char c) {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void ScalarConverter::printConversions(const int i) {
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(i)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;

	// precision loss is acceptable, but static_cast never introduces a fractional part
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}
void ScalarConverter::printConversions(const float f) {
	// print CHAR
	const double d = static_cast<double>(f);
	// used for all types in order
	bool isImpossible = isNan(d) || isInf(d) || !isWhole(d);
	if (isImpossible)
		std::cout << "char: impossible" << std::endl;
	else {
		int i = static_cast<int>(d);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<unsigned char>(i)))
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}

	// print INT
	isImpossible = isNan(d) || isInf(d)
		|| d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max();
	if (isImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	// print FLOAT
	if(isNan(d))
		std::cout << "float: nanf" << std::endl;
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "float: inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (isWhole(d))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	// print DOUBLE
	if(isNan(d))
		std::cout << "double: nan" << std::endl;
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "double: inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (isWhole(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
 
}
void ScalarConverter::printConversions(const double d) {
	// print CHAR
	// used for all types in order
	bool isImpossible = isNan(d) || isInf(d) || !isWhole(d);
	if (isImpossible)
		std::cout << "char: impossible" << std::endl;
	else {
		int i = static_cast<int>(d);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<unsigned char>(i)))
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}

	// print INT
	isImpossible = isNan(d) || isInf(d)
		|| d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max();
	if (isImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	// print FLOAT
	if(isNan(d))
		std::cout << "float: nanf" << std::endl;
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "float: inff" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else {
		float f = static_cast<float>(d);
		if (isWhole(d))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}

	// print DOUBLE
	if(isNan(d))
		std::cout << "double: nan" << std::endl;
	else if (d == std::numeric_limits<double>::infinity())
		std::cout << "double: inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (isWhole(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printAllImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
