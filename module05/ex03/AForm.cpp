#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const int HIGHEST_GRADE = 1;
static const int LOWEST_GRADE = 150;


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) throw()
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute),
	  _target(other._target) {}

AForm& AForm::operator=(const AForm& other) throw() 
{
	if (this != &other) {
		_signed = other._signed;
		// _name, _gradeToSign, _gradeToExecute, target are const, no assignment
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const throw() { return _name; }
bool AForm::getSigned() const throw() { return _signed; }
int AForm::getGradeToSign() const throw() { return _gradeToSign; }
int AForm::getGradeToExecute() const throw() { return _gradeToExecute; }
const std::string& AForm::getTarget() const throw() { return _target; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
}

// Just perform checks, then delegate to derived class
void AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high! Maximum grade is 1.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low! Minimum grade is 150.";
}

const char * AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}


std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form: " << f.getName()
	   << ", signed: " << (f.getSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute();
	return os;
}