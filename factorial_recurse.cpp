// factorial_recurse.cpp
// Glenn G. Chappell
// 16 Sep 2015
//
// For CS 411/611 Fall 2015
// Recursive Computation of a Factorial

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
using std::exit;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <cstdint>
using std::uint64_t;


// factorial
// Pre:
//     n! can be represented as a 64-bit unsigned integer (so n <= 20).
// Post:
//     Return is n!.
// Recursive.
uint64_t factorial(uint64_t n)
{
    // BASE CASE
    if (n == static_cast<uint64_t>(0))
        return static_cast<uint64_t>(1);

    // RECURSIVE CASE
    return n * factorial(n-static_cast<uint64_t>(1));
}


// getNum
// Prints prompt to cout and then inputs a number of type int on a line
// from cin. Repeats until valid number obtained; returns it to caller
// in reference argument. Return value is false if number could not be
// obtained.
bool getNum(const string & prompt,
            int & num)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())
                return false;
            continue;
        }

        istringstream istr(line);
        istr >> num;
        if (!istr)
            continue;
        return true;
    }
}


// main
// Repeatedly inputs a number n and prints n! (factorial).
// Terminates on n < 0.
// Uses getNum.
int main()
{
    // Print header
    cout << "Factorials" << endl;
    cout << endl;

    while (true)
    {
        // Prompt & input n
        int n;
        while (true)
        {
            bool good = getNum("n (negative to quit)? ", n);
            if (!good)
                exit(1);
    
            if (n < 0)
                exit(0);

            if (n > 20)
            {
                cout << "TOO LARGE!" << endl;
                cout << endl;
                continue;
            }

            break;
        }

        // Print solutions to n-Queens Problem
        cout << endl;
        uint64_t nn = static_cast<uint64_t>(n);
        uint64_t fact = factorial(nn);
        cout << n << "! = " << fact << endl;
        cout << endl;
    }
}


