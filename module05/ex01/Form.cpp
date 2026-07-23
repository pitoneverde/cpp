#include "Form.hpp"
#include "Bureaucrat.hpp"  // Full definition needed to call getGrade()

static const int HIGHEST_GRADE = 1;
static const int LOWEST_GRADE = 150;


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form& other) throw()
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) throw() 
{
    if (this != &other) {
        _signed = other._signed;
        // _name, _gradeToSign, _gradeToExecute are const, no assignment
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const throw() { return _name; }
bool Form::getSigned() const throw() { return _signed; }
int Form::getGradeToSign() const throw() { return _gradeToSign; }
int Form::getGradeToExecute() const throw() { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! Maximum grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! Minimum grade is 150.";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName()
       << ", signed: " << (f.getSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}