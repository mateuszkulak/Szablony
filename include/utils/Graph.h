#pragma once
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int verticesNumber;

public:
    Graph(int verticesNum);

    void addEdge(int u, int v, int weight = 1);
    int getEdge(int u, int v) const;
    int getNumVertices() const;
    const vector<vector<int>>& getAdjacencyMatrix() const;
    void printGraph() const;
};