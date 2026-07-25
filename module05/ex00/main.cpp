#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Valid construction ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high in constructor ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 0);  // Should throw GradeTooHighException
		std::cout << "This should NOT print!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Caught std::exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low in constructor ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);  // Should throw GradeTooLowException
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Caught specific: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment/decrement ===" << std::endl;
	try {
		Bureaucrat dave("Dave", 3);
		std::cout << "Initial: " << dave << std::endl;
		
		dave.incrementGrade();  // 3 -> 2
		std::cout << "After increment: " << dave << std::endl;
		
		dave.incrementGrade();  // 2 -> 1
		std::cout << "After increment: " << dave << std::endl;
		
		dave.incrementGrade();  // 1 -> should throw!
		std::cout << "This should NOT print!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement too low ===" << std::endl;
	try {
		Bureaucrat eve("Eve", 149);
		std::cout << "Initial: " << eve << std::endl;
		
		eve.decrementGrade();  // 149 -> 150
		std::cout << "After decrement: " << eve << std::endl;
		
		eve.decrementGrade();  // 150 -> should throw!
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Copy assignment ===" << std::endl;
	try {
		Bureaucrat a("A", 10);
		Bureaucrat b("B", 100);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;
		
		b = a;
		
		std::cout << "After b = a:" << std::endl;
		std::cout << "A: " << a << std::endl;
		std::cout << "B: " << b << std::endl;  // Name is still "B", grade is 10
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Self-assignment ===" << std::endl;
	try {
		Bureaucrat self("Self", 42);
		self = self;  // Should be safe due to self-assignment check
		std::cout << "Self: " << self << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}