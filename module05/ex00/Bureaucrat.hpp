#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

	Bureaucrat();

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other) throw();
	Bureaucrat& operator=(const Bureaucrat& other) throw();
	~Bureaucrat() throw();

	const std::string& getName() const throw();
	int getGrade() const throw();

	// EXCEPTIONS
	// Inherit from std::exception so they can be caught as std::exception&
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void incrementGrade() throw(GradeTooHighException);
	void decrementGrade() throw(GradeTooLowException);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif