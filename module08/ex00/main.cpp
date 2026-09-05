#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main()
{
    std::cout << "--- Test 1: basic vector search ---" << std::endl;
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::const_iterator it = easyfind(v, 20);
        if (it != v.end())
            std::cout << "OK: found " << *it << std::endl;
        else
            std::cout << "FAIL: should have found 20" << std::endl;
    }

    std::cout << std::endl << "--- Test 2: value not found ---" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);

        std::vector<int>::const_iterator it = easyfind(v, 999);
        // What is 'it' equal to here? Is it safe to dereference?
        if (it == v.end())
            std::cout << "OK: correctly returned end()" << std::endl;
        else
            std::cout << "FAIL: returned something other than end()" << std::endl;
    }

    std::cout << std::endl << "--- Test 3: different container type (list) ---" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);

        // Does this line compile?
        std::list<int>::const_iterator it = easyfind(lst, 200);
        if (it != lst.end())
            std::cout << "OK: found " << *it << " in list" << std::endl;
    }

    std::cout << std::endl << "--- Test 4: different container type (deque) ---" << std::endl;
    {
        std::deque<int> d;
        d.push_back(5);
        d.push_back(6);

        // Does this line compile?
        std::deque<int>::const_iterator it = easyfind(d, 6);
        if (it != d.end())
            std::cout << "OK: found " << *it << " in deque" << std::endl;
    }

    std::cout << std::endl << "--- Test 5: const container ---" << std::endl;
    {
        std::vector<int> tmp;
        tmp.push_back(42);
        const std::vector<int> cv(tmp.begin(), tmp.end());

        // Does this compile? What does easyfind do with a const argument?
        std::vector<int>::const_iterator it = easyfind(cv, 42);
        if (it != cv.end())
            std::cout << "OK: found " << *it << " in const vector" << std::endl;
    }

    std::cout << std::endl << "--- Test 6: empty container ---" << std::endl;
    {
        std::vector<int> empty;

        std::vector<int>::const_iterator it = easyfind(empty, 1);
        if (it == empty.end())
            std::cout << "OK: empty container handled" << std::endl;
    }

    std::cout << std::endl << "--- Test 7: first occurrence only ---" << std::endl;
    {
        std::vector<int> v;
        v.push_back(7);
        v.push_back(8);
        v.push_back(7);

        std::vector<int>::const_iterator it = easyfind(v, 7);
        if (it != v.end() && it == v.begin())
            std::cout << "OK: returned first occurrence" << std::endl;
        else
            std::cout << "FAIL: did not return first occurrence" << std::endl;
    }

    std::cout << std::endl << "--- Test 8: modify through found iterator ---" << std::endl;
	{
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		// This line will fail to compile if easyfind only returns const_iterator
		std::vector<int>::iterator it = easyfind(v, 20);
		*it = 99;

		if (v[1] == 99)
			std::cout << "OK: modified value through iterator" << std::endl;
		else
			std::cout << "FAIL: value not modified" << std::endl;
	}

    return 0;
}