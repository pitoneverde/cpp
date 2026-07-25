#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const Intern::FormEntry Intern::_lookupTable[] = {
	{"shrubbery creation", &Intern::_initShrubbery},
	{"robotomy request", &Intern::_initRobotomy},
	{"presidential pardon", &Intern::_initPardon}
};

const int Intern::_formCount = sizeof(_lookupTable) / sizeof(_lookupTable[0]);

AForm* Intern::_initShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_initRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::_initPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

const char* Intern::InvalidFormException::what() const throw() {
	return "Intern: Unknown form name requested";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	for (size_t i = 0; i < _formCount; i++)
	{
		if(formName == _lookupTable[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return _lookupTable[i].init(target);
		}
	}
	// Form not found in lookup table
	throw InvalidFormException();
}