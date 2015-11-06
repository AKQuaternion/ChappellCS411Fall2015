// knapsack.cpp  UNFINISHED
// Glenn G. Chappell
// 6 Nov 2015
//
// For CS 411/611 Fall 2015
// Knapsack Problem

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <cstdlib>
using std::size_t;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;
#include <cassert>
// for assert


// getYN
// Prompt user with given string, repeatedly input until user types a
// string beginning with 'y', 'Y', 'n', or 'N'. Return yes/no to caller
// as bool (true means yes). Exit on EOF.
bool getYN(const string & prompt)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        if (line.size() > 0 && (line[0] == 'y' || line[0] == 'Y'))
            return true;
        if (line.size() > 0 && (line[0] == 'n' || line[0] == 'N'))
            return false;

        cout << endl;
        cout << "Please type \"y\" or \"n\"" << endl;
    }
}


// knapsack_bf_recurse
// Given lists of object weights & values, knapsack capacity, and n,
// returns greatest possible value in knapsack problem using only
// objects from first n.
// Brute-force method.
// Recursive helper for function knapsack_bf.
int knapsack_bf_recurse(const vector<int> & weights,
                        const vector<int> & values,
                        int capacity,
                        size_t n)
{
    // WRITE THIS!!!
    return 42;  // Dummy return
}


// knapsack_bf
// Given lists of object weights & values, and knapsack capacity,
// returns greatest possible value in knapsack problem.
// Brute-force method.
// Calls recursive helper function knapsack_bf_recurse.
int knapsack_bf(const vector<int> & weights,
                const vector<int> & values,
                int capacity)
{
    assert(weights.size() == values.size());
    size_t n = weights.size();

    return knapsack_bf_recurse(weights, values,
                               capacity, n);
}


// knapsack_mem
// Given lists of object weights & values, and knapsack capacity,
// returns greatest possible value in knapsack problem.
// Memory-function version.
// Calls recursive helper function knapsack_mem_recurse.
int knapsack_mem(const vector<int> & weights,
                 const vector<int> & values,
                 int capacity)
{
    // WRITE THIS!!!
    return 42;  // Dummy return
}


// try_knapsack
// Calls functions on given number of objects; prints results.
void try_knapsack(size_t n,
                  bool dobf)  // True if we do brute-force method
{
    // Sizes & values to push
    vector<int> weightpattern { 1, 10, 1, 10, 10, 1, 10, 1 };
    vector<int> valuepattern { 1, 10, 4, 6, 4, 6, 1, 10 };
    assert(weightpattern.size() == valuepattern.size());

    // Make dataset
    vector<int> weights;
    vector<int> values;
    for (size_t i = 0; i < n; ++i)
    {
        weights.push_back(weightpattern[i%weightpattern.size()]);
        values.push_back(valuepattern[i%weightpattern.size()]);
    }
    int cap = int(4*n);

    // Call knapsack function(s)
    cout << "Number of objects: " << n << endl;
    cout << "Result (memory-function version): " << endl;
    cout << "    " << knapsack_mem(weights, values, cap) << endl;
    if (dobf)
    {
        cout << "Result (brute-force version): " << endl;
        cout << "    " << knapsack_bf(weights, values, cap) << endl;
    }
    cout << endl;
}


// Main program
// Try functions for increasing input sizes.
int main()
{
    // Ask user whether to do brute-force computation
    cout << "Knapsack Problem, Memory-Function Method" << endl;
    cout << endl;
    string prompt =
        "Also use brute-force method (for comparison)? [y/n] ";
    bool do_brute_force = getYN(prompt);
    cout << endl;

    // Loop through problem sizes
    for (size_t i = 0; i < 1000000; ++i)
        try_knapsack(i, do_brute_force);

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

