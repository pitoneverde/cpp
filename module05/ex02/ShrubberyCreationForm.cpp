#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("Shrubbery Creation", SIGN_GRADE, EXEC_GRADE, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);	// Call base, nothing to add
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream outFile(filename.c_str());  // .c_str() for C++98 compatibility
	
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}
	
	outFile << "    *    " << std::endl;
	outFile << "   ***   " << std::endl;
	outFile << "  *****  " << std::endl;
	outFile << " ******* " << std::endl;
	outFile << "*********" << std::endl;
	outFile << "   |||   " << std::endl;
	outFile << std::endl;
	outFile << "    *    " << std::endl;
	outFile << "   ***   " << std::endl;
	outFile << "  *****  " << std::endl;
	outFile << " ******* " << std::endl;
	outFile << "*********" << std::endl;
	outFile << "   |||   " << std::endl;
	
	outFile.close();
}
