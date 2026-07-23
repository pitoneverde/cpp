#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration, avoid circular include
class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

    Form();

public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other) throw();
    Form& operator=(const Form& other) throw();
    ~Form();

    const std::string& getName() const throw();
    bool getSigned() const throw();
    int getGradeToSign() const throw();
    int getGradeToExecute() const throw();

    void beSigned(const Bureaucrat& bureaucrat);

    // EXCEPTIONS
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif