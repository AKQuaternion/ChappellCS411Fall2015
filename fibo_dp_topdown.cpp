// fibo_dp_topdown.cpp  UNFINISHED
// Glenn G. Chappell
// 6 Nov 2015
//
// For CS 411/611 Fall 2015
// Computing Fibonacci Numbers
// Dynamic Programming (Top-Down)

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdint>
using std::uint_fast64_t;
#include <vector>
using std::vector;
#include <cassert>
// For assert


// Type unum
// Type of values used for large-ish integer computation.
// Should be an unsigned integer type.
using unum = uint_fast64_t;  // >= 64 bits, fast, unsigned


// fibo_recurse
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, above preconditions hold if 0 <= n <= 93.
// Post:
//     Return is F(n).
// Recursive helper function for fibo.
unum fibo_recurse(int n)
{
    unum result;  // For our final result

    if (n <= 1)  // BASE CASE
    {
        result = static_cast<unum>(n);
    }
    else         // RECURSIVE CASE
    {
        result = fibo_recurse(n-2) + fibo_recurse(n-1);
    }

    return result;
}


// fibo
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, preconditions hold if 0 <= n <= 93.
// Post:
//     Return is F(n).
// Uses recursive helper function fibo_recurse.
unum fibo(int n)
{
    return fibo_recurse(n);
}


// main
// Prints i, F(i) for i = 0, 1, 2, ... through the greatest legal
// value for our function.
// Uses fibo.
int main()
{
    cout << "Fibonacci Numbers" << endl;
    cout << endl;
    for (int i = 0; i <= 93; ++i)
    {
        cout << i << ": " << fibo(i) << endl;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

