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

float ScalarConverter::parseFloat(const std::string& literal) {
	if (literal == "-inff")
		return -std::numeric_limits<float>::infinity();
	if (literal == "+inff")
		return std::numeric_limits<float>::infinity();
	if (literal == "nanf")
		return std::numeric_limits<float>::quiet_NaN();
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
}

double ScalarConverter::parseDouble(const std::string& literal) {
	if (literal == "-inf")
		return -std::numeric_limits<double>::infinity();
	if (literal == "+inf")
		return std::numeric_limits<double>::infinity();
	if (literal == "nan")
		return std::numeric_limits<double>::quiet_NaN();
	char* end;
	const char* str = literal.c_str();
	double d = std::strtod(str, &end);
	
	if (end == str)
		throw std::invalid_argument("no conversion");
	if (*end != '\0')
		throw std::invalid_argument("trailing chars");
	
	return d;
}

double ScalarConverter::salvageToDouble(const std::string& literal, ScalarConverter::e_type type) {
	if (type == TYPE_FLOAT) {
		char* end;
		std::string num = literal.substr(0, literal.length() - 1);
		const char* str = num.c_str();
		double d = std::strtod(str, &end);
		if (end == str || *end != '\0')
			throw std::invalid_argument("bad float salvage");
		return d;
	}
	return parseDouble(literal);
}

// ENTRYPOINT

void ScalarConverter::convert(const std::string& literal) {
	ScalarConverter::e_type type = detectType(literal);
	try {
		switch (type) {
			case TYPE_CHAR: 	printConversions(parseChar(literal));	break;
			case TYPE_INT:		printConversions(parseInt(literal));	break;
			case TYPE_FLOAT:	printConversions(parseFloat(literal));	break;
			case TYPE_DOUBLE:	printConversions(parseDouble(literal));	break;
			default:			printAllImpossible();	break;
		}
	} catch (const std::invalid_argument&) {
		printAllImpossible();
	} catch (const std::out_of_range&) {
		// retry with double, which is the broadest type
		try {
			printConversions(salvageToDouble(literal, type));
		} catch (const std::invalid_argument&) {
			printAllImpossible();
		}
	}
}