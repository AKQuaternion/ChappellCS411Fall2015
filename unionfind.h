// unionfind.h  UNFINISHED
// Glenn G. Chappell
// 11 Nov 2015
//
// For CS 411/611 Fall 2015
// Header for class UnionFind
// Union-Find Structure
// There is no associated source file

#ifndef FILE_UNIONFIND_H_INCLUDED
#define FILE_UNIONFIND_H_INCLUDED

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <cassert>
// for assert


// class UnionFind
// Union-Find structure.
// "Quick union" (rooted tree) implementation, with union-by-rank and
// path-compression optimizations.
//
// Items are nonnegative int values.
// Member functions:
// - makeSet (Make-Set operation)
// - find    (Find operation)
// - unionx  (Union operation)
class UnionFind {

// ***** UnionFind: ctors, dctor, op= *****
public:

    // Compiler generated default ctor, copy ctor, copy =, dctor used

// ***** UnionFind: general public functions *****
public:

    // makeSet
    // Make-Set operation.
    // Pre:
    //     x >= 0.
    void makeSet(int x)
    {
        // WRITE THIS!!!
    }

    // find
    // Find operation.
    // Pre:
    //     x >= 0.
    //     makeSet must have been previously called on x.
    int find(int x)
    {
        // WRITE THIS!!!
        return 0;  // Dummy return
    }

    // unionx
    // Union operation ("union" is a reserved word in C++).
    // Pre:
    //    x >= 0.
    //    y >= 0.
    //    makeSet must have been previously called on each of x, y.
    void unionx(int x,
                int y)
    {
        // WRITE THIS!!!
    }

// ***** UnionFind: internal-use types *****
private:

    // struct Info
    // Info on single item in union-find structure
    struct Info {
        int  _parent;  // Parent of item
        int  _rank;    // Tree rank; only valid for root item
        bool _inited;  // Has Make-Set been called on this item?
                       //  _parent, _rank fields invalid if !_inited

        // Ctor from field values, for convenience
        Info(int theParent,
             int theRank,
             bool theInited)
           :_parent(theParent),
            _rank(theRank),
            _inited(theInited)
        {}
    };

// ***** UnionFind: data members *****
private:

    vector<Info> _data;  // Info for each item

};  // End class UnionFind

#endif //#ifndef FILE_UNIONFIND_H_INCLUDED

