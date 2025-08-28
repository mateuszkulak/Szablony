#include "algorithms/DFS.h"
#include <stack>
#include "custom_data_structures/ThreadSafeStack.h"
#include <iostream>

DFS::DFS(Graph &g) : graph(g)
{
    visited = vector<bool>(g.getNumVertices(), false);
    visitedOrder = vector<int>();
}

DFS::~DFS() {}

void DFS::run(int start, bool useCustomDataStructure)
{
    if (useCustomDataStructure)
    {
        DFS::dfsCustomSearch(start);
    }
    else
    {
        DFS::dfsStlSearch(start);
    }

    for (int v : visitedOrder)
    {
        cout << v << " ";
    }
    cout << endl;
}

const char* DFS::describe() const
{
    return "This is the Depth-First Search (DFS) algorithm. It explores as far as possible along each branch before backtracking.";
}

void DFS::dfsStlSearch(int v)
{
    stack<int> s;
    dfsGenericSearch(v, s);
}

void DFS::dfsCustomSearch(int v)
{
    ThreadSafeStack<int> s;
    dfsGenericSearch(v, s);
}
