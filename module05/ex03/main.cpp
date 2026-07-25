#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Create shrubbery form ===" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "home");
        
        Bureaucrat bob("Bob", 137);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Create robotomy form ===" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Bender");
        
        Bureaucrat alice("Alice", 45);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Create presidential pardon ===" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Arthur Dent");
        
        Bureaucrat zaphod("Zaphod", 5);
        zaphod.signForm(*form);
        zaphod.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Unknown form — exception thrown! ===" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("coffee request", "Kitchen");
        
        std::cout << "This should NOT print!" << std::endl;
        delete form;
    }
    catch (Intern::InvalidFormException& e) {
        std::cout << "Caught specific: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Caught generic: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Multiple forms from one intern ===" << std::endl;
    try {
        Intern intern;
        
        AForm* shrub = intern.makeForm("shrubbery creation", "yard");
        AForm* robo = intern.makeForm("robotomy request", "C3PO");
        AForm* pardon = intern.makeForm("presidential pardon", "Marvin");
        
        Bureaucrat exec("Exec", 1);
        
        exec.signForm(*shrub);
        exec.signForm(*robo);
        exec.signForm(*pardon);
        
        exec.executeForm(*shrub);
        exec.executeForm(*robo);
        exec.executeForm(*pardon);
        
        delete shrub;
        delete robo;
        delete pardon;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Case sensitivity ===" << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("Shrubbery Creation", "home");
        delete form;
    }
    catch (Intern::InvalidFormException& e) {
        std::cout << "Case-sensitive match failed: " << e.what() << std::endl;
    }

    return 0;
}