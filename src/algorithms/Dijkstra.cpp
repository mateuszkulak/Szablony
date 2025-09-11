#include "algorithms/Dijkstra.h"
#include <queue>
#include "custom_data_structures/ThreadSafePriorityQueue.h"
#include <iostream>

using namespace std;

Dijkstra::Dijkstra(Graph &g) : graph(g) {}

Dijkstra::~Dijkstra() {}

const char* Dijkstra::describe() const
{
    return "This is Dijkstra's algorithm. It finds the shortest path from a starting node to all other nodes in a weighted graph.";
}
