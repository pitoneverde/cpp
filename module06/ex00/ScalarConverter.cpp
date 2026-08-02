#include "ScalarConverter.hpp"

// BOILERPLATE

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

// HELPERS

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal) {
	// CHAR: must be exactly 3 chars: 'x' => quote + char + quote
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return TYPE_CHAR;

	// FLOAT: special pseudo-literals
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return TYPE_FLOAT;

	// DOUBLE: special pseudo-literals
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return TYPE_DOUBLE;
	
	// FLOAT: at least a digit and ends with 'f'
	if (!literal.empty() && literal[literal.length() - 1] == 'f') {
		bool hasDigit = false;
		for (size_t i = 0; i < literal.length() - 1; ++i)
		{
			// defensive cast to avoid UB because isdigit takes an int representing an unsigned char or EOF
			if (std::isdigit(static_cast<unsigned char>(literal[i]))) {
				hasDigit = true;
				break;
			}
		}
		if (hasDigit) return TYPE_FLOAT;
	}
	
	// DOUBLE: at least one digit and contains '.'
	bool hasDot = false;
	bool hasDigit = false;
	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '.') hasDot = true;
		if (std::isdigit(static_cast<unsigned char>(literal[i]))) hasDigit = true;
	}
	if (hasDot && hasDigit) return TYPE_DOUBLE;
	
	// INT: optional sign + digits only
	size_t start = 0;
	if (!literal.empty() && (literal[0] == '-' || literal[0] == '+')) start = 1;
	bool allDigits = (start < literal.length());	// not only a '-' or '+'
	for (size_t i = start; i < literal.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
			allDigits = false;
			break;
		}
	}
	if (allDigits) return TYPE_INT;
	
	// INVALID: everything else
	return TYPE_INVALID;	
}

// input guaranteed to be 'x' by detectType
char ScalarConverter::parseChar(const std::string& literal) {
	return literal[1];
}

int ScalarConverter::parseInt(const std::string& literal) {
	try {
		char* end;
		const char* str = literal.c_str();
		long value = std::strtol(str, &end, 10);
		if (end == str)
			throw std::invalid_argument("no conversion");
		if (*end !='\0')
			throw std::invalid_argument("trailing chars");
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::out_of_range("overflow");	
		return static_cast<int>(value);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 0;
	}
}

float ScalarConverter::parseFloat(const std::string& literal) {
	if (literal == "-inff")
		return -std::numeric_limits<float>::infinity();
	if (literal == "+inff")
		return std::numeric_limits<float>::infinity();
	if (literal == "nanf")
		return std::numeric_limits<float>::quiet_NaN();
	try {
		// strip trailing 'f'
		std::string num = literal.substr(0, literal.length() -1);
	
		char* end;
		const char* str = num.c_str();
		float f = std::strtof(str, &end);
		
		if (end == str)
			throw std::invalid_argument("no conversion");
		if (*end != '\0')
			throw std::invalid_argument("trailing chars");
		
		return f;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return .0f;
	}
}

double ScalarConverter::parseDouble(const std::string& literal) {
	if (literal == "-inf")
		return -std::numeric_limits<double>::infinity();
	if (literal == "+inf")
		return std::numeric_limits<double>::infinity();
	if (literal == "nan")
		return std::numeric_limits<double>::quiet_NaN();
	try {
		char* end;
		const char* str = literal.c_str();
		double d = std::strtod(str, &end);
		
		if (end == str)
			throw std::invalid_argument("no conversion");
		if (*end != '\0')
			throw std::invalid_argument("trailing chars");
		
		return d;
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return .0;
	}
}

// move to another file

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
	isImpossible == isNan(d) || isInf(d)
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
	isImpossible == isNan(d) || isInf(d)
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

// ENTRYPOINT

void ScalarConverter::convert(const std::string& literal) {
	ScalarConverter::e_type type = detectType(literal);
	switch (type) {
		case TYPE_CHAR: 	printConversions(parseChar(literal));	break;
		case TYPE_INT:		printConversions(parseInt(literal));	break;
		case TYPE_FLOAT:	printConversions(parseFloat(literal));	break;
		case TYPE_DOUBLE:	printConversions(parseDouble(literal));	break;
		default:			printAllImpossible();	break;
	}
}