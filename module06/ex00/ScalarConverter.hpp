#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <cmath>


class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	enum e_type {
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INVALID
	};
	static e_type detectType(const std::string& literal);

	static char parseChar(const std::string& literal); 
	static int parseInt(const std::string& literal);
	static float parseFloat(const std::string& literal);
	static double parseDouble(const std::string& literal);

	static void printConversions(const char c);
	static void printConversions(const int i);
	static void printConversions(const float f);
	static void printConversions(const double d);

	static void printAllImpossible();

public:
	static void convert(const std::string& literal);
};

#endif