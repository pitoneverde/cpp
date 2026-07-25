#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration, avoid circular include
class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	const std::string _target;

	AForm();

public:
	AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
	AForm(const AForm& other) throw();
	AForm& operator=(const AForm& other) throw();
	virtual ~AForm();

	const std::string& getName() const throw();
	bool getSigned() const throw();
	int getGradeToSign() const throw();
	int getGradeToExecute() const throw();
	const std::string& getTarget() const throw();

	void beSigned(const Bureaucrat& bureaucrat);

	// TEMPLATE METHOD PATTERN	
	void execute(Bureaucrat const& executor) const;
	virtual void executeAction() const = 0;

	// EXCEPTIONS
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif