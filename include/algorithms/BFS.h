#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>

using namespace std;

class BFS : public Algorithm {
private:
    vector<bool> visited;
    vector<int> visitedOrder;
    Graph& graph;

    void bfsStlSearch(int start);
    void bfsCustomSearch(int start);

    template <typename QueueType>
    void bfsGenericSearch(int start, QueueType& q) {
        q.push(start);
        visited[start] = true;

        const vector<vector<int>>& adjacencyMatrix = graph.getAdjacencyMatrix();

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visitedOrder.push_back(current);

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
                if (adjacencyMatrix[current][neighbor] && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    BFS(Graph& g);
    ~BFS();

    void run(int start, bool useCustomDataStructure);
    const vector<int>& getVisitedOrder() const;
};
