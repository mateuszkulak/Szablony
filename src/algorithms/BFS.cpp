#include "algorithms/BFS.h"
#include <queue>
#include "custom_data_structures/ThreadSafeQueue.h"
#include <iostream>

BFS::BFS(Graph& g) : graph(g) {
    visited = vector<bool>(g.getNumVertices(), false);
    visitedOrder = vector<int>();
}

BFS::~BFS() {}

void BFS::run(int start, bool useCustomDataStructure){
    if (useCustomDataStructure) {
        BFS::bfsCustomSearch(start);
    }
    else {
        BFS::bfsStlSearch(start);
    }

    for (int v : visitedOrder) {
        cout << v << " ";
    }
    cout << endl;
}

void BFS::bfsStlSearch(int v) {
    std::queue<int> q;
    bfsGenericSearch(v, q);
}

void BFS::bfsCustomSearch(int v) {
    ThreadSafeQueue<int> q;
    bfsGenericSearch(v, q);
}
