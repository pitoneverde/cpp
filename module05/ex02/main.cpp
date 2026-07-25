#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Shrubbery Creation ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");
		
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		
		std::cout << "After signing: " << shrub << std::endl;
		
		bob.executeForm(shrub);  // Should create home_shrubbery
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Robotomy Request ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robot("Bender");
		
		alice.signForm(robot);
		
		std::cout << "Executing robotomy (run multiple times for randomness):" << std::endl;
		for (int i = 0; i < 5; i++) {
			alice.executeForm(robot);
		}
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Presidential Pardon ===" << std::endl;
	try {
		Bureaucrat zaphod("Zaphod", 5);
		PresidentialPardonForm pardon("Arthur Dent");
		
		zaphod.signForm(pardon);
		zaphod.executeForm(pardon);
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execute unsigned form ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		ShrubberyCreationForm unsignedForm("garden");
		
		charlie.executeForm(unsignedForm);  // Should fail with NotSignedException
	}
	catch (std::exception& e) {
		// This won't fire because executeForm catches internally
		std::cout << "Unexpected catch: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Grade too low to execute ===" << std::endl;
	try {
		Bureaucrat chris("Chris", 1);	// Just to sign
		Bureaucrat dave("Dave", 150);
		ShrubberyCreationForm lowForm("park");
		
		chris.signForm(lowForm);
		dave.executeForm(lowForm);	// Should throw
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Polymorphism test ===" << std::endl;
	try {
		Bureaucrat exec("Exec", 1);
		
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("yard");
		forms[1] = new RobotomyRequestForm("R2D2");
		forms[2] = new PresidentialPardonForm("Ford Prefect");
		
		for (int i = 0; i < 3; i++) {
			exec.signForm(*forms[i]);
			exec.executeForm(*forms[i]);
			delete forms[i];
		}
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Cannot instantiate abstract class ===" << std::endl;
	// AForm form("test", 1, 1, "target");
	std::cout << "AForm is abstract, cannot instantiate directly." << std::endl;

	return 0;
}