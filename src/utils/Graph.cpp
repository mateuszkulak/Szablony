#include "utils/Graph.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Graph::Graph(int verticesNum)
    : verticesNumber(verticesNum), adjacencyMatrix(verticesNum, vector<int>(verticesNum, 0)) {}

void Graph::addEdge(int u, int v, int weight)
{
    if (u >= 0 && u < verticesNumber && v >= 0 && v < verticesNumber)
    {
        adjacencyMatrix[u][v] = weight;
        return;
    }
    throw out_of_range("Invalid edge");
}

int Graph::getEdge(int u, int v) const
{
    if (u >= 0 && u < verticesNumber && v >= 0 && v < verticesNumber)
    {
        return adjacencyMatrix[u][v];
    }
    return 0;
}

int Graph::getNumVertices() const
{
    return verticesNumber;
}

const vector<vector<int>> &Graph::getAdjacencyMatrix() const
{
    return adjacencyMatrix;
}

void Graph::printGraph() const
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < verticesNumber; ++i)
    {
        for (int j = 0; j < verticesNumber; ++j)
        {
            cout << setw(3) << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}