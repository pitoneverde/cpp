#include "Span.hpp"

Span::Span() {
	_size = 0;
	_count = 0;
}
Span::Span(unsigned int N) : _size(N) {}
Span::Span(const Span& src) {
	*this = src;
}
Span& Span::operator=(const Span& src) {
	_storage = src._storage;
	_size = src._size;
	_count = src._count;
}
Span::~Span() {}

void Span::addNumber(int value) {
	if (_count == _size) throw std::exception();
	++_count;
	_storage.insert(value);
}
int Span::longestSpan() {
	if (_count == 0 || _count == 1) throw std::exception();
	return std::abs(*_storage.begin() - *(--_storage.end()));
}
int Span::shortestSpan() {
	if (_count == 0 || _count == 1) throw std::exception();
}
// addRange