#include "algorithms/DFS.h"
#include <stack>
#include "custom_data_structures/ThreadSafeStack.h"

DFS::DFS(Graph& g) : graph(g) {
    visited = vector<bool>(g.getNumVertices(), false);
    visitedOrder = vector<int>();
}

void DFS::run(int start, bool useCustomDataStructure){
    if (useCustomDataStructure) {
        DFS::dfsCustomSearch(start);
    }
    else {
        DFS::dfsStlSearch(start);
    }
}

void DFS::dfsStlSearch(int v) {
    stack<int> s;
    s.push(v);
    visited[v] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        visitedOrder.push_back(current);

        for (int neighbor : this->graph.getAdjacencyList()[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

void DFS::dfsCustomSearch(int v) {
    ThreadSafeStack<int> s;
    s.push(v);
    visited[v] = true;

    while (!s.empty()) {
        int current = s.pop();
        visitedOrder.push_back(current);

        for (int neighbor : this->graph.getAdjacencyList()[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}
