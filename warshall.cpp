// warshall.cpp
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

using AdjacencyMatrix = vector<vector<int>>;

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
AdjacencyMatrix warshall(const AdjacencyMatrix & adjmat)
{
    // d: temporary storage
    // Item i,j in adjacency matrix k is stored in d[k*n*n + i*n + j].
    // The item is 1 if there is a directed path in the original graph
    //  from vertex i to vertex j, using only intermediate vertices
    //  numbered less than k.
    // NOTE: This numbering scheme is slightly different from that in
    //  the Levitin text.
    const auto N = adjmat.size();
    vector<AdjacencyMatrix> d(N+1,AdjacencyMatrix(N,vector<int>(N)));
    
    // Copy adjacency matrix to d
    d[0] = adjmat;
    
    // Run Warshall's Algorithm
    for (size_t k = 1; k <= N; ++k)
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < N; ++j)
                d[k][i][j] = d[k-1][i][j] || (d[k-1][i][k] && d[k-1][k][j]);
    
    // Copy final matrix to storage for result and return it
    return d[N];
}


// printMatrix
// Given a matrix stored in a vector, with the (i,j) entry stored in
// matrix[i*numcols+j], print the matrix, entries separated by blanks,
// rows ending with newline.
void printMatrix(AdjacencyMatrix & matrix)
{
    for (const auto &row:matrix)
    {
        for (auto e:row)
        {
            cout << setw(3) << e << " ";
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
    AdjacencyMatrix adjmat(N,vector<int>(N,0));
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[1][4] = 1;
    adjmat[1][3] = 1;
    adjmat[4][2] = 1;
    adjmat[4][3] = 1;
    
    // Print original adjacency matrix
    cout << "Original digraph:" << endl;
    printMatrix(adjmat);
    cout << endl;
    
    // Compute transitive closure
    auto result = warshall(adjmat);
    
    // Print transitive closure
    cout << "Transitive closure:" << endl;
    printMatrix(result);
    cout << endl;
    
    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
    
    return 0;
}

