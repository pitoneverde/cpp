/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:36:17 by sabruma           #+#    #+#             */
/*   Updated: 2026/03/29 22:18:56 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

void test_constructors() {
    std::cout << std::endl;
	std::cout << "=== Testing Constructors ===" << std::endl;
    
    // Default constructor
    Fixed a;
    std::cout << "Default: " << a << " (expected: 0)" << std::endl;
    assert(a.toFloat() == 0.0f);
    
    // Int constructor
    Fixed b(42);
    std::cout << "Int(42): " << b << " (expected: 42)" << std::endl;
    assert(b.toInt() == 42);
    
    // Float constructor
    Fixed c(42.42f);
    std::cout << "Float(42.42): " << c << " (expected: ~42.42)" << std::endl;
    assert(std::abs(c.toFloat() - 42.42f) < 0.01f);
    
    // Copy constructor
    Fixed d(c);
    std::cout << "Copy of c: " << d << " (expected: same as c)" << std::endl;
    assert(d.toFloat() == c.toFloat());
}

void test_assignment() {
	std::cout << std::endl;
    std::cout << "=== Testing Assignment ===" << std::endl;
    
    Fixed a(10);
    Fixed b;
    b = a;
    std::cout << "Assigned: " << b << " (expected: 10)" << std::endl;
    assert(b.toInt() == 10);
    
    // Self-assignment
    b = b;
    std::cout << "Self-assign: " << b << " (expected: 10)" << std::endl;
    assert(b.toInt() == 10);
}

void test_comparison() {
    std::cout << std::endl;
    std::cout << "=== Testing Comparison Operators ===" << std::endl;
    
    Fixed a(10);
    Fixed b(20);
    Fixed c(10);
    
    // Greater than
    assert(b > a);
    assert(!(a > b));
    std::cout << "20 > 10: OK" << std::endl;
    
    // Less than
    assert(a < b);
    assert(!(b < a));
    std::cout << "10 < 20: OK" << std::endl;
    
    // Greater equal
    assert(a >= c);
    assert(b >= a);
    assert(!(a >= b));
    std::cout << ">=: OK" << std::endl;
    
    // Less equal
    assert(a <= c);
    assert(a <= b);
    assert(!(b <= a));
    std::cout << "<=: OK" << std::endl;
    
    // Equal
    assert(a == c);
    assert(!(a == b));
    std::cout << "==: OK" << std::endl;
    
    // Not equal
    assert(a != b);
    assert(!(a != c));
    std::cout << "!=: OK" << std::endl;
}

void test_arithmetic() {
    std::cout << std::endl;
    std::cout << "=== Testing Arithmetic Operators ===" << std::endl;
    
    Fixed a(10);
    Fixed b(3);
    Fixed c(5.5f);
    
    // Addition
    Fixed sum = a + b;
    std::cout << "10 + 3 = " << sum << " (expected: 13)" << std::endl;
    assert(sum.toInt() == 13);
    
    // Subtraction
    Fixed diff = a - b;
    std::cout << "10 - 3 = " << diff << " (expected: 7)" << std::endl;
    assert(diff.toInt() == 7);
    
    // Multiplication
    Fixed prod = a * b;
    std::cout << "10 * 3 = " << prod << " (expected: 30)" << std::endl;
    assert(prod.toInt() == 30);
    
    // Float multiplication
    Fixed fprod = Fixed(2) * Fixed(5.5f);
    std::cout << "2 * 5.5 = " << fprod << " (expected: 11)" << std::endl;
    assert(fprod.toInt() == 11);
    
    // Division
    Fixed quot = a / b;
    std::cout << "10 / 3 = " << quot << " (expected: ~3.33)" << std::endl;
    assert(std::abs(quot.toFloat() - 3.333f) < 0.1f);
    
    // Division by zero (crashes with FPE)
    // Fixed zero;
    // Fixed div_zero = a / zero;
    // std::cout << "10 / 0 = " << div_zero << " (check your implementation)" << std::endl;
}

void test_increment_decrement() {
    std::cout << std::endl;
    std::cout << "=== Testing Increment/Decrement ===" << std::endl;
    
    Fixed a;
    
    // Pre-increment
    std::cout << "Initial: " << a << std::endl;
    std::cout << "++a: " << ++a << " (expected: ~0.0039, smallest representable > 0)" << std::endl;
    std::cout << "After ++a: " << a << std::endl;
    
    // Post-increment
    Fixed b = a++;
    std::cout << "b = a++: " << b << " (expected: previous value)" << std::endl;
    std::cout << "After a++: " << a << std::endl;
    
    // Pre-decrement
    std::cout << "--a: " << --a << " (expected: back to previous)" << std::endl;
    
    // Post-decrement
    Fixed c = a--;
    std::cout << "c = a--: " << c << std::endl;
    std::cout << "After a--: " << a << std::endl;
}

void test_conversions() {
	std::cout << std::endl;
    std::cout << "=== Testing Conversions ===" << std::endl;
    
    Fixed a(42.625f);  // 42 + 5/8, should be exact in binary
    
    std::cout << "toInt: " << a.toInt() << " (expected: 42)" << std::endl;
    assert(a.toInt() == 42);
    
    std::cout << "toFloat: " << a.toFloat() << " (expected: ~42.625)" << std::endl;
    assert(std::abs(a.toFloat() - 42.625f) < 0.001f);
    
    std::cout << "getRawBits: " << a.getRawBits() << std::endl;
    
    Fixed b;
    b.setRawBits(256);  // 256 / 256 = 1.0
    std::cout << "After setRawBits(256): " << b << " (expected: 1)" << std::endl;
    assert(b.toInt() == 1);
}

void test_min_max() {
    std::cout << std::endl;
    std::cout << "=== Testing Min/Max ===" << std::endl;
    
    Fixed a(10);
    Fixed b(20);
    const Fixed ca(10);
    const Fixed cb(20);
    
    // Non-const versions
    std::cout << "min(10, 20): " << Fixed::min(a, b) << " (expected: 10)" << std::endl;
    std::cout << "max(10, 20): " << Fixed::max(a, b) << " (expected: 20)" << std::endl;
    
    // Const versions
    std::cout << "min(const)(10, 20): " << Fixed::min(ca, cb) << " (expected: 10)" << std::endl;
    std::cout << "max(const)(10, 20): " << Fixed::max(ca, cb) << " (expected: 20)" << std::endl;
    
    // Edge cases
    Fixed neg(-10);
    std::cout << "min(-10, 10): " << Fixed::min(neg, a) << " (expected: -10)" << std::endl;
    std::cout << "max(-10, 10): " << Fixed::max(neg, a) << " (expected: 10)" << std::endl;
}

void test_negative_values() {
    std::cout << std::endl;
    std::cout << "=== Testing Negative Values ===" << std::endl;
    
    Fixed a(-5);
    Fixed b(3);
    Fixed c(-2.5f);
    
    std::cout << "Negative int: " << a << " (expected: -5)" << std::endl;
    std::cout << "Negative float: " << c << " (expected: ~-2.5)" << std::endl;
    
    Fixed sum = a + b;
    std::cout << "-5 + 3 = " << sum << " (expected: -2)" << std::endl;
    assert(sum.toInt() == -2);
    
    Fixed prod = a * b;
    std::cout << "-5 * 3 = " << prod << " (expected: -15)" << std::endl;
    assert(prod.toInt() == -15);
}

void test_precision_limits() {
	std::cout << std::endl;
    std::cout << "=== Testing Precision Limits ===" << std::endl;
    
    // Test smallest representable value (1/256 ≈ 0.00390625)
    Fixed tiny;
    tiny.setRawBits(1);
    std::cout << "Smallest positive: " << tiny << " (raw: 1)" << std::endl;
    
    // Test values that push precision limits
    Fixed a(0.00390625f);   // Exactly 1/256
    Fixed b(0.0078125f);    // Exactly 2/256
    std::cout << "0.00390625: " << a << std::endl;
    std::cout << "0.0078125: " << b << std::endl;
    
    // Test accumulation of rounding errors
    Fixed sum;
    for (int i = 0; i < 10; i++) {
        sum = sum + Fixed(0.1f);
    }
    std::cout << "Sum of ten 0.1: " << sum << " (expected: ~1, might be slightly off due to precision)" << std::endl;
}

// Original main from subject
void test_subject_main() {
    std::cout << std::endl;
    std::cout << "=== Original Subject Main ===" << std::endl;
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
}

int main(void) {
    test_constructors();
    test_assignment();
    test_comparison();
    test_arithmetic();
    test_increment_decrement();
    test_conversions();
    test_min_max();
    test_negative_values();
    test_precision_limits();
    test_subject_main();
    
    std::cout << "All tests completed!" << std::endl;
    return 0;
}