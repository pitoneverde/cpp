#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>

class AForm;

class Intern {
private:
	typedef AForm* (*FormInit)(const std::string& target);

	struct FormEntry {
		const char* name;
		FormInit init;
	};

	// Both initialized at compile-time
	static const FormEntry _lookupTable[];
	static const int _formCount;

	static AForm* _initShrubbery(const std::string& target);
	static AForm* _initRobotomy(const std::string& target);
	static AForm* _initPardon(const std::string& target);

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	class InvalidFormException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif