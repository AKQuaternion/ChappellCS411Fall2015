// counting_sort_vector.cpp  UNFINISHED
// Glenn G. Chappell
// 28 Oct 2015
//
// For CS 411/611 Fall 2015
// Counting Sorts on a Vector

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;


// comparisonCountingSort
// Sorts a vector, using Comparison Counting Sort
template <typename Val>
void comparisonCountingSort(vector<Val> & data)
{
    // WRITE THIS!!!
}


// distributionCountingSort
// Sorts a vector, using Distribution Counting Sort
template <typename Val>
void distributionCountingSort(vector<Val> & data)
{
    // WRITE THIS!!!
}


// Main program
// Demonstrates use of Counting Sort functions.
int main()
{
    // Set up data to sort
    vector<int> v { 5, 3, 2, 8, 8, 8, 8, 5, 9, 10, 4, 8, 6, 1, -4 };

    // Print unaltered data
    cout << "Before:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Call one of the Counting Sort functions
    comparisonCountingSort(v);
    //distributionCountingSort(v);

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

