#pragma once
#include <vector>

using namespace std;

/**
* Graph representation using a weighted adjacency matrix.
* This is an undirected (two-way) graph where edges have weights.
*/
class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int verticesNumber;

public:
    /** Constructor for the Graph class
    *
    * @param verticesNum The number of vertices in the graph
    */
    Graph(int verticesNum);

    /** Function to add an edge to the graph
    *
    * @param u The starting vertex
    * @param v The ending vertex
    * @param weight The weight of the edge
    */
    void addEdge(int u, int v, int weight = 1);

    /** Function to get the weight of an edge
    *
    * @param u The starting vertex
    * @param v The ending vertex
    * @return The weight of the edge
    */
    int getEdge(int u, int v) const;

    /** Function to get the number of vertices in the graph
    *
    * @return The number of vertices
    */
    int getNumVertices() const;

    /** Function to get the adjacency matrix of the graph
    *
    * @return The adjacency matrix
    */
    const vector<vector<int>>& getAdjacencyMatrix() const;

    /** Function printing graph
    */
    void printGraph() const;
};