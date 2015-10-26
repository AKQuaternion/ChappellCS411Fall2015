// heap_sort.cpp  UNFINISHED
// Glenn G. Chappell
// 25 Oct 2015
//
// For CS 411/611 Fall 2015
// Heap algorithms & Heap Sort

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::swap;
using std::iter_swap;
#include <cassert>
// For assert


// testHeap
// Determines whether given random-access range is a Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <.
// Pre:
//     [first, last) is a valid range.
// Post:
//     Return value is true iff given range is a Heap.
template<typename RAIter>
bool testHeap(RAIter first, RAIter last)
{
    // WRITE THIS!!!
    return true;  // DUMMY
}


// heapInsert
// Heap insert operation on a random-access range.
// Inserts *(last-1) into Heap [first, last-1).
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last-1) forms a Heap.
// Post:
//     [first, last) forms a Heap with the items formerly in [first, last).
template<typename RAIter>
void heapInsert(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// trickleDown
// Internal-use function for heapDelete, makeHeap.
// Does "trickle down" of item at given location into existing partial
// Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     location lies in [first, last).
//     (location, last) is a partial Heap.
//      That is, !(first[(k-1)/2] < first[k]), whenever both
//      first+(k-1)/2 and first+k lie in (location, last).
// Post:
//     [location, last) is a partial Heap containing the same items as
//      initially.
template<typename RAIter>
void trickleDown(RAIter first, RAIter last, RAIter location)
{
    // WRITE THIS!!!
}


// heapDelete
// Heap delete operation on a random-access range.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last) forms a Heap.
// Post:
//     *(last-1) is the former *first.
//     [first, last-1) forms a Heap with the remaining items.
template<typename RAIter>
void heapDelete(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// makeHeap
// Turns the given random-access range into a Heap using a linear number
// of compare & swap operations.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) is a Heap containing the same items as initially.
template<typename RAIter>
void makeHeap(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// heapToSorted
// Given a Heap; makes it into a sorted list.
// Sorts the given Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last) is a Heap.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by <.
template<typename RAIter>
void heapToSorted(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// heapSort
// Sorts a sequence, using Heap Sort.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     operator< is a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by <.
template <typename RAIter>
void heapSort(RAIter first, RAIter last)
{
    // WRITE THIS!!!
}


// Main program
// Demonstrates use of function heapSort.
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
    heapSort(v.begin(), v.end());

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

