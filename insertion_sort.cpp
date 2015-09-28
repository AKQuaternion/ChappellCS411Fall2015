// insertion_sort.cpp  UNFINISHED
// Glenn G. Chappell
// 28 Sep 2015
//
// For CS 411/611 Fall 2015
// Insertion Sort using Iterators

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;


// insertionSortRec
// Sort a sequence using Insertion Sort.
// Recursive version.
// Requirements on Types:
//     ???
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename RAIter>
void insertionSortRec(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// Main program
// Demonstrates use of function insertionSortRec.
int main()
{
    // Set up data to sort
    vector<int> v { 5, 3, 2, 8, 5, 9, 10, 4, 6, 1, -4 };

    // Print unaltered data
    cout << "Before:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Do a sort
    insertionSortRec(v.begin(), v.end());  // Recursive version

    // Print results
    cout << "After:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

