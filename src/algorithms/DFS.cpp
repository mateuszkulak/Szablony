#include "algorithms/DFS.h"
#include <stack>
#include "custom_data_structures/ThreadSafeStack.h"
#include <iostream>

DFS::DFS(Graph& g) : graph(g) {
    visited = vector<bool>(g.getNumVertices(), false);
    visitedOrder = vector<int>();
}

DFS::~DFS() {}

void DFS::run(int start, bool useCustomDataStructure){
    if (useCustomDataStructure) {
        DFS::dfsCustomSearch(start);
    }
    else {
        DFS::dfsStlSearch(start);
    }

    for (int v : visitedOrder) {
        cout << v << " ";
    }
    cout << endl;
}

void DFS::dfsStlSearch(int v) {
    stack<int> s;
    s.push(v);
    const vector<vector<int>>& adjacencyMatrix = graph.getAdjacencyMatrix();

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            visitedOrder.push_back(current);

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
                if (adjacencyMatrix[current][neighbor] && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

void DFS::dfsCustomSearch(int v) {
    ThreadSafeStack<int> s;
    s.push(v);
    const vector<vector<int>>& adjacencyMatrix = graph.getAdjacencyMatrix();

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            visitedOrder.push_back(current);

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
                if (adjacencyMatrix[current][neighbor] && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}
