#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	// HARDCODED TESTS FOR EVAL
    
    // // SUBJECT EXAMPLES
    // ScalarConverter::convert("0");
    // std::cout << std::endl;
    // ScalarConverter::convert("nan");
    // std::cout << std::endl;
    // ScalarConverter::convert("42.0f");
    // std::cout << std::endl;

    // // CHAR LITERALS
    // ScalarConverter::convert("'c'");      // normal printable
    // std::cout << std::endl;
    // ScalarConverter::convert("'0'");      // digit character (ASCII 48)
    // std::cout << std::endl;
    // ScalarConverter::convert("' '");      // space (ASCII 32, displayable)
    // std::cout << std::endl;

    // // INT LITERALS
    // ScalarConverter::convert("42");       // basic positive
    // std::cout << std::endl;
    // ScalarConverter::convert("-42");      // negative
    // std::cout << std::endl;
    // ScalarConverter::convert("0");        // zero → char non-displayable
    // std::cout << std::endl;
    // ScalarConverter::convert("127");      // char boundary (DEL, non-displayable)
    // std::cout << std::endl;
    // ScalarConverter::convert("31");       // char non-displayable boundary
    // std::cout << std::endl;
    // ScalarConverter::convert("32");       // char displayable boundary (space)
    // std::cout << std::endl;
    // ScalarConverter::convert("126");      // char '~' last displayable ASCII
    // std::cout << std::endl;

    // // FLOAT LITERALS
    // ScalarConverter::convert("0.0f");     // zero float
    // std::cout << std::endl;
    // ScalarConverter::convert("4.2f");     // basic decimal
    // std::cout << std::endl;
    // ScalarConverter::convert("-4.2f");    // negative decimal
    // std::cout << std::endl;
    // ScalarConverter::convert("42.0f");    // whole number float → char '*'
    // std::cout << std::endl;
    // ScalarConverter::convert("42.5f");    // fractional → char impossible
    // std::cout << std::endl;
    // ScalarConverter::convert("-inff");    // negative infinity
    // std::cout << std::endl;
    // ScalarConverter::convert("+inff");    // positive infinity
    // std::cout << std::endl;
    // ScalarConverter::convert("nanf");     // not-a-number
    // std::cout << std::endl;

    // // DOUBLE LITERALS
    // ScalarConverter::convert("0.0");      // zero double
    // std::cout << std::endl;
    // ScalarConverter::convert("4.2");      // basic decimal
    // std::cout << std::endl;
    // ScalarConverter::convert("-4.2");     // negative decimal
    // std::cout << std::endl;
    // ScalarConverter::convert("42.0");     // whole number double
    // std::cout << std::endl;
    // ScalarConverter::convert("-inf");     // negative infinity
    // std::cout << std::endl;
    // ScalarConverter::convert("+inf");     // positive infinity
    // std::cout << std::endl;
    // ScalarConverter::convert("nan");      // not-a-number
    // std::cout << std::endl;

    // // OVERFLOW / RANGE
    // ScalarConverter::convert("9999999999999");  // int overflow, valid double
    // std::cout << std::endl;
    // ScalarConverter::convert("-9999999999999"); // negative overflow
    // std::cout << std::endl;
    // ScalarConverter::convert("2147483647");     // INT_MAX
    // std::cout << std::endl;
    // ScalarConverter::convert("-2147483648");    // INT_MIN
    // std::cout << std::endl;

    // // INVALID INPUTS
    // ScalarConverter::convert("abc");        // pure garbage
    // std::cout << std::endl;
    // ScalarConverter::convert("42abc");      // trailing garbage
    // std::cout << std::endl;
    // ScalarConverter::convert("");           // empty (if you bypass main guard)
    // std::cout << std::endl;
    // ScalarConverter::convert("f");          // lone f suffix
    // std::cout << std::endl;
    // ScalarConverter::convert(".");          // lone dot
    // std::cout << std::endl;
	
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return 1;
	}
	// std::string has implicit constructor from const char*
	ScalarConverter::convert(argv[1]);
	return 0;
}
