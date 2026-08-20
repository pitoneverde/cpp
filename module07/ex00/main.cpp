#include <iostream>
#include <string>
#include "whatever.hpp"

// int main()
// {
//     // swap
//     std::cout << "=== swap ===" << std::endl;
//     int a = 2;
//     int b = 3;
//     std::cout << "Before: a = " << a << ", b = " << b << std::endl;
//     ::swap(a, b);
//     std::cout << "After:  a = " << a << ", b = " << b << std::endl;

//     std::string s1 = "hello";
//     std::string s2 = "world";
//     std::cout << "Before: s1 = " << s1 << ", s2 = " << s2 << std::endl;
//     ::swap(s1, s2);
//     std::cout << "After:  s1 = " << s1 << ", s2 = " << s2 << std::endl;

//     // min
//     std::cout << "\n=== min ===" << std::endl;
//     int x = 10;
//     int y = 20;
//     std::cout << "min(10, 20) = " << ::min(x, y) << std::endl;
//     std::cout << "min(20, 10) = " << ::min(y, x) << std::endl;

//     // Equal values
//     int equal1 = 42;
//     int equal2 = 42;
//     const int &minResult = ::min(equal1, equal2);
//     std::cout << "min(42, 42) = " << minResult << std::endl;
//     std::cout << "Returns second argument: "
//               << (&minResult == &equal2 ? "YES" : "NO")
//               << std::endl;

//     // max
//     std::cout << "\n=== max ===" << std::endl;
//     std::cout << "max(10, 20) = " << ::max(x, y) << std::endl;
//     std::cout << "max(20, 10) = " << ::max(y, x) << std::endl;

//     // Equal values
//     int maxEqual1 = 42;
//     int maxEqual2 = 42;
//     const int &maxResult = ::max(maxEqual1, maxEqual2);
//     std::cout << "max(42, 42) = " << maxResult << std::endl;
//     std::cout << "Returns second argument: "
//               << (&maxResult == &maxEqual2 ? "YES" : "NO")
//               << std::endl;


//     // Other types
//     std::cout << "\n=== other types ===" << std::endl;
//     double d1 = 3.14;
//     double d2 = 2.71;
//     std::cout << "min(3.14, 2.71) = " << ::min(d1, d2) << std::endl;
//     std::cout << "max(3.14, 2.71) = " << ::max(d1, d2) << std::endl;

//     std::string str1 = "apple";
//     std::string str2 = "banana";
//     std::cout << "min(\"apple\", \"banana\") = "
//               << ::min(str1, str2) << std::endl;
//     std::cout << "max(\"apple\", \"banana\") = "
//               << ::max(str1, str2) << std::endl;

//     return 0;
// }

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}