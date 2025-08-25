#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>

using namespace std;

class DFS : public Algorithm {
private:
    vector<bool> visited;
    vector<int> visitedOrder;
    Graph& graph;

    void dfsStlSearch(int v);
    void dfsCustomSearch(int v);

    template <typename StackType>
    void dfsGenericSearch(int v, StackType& s) {
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

public:
    DFS(Graph& g);
    ~DFS();

    void run(int start, bool useCustomDataStructure);
    const vector<int>& getVisitedOrder() const;
};
