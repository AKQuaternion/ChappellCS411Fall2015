// dijkstra.cpp  UNFINISHED
// Glenn G. Chappell
// 16 Nov 2015
//
// For CS 411/611 Fall 2015
// Dijkstra's Algorithm
// Based on prim.cpp

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <utility>
using std::pair;
using std::make_pair;
#include <queue>
using std::priority_queue;
#include <cassert>  // for assert


const int INF = -1;  // Used to represent +infinity

// We represent a weighted graph by an adjacency-matrix-like structure.
//  For an N-vertex graph, the structure is a vector<int> of size N*N.
//  Entry [i*N+j] is INF if there is no edge from i to j, and
//  nonnegative otherwise. This nonnegative value is the weight on the
//  edge from i to j.

typedef pair<int, int> Edge;    // Type for edge of graph
                                //  Integers are indices of endpoints.


// dijkstra
// Solve single-source shortest-path problem using Dijkstra's Algorithm.
// Given weighted graph (represented as discussed above), order of
// graph, adjacency lists, and start vertex. Return value is pair
// holding (1) edges of shortest-path tree, (2) vertex distances.
pair<vector<Edge>, vector<int> > dijkstra(
    const vector<int> & wgraph,             // weights
    int N,                                  // number of vertices
    const vector<vector<int> > & adjlists,  // adjacency lists
    int start)                              // index of start vertex
{
    // WRITE THIS!!!
    return make_pair(vector<Edge>(), vector<int>());  // Dummy return
}


// makeAdjLists
// Given weights for graph, with nonedges indicated by INF,
//  returns vector of adjacency lists.
vector<vector<int> > makeAdjLists(const vector<int> & wgraph,
                                  int N)  // number of vertices
{
    vector<vector<int> > adjlists;
    for (int i = 0; i < N; ++i)
    {
        adjlists.push_back(vector<int>());
        for (int j = 0; j < N; ++j)
        {
            if (wgraph[i*N + j] != INF)
                adjlists[i].push_back(j);
        }
    }
    return adjlists;
}


// printMatrix
// Given a matrix stored in a vector, with the (i,j) entry stored in
// matrix[i*numcols+j], print the matrix, entries separated by blanks,
// rows ending with newline.
void printMatrix(const vector<int> & matrix,
                 int numcols)
{
    for (int row = 0; size_t((row+1)*numcols) <= matrix.size(); ++row)
    {
        for (int col = 0; col < numcols; ++col)
        {
            int value = matrix[row*numcols+col];
            if (value == INF)
                cout << "  -";
            else
                cout << setw(3) <<value;
            cout << " ";
        }
        cout << endl;
    }
}

// setWeight
// Sets weight of a,b edge in N-vertex weighted graph described by
//  wgraph (see above).
void setWeight(vector<int> & wgraph, int N,
               int a, int b,
               int wt)
{
    wgraph[a*N + b] = wt;
    wgraph[b*N + a] = wt;
}


// main
// Example using function dijkstra
int main()
{
    const int N = 5;  // Number of vertices of graph

    // Set up weight matrix for graph;
    vector<int> wgraph(N*N, INF);
    setWeight(wgraph, N, 0, 1, 7);
    setWeight(wgraph, N, 0, 3, 4);
    setWeight(wgraph, N, 0, 4, 3);
    setWeight(wgraph, N, 1, 2, 2);
    setWeight(wgraph, N, 1, 3, 8);
    setWeight(wgraph, N, 1, 4, 6);
    setWeight(wgraph, N, 2, 3, 9);
    setWeight(wgraph, N, 2, 4, 5);
    setWeight(wgraph, N, 3, 4, 1);

    // Print weights
    cout << "Weight matrix:" << endl;
    printMatrix(wgraph, N);
    cout << endl;

    // Compute & print adjacency lists
    vector<vector<int> > adjlists = makeAdjLists(wgraph, N);
    cout << "Adjacency lists:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << i << ": ";
        for (int j = 0; size_t(j) < adjlists[i].size(); ++j)
        {
            if (j != 0)
                cout << ", ";
            cout << adjlists[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Run Dijkstra's Algorithm & print result
    cout << "Running Dijkstra's Algorithm" << endl;
    pair<vector<Edge>, vector<int> > p;
    p = dijkstra(wgraph, N, adjlists, 0);
    auto tree = p.first;
    auto dist = p.second;
    cout << "Edges in single-source shortest-path tree:" << endl;
    if (tree.size() == 0)
        cout << "[NONE]" << endl;
    for (int i = 0; size_t(i) < tree.size(); ++i)
    {
        cout << tree[i].first << ", " << tree[i].second << endl;
    }
    cout << endl;
    cout << "Vertex distances:" << endl;
    for (int i = 0; size_t(i) < dist.size(); ++i)
    {
        cout << i << ": ";
        if (dist[i] == INF)
            cout << "--";
        else
            cout << dist[i];
        cout << endl;
    }
    cout << endl;

    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

