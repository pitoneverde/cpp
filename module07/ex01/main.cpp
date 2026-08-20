#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &value)
{
    std::cout << value << " ";
}

template <typename T>
void increment(T &value)
{
    ++value;
}

void printString(std::string const &str)
{
    std::cout << str << " ";
}

int main()
{
    // int array + const-reference function
    std::cout << "=== int / print ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    // int array + non-const-reference function
    std::cout << "\n=== int / increment ===" << std::endl;
    iter(numbers, 5, increment<int>);
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    // const int array
    std::cout << "\n=== const int ===" << std::endl;
    const int constNumbers[] = {10, 20, 30, 40, 50};
    iter(constNumbers, 5, print<int>);
    std::cout << std::endl;

    // std::string
    std::cout << "\n=== string ===" << std::endl;
    std::string words[] = {
        "hello",
        "world",
        "from",
        "iter"
    };
    iter(words, 4, print<std::string>);
    std::cout << std::endl;

    // Empty array
    std::cout << "\n=== empty ===" << std::endl;
    iter(numbers, 0, print<int>);
    std::cout << "done" << std::endl;

    return 0;
}