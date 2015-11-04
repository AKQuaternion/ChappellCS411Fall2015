// coinrow.cpp  UNFINISHED
// Glenn G. Chappell
// 4 Nov 2015
//
// For CS 411/611 Fall 2015
// Simple Dynamic-Programming Example

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdlib>
using std::size_t;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;
#include <cassert>  // for assert


// coinRow_bf
// Returns maximum sum of subset of given values, on the condition that
// no two consecutive values lie in the subset. Assumes values are all
// nonnegative.
// Brute-force method.
int coinRow_bf(const vector<int> & values)
{
    // WRITE THIS!!!
    return 42;  // Dummy return
}


// coinRow_dp
// Returns maximum sum of subset of given values, on the condition that
// no two consecutive values lie in the subset. Assumes values are all
// nonnegative.
// Uses dynamic programming.
int coinRow_dp(const vector<int> & values)
{
    // WRITE THIS!!!
    return 42;  // Dummy return
}


// try_coinRow
// Calls functions on a list of the given size; prints results.
void try_coinRow(size_t n)
{
    const int DO_BRUTE_FORCE = 1;  // Determines whether BF used
    // Values to push
    int valuepattern[8] = { 1, 10, 1, 10, 10, 1, 10, 1 };

    // Make dataset
    vector<int> values;
    for (size_t i = 0; i != n; ++i)
        values.push_back(valuepattern[i%8]);

    // Call coin-row function(s)
    cout << "Number of values: " << n << endl;
    cout << "Result (dynamic-programming version): " << endl;
    cout << "    " << coinRow_dp(values) << endl;
    if (DO_BRUTE_FORCE)
    {
        cout << "Result (brute-force version): " << endl;
        cout << "    " << coinRow_bf(values) << endl;
    }
    cout << endl;
}


// Main program
// Try functions for increasing input sizes.
int main()
{
    for (size_t i = 0; i < 100000000; ++i)
        try_coinRow(i);

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

