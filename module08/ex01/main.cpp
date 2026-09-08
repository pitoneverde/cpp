#include <iostream>
#include <sstream>
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

	std::cout << std::endl << "--- Test 9: random order ---" << std::endl;
	{
		Span sp(3);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		std::cout << "shortest: " << sp.shortestSpan() << " (expect 0)" << std::endl;
	}

    std::cout << std::endl << "--- Test 10: exactly two elements ---" << std::endl;
    {
        Span sp1(2);
        sp1.addNumber(100);
        sp1.addNumber(101);
        std::cout << "A: " << sp1.shortestSpan() << " (expect 1)" << std::endl;
    }

    std::cout << std::endl << "--- Test 11: all duplicates (zero span) ---" << std::endl;
    {
        Span sp2(3);
        sp2.addNumber(7);
        sp2.addNumber(7);
        sp2.addNumber(7);
        std::cout << "B: " << sp2.shortestSpan() << " (expect 0)" << std::endl;
    }

    std::cout << std::endl << "--- Test 10: extreme adjacent values ---" << std::endl;
    {
        Span sp3(2);
        sp3.addNumber(-1);
        sp3.addNumber(2147483647);  // INT_MAX
        std::cout << "C: " << sp3.shortestSpan() << " (expect overflow)" << std::endl;
    }

    std::cout << std::endl << "--- Test 10: INT_MIN involved ---" << std::endl;
    {
        Span sp4(2);
        sp4.addNumber(-2147483648); // INT_MIN
        sp4.addNumber(0);
        std::cout << "D: " << sp4.shortestSpan() << " (expect overflow)" << std::endl;
    }

    // tests for addRange
    std::cout << "--- Test 1: basic range from vector ---" << std::endl;
    {
        Span sp(5);
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        sp.addRange(v.begin(), v.end());
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 10)" << std::endl;
        std::cout << "longest:  " << sp.longestSpan()  << " (expect 40)" << std::endl;
    }

    std::cout << "\n--- Test 2: range exceeds capacity ---" << std::endl;
    {
        Span sp(3);
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);  // 4 elements into capacity 3

        try {
            sp.addRange(v.begin(), v.end());
            std::cout << "FAIL: did not throw" << std::endl;
        } catch (std::exception& e) {
            // After the throw, the Span should still be empty (atomicity)
            try {
                sp.shortestSpan();
                std::cout << "FAIL: Span was modified before throw" << std::endl;
            } catch (std::exception&) {
                std::cout << "OK: threw and Span is still empty" << std::endl;
            }
        }
    }

    std::cout << "\n--- Test 3: range from list (different iterator type) ---" << std::endl;
    {
        Span sp(3);
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(50);
        lst.push_back(25);

        sp.addRange(lst.begin(), lst.end());
        std::cout << "longest: " << sp.longestSpan() << " (expect 75)" << std::endl;
    }

    std::cout << "\n--- Test 4: partial fill then range ---" << std::endl;
    {
        Span sp(5);
        sp.addNumber(1);
        sp.addNumber(2);

        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        sp.addRange(v.begin(), v.end());
        std::cout << "count OK? try shortestSpan..." << std::endl;
        std::cout << "shortest: " << sp.shortestSpan() << " (expect 1)" << std::endl;
    }

    std::cout << "\n--- Test 5: empty range ---" << std::endl;
    {
        Span sp(3);
        std::vector<int> v;  // empty
        sp.addRange(v.begin(), v.end());
        try {
            sp.shortestSpan();
            std::cout << "FAIL: should throw with 0 elements" << std::endl;
        } catch (std::exception&) {
            std::cout << "OK: empty range insert did nothing" << std::endl;
        }
    }

    std::cout << "\n--- Test 6: InputIterator trap (optional) ---" << std::endl;
    {
        Span sp(3);
        std::stringstream ss("1 2 3");
        std::istream_iterator<int> it(ss);
        std::istream_iterator<int> end;

        // If you used std::distance() before insert, this may silently
        // insert nothing instead of throwing or inserting 3 elements.
        try {
            sp.addRange(it, end);
            std::cout << "elements added: check count manually" << std::endl;
        } catch (std::exception& e) {
            std::cout << "threw: " << e.what() << std::endl;
        }
    }
    return 0;
}