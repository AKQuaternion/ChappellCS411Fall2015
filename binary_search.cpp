// binary_search.cpp  UNFINISHED
// Glenn G. Chappell
// 4 Oct 2015
//
// For CS 411/611 Fall 2015
// Binary Search using Iterators

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;


// binarySearch
// Does Binary Search on a range specified with iterators.
// Recursive.
// Requirements on types:
//     RAIter is a random-access iterator type.
//     ValueType is the value type of RAIter.
//     ValueType has a public operator<.
//     operator< is a total order on ValueType.
// Pre:
//     [first, last) is a valid range.
//     Values in the range are sorted by < (ascending).
// Post:
//     Return is true if findme was found (using equivalence) in range,
//      false otherwise.
template <typename RAIter, typename ValueType>
bool binarySearch(RAIter first, RAIter last,  // Range to search
                  const ValueType & findme)   // Value to find
{
    // BASE CASE

    if (first == last)
        return false;
    if (last == first+1)
        return *first == findme;

    // RECURSIVE CASE

    // Get iterator to middle position of range
    RAIter middle = first + (last-first)/2;

    if (findme < *middle)
    {   // Search first half of range
        return binarySearch(first, middle, findme);
    }
    else
    {   // Search second half of range
        return binarySearch(middle, last, findme);
    }
}


// doSearch
// Do a search using function binarySearch with the given data & key.
// Print result.
void doSearch(const vector<int> & data,  // Data to search in
              int key,                   // Key to search for
              bool expect)               // Expected result
{
    // Do search
    cout << "Searching for key: " << key << endl;
    bool success = binarySearch(data.begin(), data.end(), key);

    // Print result
    cout << "Result: " << (success ? "found" : "not found") << endl;
    cout << "Same as expected result: "
         << (success == expect ? "yes" : "NO *************************")
         << endl;
    cout << endl;
}



// Main program
// Do several searches using binarySearch
int main()
{
    // Set up data to search
    vector<int> data;
    const int SIZE = 100000;
    for (auto i = 0; i < SIZE; ++i)
        data.push_back(10*i);

    doSearch(data, 40, true);   // Search for 40, expect to find it
    doSearch(data, 45, false);  // Search for 45, expect not to find it
    doSearch(data, 1000, true);
    doSearch(data, 1001, false);
    doSearch(data, -1, false);

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

