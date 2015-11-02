// use_hash.cpp
// Glenn G. Chappell
// 1 Nov 2015
//
// For CS 411/611 Fall 2015
// C++11 Hash Table Demo

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;  // Hash table


// Given a string -> int unordered_map, and a key (string):
// - Determine whether the key lies in the hash table and print a
//   message indicating the result.
// - If the key lies in the hash table, then print the key and
//   associated value.
void check_key(const unordered_map<string, int> & h,
               const string & key)
{
    auto it = h.find(key);  // Could also use h.count(key) here
    cout << "Key \"" << key << "\": ";
    if (it == h.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "FOUND" << endl;
        cout << "  Key: " << it->first << endl;
        cout << "  Value: " << it->second << endl;
    }
}


// Main program
// Create a hash table and look for various keys in it.
int main()
{
    // Introductory message

    cout << "Mucking about with a hash table" << endl;
    cout << endl;

    // Make hash table

    unordered_map<string, int> h;  // Hash table

    // Insert ("abcd", 42) into hash table (CREATE operation)
    h["abcd"] = 42;
    // Insert ("aaa", -27) into hash table (CREATE operation)
    h["aaa"] = -27;
    // Change value associated wth "abcd" to 24 (UPDATE operation)
    h["abcd"] = 24;

    // Check whether various keys are in hash table

    check_key(h, "abc");
    cout << endl;
    check_key(h, "abcd");
    cout << endl;
    check_key(h, "x");
    cout << endl;
    check_key(h, "aaa");
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

