#include "Bureaucrat.hpp"
#include "Form.hpp"

// CLASS

static const int HIGHEST_GRADE = 1;
static const int LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    : _name(name), _grade(grade)
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();  // throw by value, catch by reference
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) throw()
    : _name(other._name), _grade(other._grade) {}

// Cannot assign to _name because it's const
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) throw()
{
	// Check for self-assignment
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() throw() {}

const std::string& Bureaucrat::getName() const throw() { return _name; }
int Bureaucrat::getGrade() const throw() { return _grade; }

// 3 -> 2 -> 1 (lower number = higher rank)
void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (_grade <= HIGHEST_GRADE)
        throw GradeTooHighException();
    _grade--;
}

// 1 -> 2 -> 3 (higher number = lower rank)
void Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    if (_grade >= LOWEST_GRADE)
        throw GradeTooLowException();
    _grade++;
}

// 'const' because signing a form doesn't change the bureaucrat
void Bureaucrat::signForm(Form& form) const
{
    try {
        form.beSigned(*this);  // Attempt to sign
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
    // beSigned() only throws GradeTooLowException
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! Minimum grade is 150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;  // Return the stream for chaining
}