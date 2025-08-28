#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>

using namespace std;

/**
* Depth-First Search (DFS) algorithm implementation.
*/
class DFS : public Algorithm
{
private:
    vector<bool> visited;
    vector<int> visitedOrder;
    Graph &graph;

    void dfsStlSearch(int v);
    void dfsCustomSearch(int v);

    template <typename StackType>
    void dfsGenericSearch(int v, StackType &s)
    {
        s.push(v);
        const vector<vector<int>> &adjacencyMatrix = graph.getAdjacencyMatrix();

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (!visited[current])
            {
                visited[current] = true;
                visitedOrder.push_back(current);

                for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor)
                {
                    if (adjacencyMatrix[current][neighbor] && !visited[neighbor])
                    {
                        s.push(neighbor);
                    }
                }
            }
        }
    }

public:
    /**
    * Constructor for DFS algorithm.
    *
    * @param[in] g Reference to the graph to be searched.
    */
    DFS(Graph &g);

    /**
    * Destructor for DFS algorithm.
    */
    ~DFS();

    /**
    * Runs the DFS algorithm.
    *
    * @param[in] start The starting node for the search.
    * @param[in] useCustomDataStructure Flag to use a custom data structure.
    */
    void run(int start, bool useCustomDataStructure);

    /**
    * Describes the DFS algorithm.
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
