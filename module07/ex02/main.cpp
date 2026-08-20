#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void printArray(Array<T> const &arr)
{
    std::cout << "[ ";

    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";

    std::cout << "]" << std::endl;
}

int main()
{
    // 1. Empty array
    std::cout << "=== Empty array ===" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    // 2. Array with n elements
    std::cout << "\n=== Array with 5 elements ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "size: " << numbers.size() << std::endl;
    printArray(numbers);

    // 3. Assign values through []
    std::cout << "\n=== Assignment through [] ===" << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i * 10);
    printArray(numbers);

    // 4. Reading values through []
    std::cout << "\n=== Reading values ===" << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    // 5. Copy constructor
    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Original: ";
    printArray(numbers);
    std::cout << "Copy:     ";
    printArray(copy);

    // 6. Deep copy test
    std::cout << "\n=== Deep copy test ===" << std::endl;
    copy[0] = 999;
    std::cout << "Original after modifying copy: ";
    printArray(numbers);
    std::cout << "Copy after modification:       ";
    printArray(copy);

    // 7. Assignment operator

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> assigned(3);
    assigned[0] = 100;
    assigned[1] = 200;
    assigned[2] = 300;
    std::cout << "Before assignment: ";
    printArray(assigned);
    assigned = numbers;
    std::cout << "After assignment:  ";
    printArray(assigned);

    // 8. Deep copy test for assignment
    std::cout << "\n=== Assignment deep copy test ===" << std::endl;
    assigned[0] = -123;
    std::cout << "Original:  ";
    printArray(numbers);
    std::cout << "Assigned:  ";
    printArray(assigned);

    // 9. Const array
    std::cout << "\n=== Const array ===" << std::endl;
    Array<int> constArray(numbers);
    const Array<int> &constRef = constArray;
    std::cout << "size: " << constRef.size() << std::endl;
    std::cout << "constRef[0]: " << constRef[0] << std::endl;

    // 10. Out-of-bounds access
    std::cout << "\n=== Out-of-bounds access ===" << std::endl;
    try
    {
        std::cout << numbers[100] << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 11. Negative index
    std::cout << "\n=== Negative index ===" << std::endl;
    try
    {
        numbers[-1] = 42;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 12. Strings
    std::cout << "\n=== String array ===" << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "!";
    printArray(words);

    // 13. Zero-sized array
    std::cout << "\n=== Zero-sized array ===" << std::endl;
    Array<int> zero(0);
    std::cout << "size: " << zero.size() << std::endl;
    try
    {
        zero[0] = 42;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 14. Self-assignment
    std::cout << "\n=== Self-assignment ===" << std::endl;
    Array<int> self(numbers);
    self = self;
    std::cout << "After self-assignment: ";
    printArray(self);

    // 15. Different types
    std::cout << "\n=== Double array ===" << std::endl;
    Array<double> decimals(3);
    decimals[0] = 1.1;
    decimals[1] = 2.2;
    decimals[2] = 3.3;
    printArray(decimals);
    std::cout << "\n=== Done ===" << std::endl;

    // 16. Larger array
    std::cout << "\n=== Larger array ===" << std::endl;
    Array<int> large(10000);
    std::cout << "size = " << large.size() << std::endl;
    large[0] = 123;
    large[9999] = 456;
    std::cout << "large[0] = " << large[0] << std::endl;
    std::cout << "large[9999] = " << large[9999] << std::endl;
    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}