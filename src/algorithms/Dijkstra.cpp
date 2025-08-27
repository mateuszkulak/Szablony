#include "algorithms/Dijkstra.h"
#include <queue>
#include "custom_data_structures/ThreadSafePriorityQueue.h"
#include <iostream>

using namespace std;

Dijkstra::Dijkstra(Graph &g) : graph(g) {}

Dijkstra::~Dijkstra() {}

void Dijkstra::run(int start, int end, bool useCustomDataStructure)
{
    if (useCustomDataStructure)
    {
        Dijkstra::dijkstraCustomSearch(start, end);
    }
    else
    {
        Dijkstra::dijkstraStlSearch(start, end);
    }

    for (size_t i = 0; i < graph.getNumVertices(); i++)
    {
        cout << distances[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < shortestPathResult.size(); i++)
    {
        cout << shortestPathResult[i] << " ";
    }
    cout << endl;
}

const char *Dijkstra::describe() const
{
    return "This is Dijkstra's algorithm. It finds the shortest path from a starting node to all other nodes in a weighted graph.";
}

void Dijkstra::dijkstraStlSearch(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dijkstraSearch(start, end, pq);
}

void Dijkstra::dijkstraCustomSearch(int start, int end)
{
    ThreadSafePriorityQueue<pair<int, int>, greater<pair<int, int>>> pq;
    dijkstraSearch(start, end, pq);
}