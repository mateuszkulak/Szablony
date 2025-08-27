#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Dijkstra's algorithm implementation.
 */
class Dijkstra : public Algorithm
{
private:
    vector<int> distances;
    vector<int> shortestPath;
    vector<int> shortestPathResult;
    Graph &graph;

    void dijkstraStlSearch(int start, int end);
    void dijkstraCustomSearch(int start, int end);

    template <typename PriorityQueueType>
    void dijkstraSearch(int start, int end, PriorityQueueType &pq)
    {
        distances.assign(graph.getNumVertices(), numeric_limits<int>::max());
        shortestPath.assign(graph.getNumVertices(), -1);
        distances[start] = 0;
        pq.push({0, start});

        const vector<vector<int>> &adjacencyMatrix = graph.getAdjacencyMatrix();

        while (!pq.empty())
        {
            auto [dist, current] = pq.top();
            pq.pop();

            if (current == end)
            {
                reconstructPath(start, end);
                return;
            }

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor)
            {
                if (adjacencyMatrix[current][neighbor] == 0)
                    continue;
                int newDist = distances[current] + graph.getEdge(current, neighbor);
                if (newDist < distances[neighbor])
                {
                    distances[neighbor] = newDist;
                    shortestPath[neighbor] = current;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }

    void reconstructPath(int start, int end)
    {
        shortestPathResult.clear();
        for (int v = end; v != -1; v = shortestPath[v])
        {
            shortestPathResult.push_back(v);
        }
        reverse(shortestPathResult.begin(), shortestPathResult.end());
    }

public:
    /**
     * Constructor for Dijkstra algorithm.
     *
     * @param[in] g Reference to the graph to be searched.
     */
    Dijkstra(Graph &g);

    /**
     * Destructor for Dijkstra algorithm.
     */
    ~Dijkstra();

    /**
     * Runs the Dijkstra algorithm.
     *
     * @param[in] start The starting node for the search.
     * @param[in] end The target node for the search.
     * @param[in] useCustomDataStructure Flag to use a custom data structure.
     */
    void run(int start, int end, bool useCustomDataStructure);

    /**
     * Describes the Dijkstra algorithm.
     *
     * @return A description of the algorithm.
     */
    const char *describe() const override;

    /**
     * Gets the shortest path from the start node to the end node.
     *
     * @return A vector of shortest path node IDs.
     */
    const vector<int> &getShortestPath() const;
};