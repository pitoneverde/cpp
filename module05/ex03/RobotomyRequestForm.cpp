#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("Robotomy Request", SIGN_GRADE, EXEC_GRADE, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES * BZZZZZZ... WHIRRRRRR..." << std::endl;

	// Horrible, but only was in C++98
	// <random> is introduced only later in C++11
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy of " << getTarget() << " failed." << std::endl;
	}
}