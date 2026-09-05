#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    std::cout << "--- Test 1: subject example ---" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 2)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan()  << " (expect 14)" << std::endl;
    }

    std::cout << "\n--- Test 2: add to full Span ---" << std::endl;
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        try {
            sp.addNumber(3);
            std::cout << "FAIL: did not throw when full" << std::endl;
        } catch (std::exception& e) {
            std::cout << "OK: threw exception when full" << std::endl;
        }
    }

    std::cout << "\n--- Test 3: not enough numbers ---" << std::endl;
    {
        Span sp0(10);
        try {
            sp0.shortestSpan();
            std::cout << "FAIL: did not throw with 0 numbers" << std::endl;
        } catch (std::exception& e) {
            std::cout << "OK: threw with 0 numbers" << std::endl;
        }

        Span sp1(10);
        sp1.addNumber(42);
        try {
            sp1.longestSpan();
            std::cout << "FAIL: did not throw with 1 number" << std::endl;
        } catch (std::exception& e) {
            std::cout << "OK: threw with 1 number" << std::endl;
        }
    }

    std::cout << "\n--- Test 4: large N performance ---" << std::endl;
    {
        Span sp(10000);
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(i);
        }
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 1)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan()  << " (expect 9999)" << std::endl;
    }

    std::cout << "\n--- Test 5: duplicates (zero span) ---" << std::endl;
    {
        Span sp(3);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 0)" << std::endl;
    }

    std::cout << "\n--- Test 6: negative numbers ---" << std::endl;
    {
        Span sp(3);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(10);
        std::cout << "longest: " << sp.longestSpan() << " (expect 20)" << std::endl;
    }

    std::cout << "\n--- Test 7: iterator range add (bonus) ---" << std::endl;
    {
        Span sp(5);
        std::vector<int> v;
        v.push_back(100);
        v.push_back(50);
        v.push_back(25);
        v.push_back(75);
        v.push_back(125);

        // Uncomment and adapt to your bonus method name:
        // sp.addNumber(v.begin(), v.end());
        // std::cout << "range shortest: " << sp.shortestSpan() << " (expect 25)" << std::endl;
        // std::cout << "range longest:  " << sp.longestSpan()  << " (expect 100)" << std::endl;
    }

    std::cout << "\n--- Test 8: random order ---" << std::endl;
    {
        Span sp(5);
        sp.addNumber(42);
        sp.addNumber(-5);
        sp.addNumber(17);
        sp.addNumber(100);
        sp.addNumber(3);
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 8? think about it)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan()  << " (expect 105)" << std::endl;
    }

	std::cout << std::endl << "--- Test 8: random order ---" << std::endl;
	{
		Span sp(3);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		std::cout << "shortest: " << sp.shortestSpan() << " (expect 0)" << std::endl;
	}

    return 0;
}