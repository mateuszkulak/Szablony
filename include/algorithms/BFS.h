#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>

using namespace std;

/**
* Breadth-First Search (BFS) algorithm implementation.
*/
class BFS : public Algorithm
{
private:
    vector<bool> visited;
    vector<int> visitedOrder;
    Graph &graph;

    void bfsStlSearch(int start);
    void bfsCustomSearch(int start);

    template <typename QueueType>
    void bfsGenericSearch(int start, QueueType &q)
    {
        q.push(start);
        visited[start] = true;

        const vector<vector<int>> &adjacencyMatrix = graph.getAdjacencyMatrix();

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            visitedOrder.push_back(current);

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor)
            {
                if (adjacencyMatrix[current][neighbor] && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    /**
    * Constructor for BFS algorithm.
    *
    * @param[in] g Reference to the graph to be searched.
    */
    BFS(Graph &g);

    /**
    * Destructor for BFS algorithm.
    */
    ~BFS();

    /**
    * Runs the BFS algorithm.
    *
    * @param[in] start The starting node for the search.
    * @param[in] useCustomDataStructure Flag to use a custom data structure.
    */
    void run(int start, bool useCustomDataStructure);

    /**
    * Describes the BFS algorithm.
    *
    * @return A description of the algorithm.
    */
    const char*describe() const override;

    /**
    * Gets the order of visited nodes.
    *
    * @return A vector of visited node IDs.
    */
    const vector<int> &getVisitedOrder() const;
};
