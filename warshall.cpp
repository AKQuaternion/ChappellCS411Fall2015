// warshall.cpp  UNFINISHED
// Glenn G. Chappell
// 9 Nov 2015
//
// For CS 411/611 Fall 2015
// Warshall's Algorithm

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <vector>
using std::vector;
#include <cstdlib>
using std::size_t;


// warshall
// Given the adjacency matrix of a digraph, computes the adjacency
//  matrix of the transitive closure of the digraph, using Warshall's
//  Algorithm.
//
// Input adjacency matrix is given in adjmat, with its order in N.
//  adjmat[i*N + j] is 1 if there is a directed edge from vertex i to
//  vertex j, 0 otherwise,
// Output adjacency matrix is returned in the same format.
//
// Pre:
//     adjmat has size at least N*N.
//     adjmat[i*N + j] is either 0 or 1, for 0 <= i,j < N.
// Post:
//     Considering adjmat[..] as an adjacency matrix (see above),
//      adjacency matrix of transitive closure lies in return value.
vector<int> warshall(const vector<int> & adjmat,
                     size_t N)
{
    // WRITE THIS!!!
    return adjmat;  // Dummy return
}


// printMatrix
// Given a matrix stored in a vector, with the (i,j) entry stored in
// matrix[i*numcols+j], print the matrix, entries separated by blanks,
// rows ending with newline.
void printMatrix(const vector<int> & matrix,
                 size_t numcols)
{
    for (size_t row = 0; (row+1)*numcols-1 < matrix.size(); ++row)
    {
        for (size_t col = 0; col < numcols; ++col)
        {
            cout << setw(3) << matrix[row*numcols+col] << " ";
        }
        cout << endl;
    }
}


// Main program
// Demonstrate use of function warshall.
int main()
{
    const size_t N = 5;  // Number of vertices of digraph

    // Set up adjacency matrix of digraph
    vector<int> adjmat(N*N, 0);
    adjmat[0*N + 1] = 1;
    adjmat[1*N + 0] = 1;
    adjmat[1*N + 4] = 1;
    adjmat[1*N + 3] = 1;
    adjmat[4*N + 2] = 1;
    adjmat[4*N + 3] = 1;

    // Print original adjacency matrix
    cout << "Original digraph:" << endl;
    printMatrix(adjmat, N);
    cout << endl;

    // Compute transitive closure
    vector<int> result = warshall(adjmat, N);

    // Print transitive closure
    cout << "Transitive closure:" << endl;
    printMatrix(result, N);
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

