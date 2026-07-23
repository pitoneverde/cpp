#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid form construction ===" << std::endl;
    try {
        Form taxForm("Tax Return", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Form grade too high ===" << std::endl;
    try {
        Form badForm("Bad", 0, 50);  // gradeToSign = 0 is invalid
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Caught Form::GradeTooHighException: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Form grade too low ===" << std::endl;
    try {
        Form badForm("Bad", 50, 151);  // gradeToExecute = 151 is invalid
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Successful signing ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 10);
        Form contract("Contract", 50, 25);  // Should be signed
        
        std::cout << "Before: " << contract << std::endl;
        alice.signForm(contract);
        std::cout << "After: " << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Failed signing (grade too low) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form secret("Secret Document", 50, 25);
        
        std::cout << "Before: " << secret << std::endl;
        bob.signForm(secret);  // Should fail gracefully with message
        std::cout << "After: " << secret << std::endl;  // Should still be unsigned
    }
    catch (std::exception& e) {
        // Should be unreachable
        std::cout << "Unexpected catch: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Direct beSigned() call ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 75);
        Form permit("Permit", 50, 25);
        
        permit.beSigned(charlie);  // Should throw — charlie's grade (75) > 50
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Direct call failed: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Copy constructor ===" << std::endl;
    try {
        Form original("Original", 30, 20);
        original.beSigned(Bureaucrat("Temp", 10));  // Sign it first
        
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;  // Copy should also be signed
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Copy assignment (only _signed copies) ===" << std::endl;
    try {
        Form a("A", 10, 5);
        Form b("B", 100, 90);
        
        a.beSigned(Bureaucrat("Signer", 5));
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;
        
        b = a;  // Only _signed copies! Name and grades stay as "B"'s
        
        std::cout << "After b = a:" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Edge case — exact grade match ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 50);  // Exactly grade 50
        Form form("Exact", 50, 25);   // Requires exactly grade 50
        
        dave.signForm(form);  // Should succeed (50 <= 50)
        std::cout << form << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return 0;
}