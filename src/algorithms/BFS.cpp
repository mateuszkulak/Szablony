#include "algorithms/BFS.h"
#include <queue>
#include "custom_data_structures/ThreadSafeQueue.h"
#include <iostream>

using namespace std;

BFS::BFS(Graph &g) : graph(g)
{
    visited = vector<bool>(g.getNumVertices(), false);
    visitedOrder = vector<int>();
}

BFS::~BFS() {}

void BFS::run(int start, bool useCustomDataStructure)
{
    if (useCustomDataStructure)
    {
        BFS::bfsCustomSearch(start);
    }
    else
    {
        BFS::bfsStlSearch(start);
    }

    for (int v : visitedOrder)
    {
        cout << v << " ";
    }
    cout << endl;
}

const char *BFS::describe() const
{
    return "This is the Breadth-First Search (BFS) algorithm. It explores all the neighbors at the present depth prior to moving on to the nodes at the next depth level.";
}

void BFS::bfsStlSearch(int v)
{
    queue<int> q;
    bfsGenericSearch(v, q);
}

void BFS::bfsCustomSearch(int v)
{
    ThreadSafeQueue<int> q;
    bfsGenericSearch(v, q);
}
