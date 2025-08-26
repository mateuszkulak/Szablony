#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Dijkstra : public Algorithm {
private:
    vector<int> distances;
    vector<int> shortestPath;
    vector<int> shortestPathResult;
    Graph& graph;

    void dijkstraStlSearch(int start, int end);
    void dijkstraCustomSearch(int start, int end);

    template<typename PriorityQueueType>
    void dijkstraSearch(int start, int end, PriorityQueueType& pq) {
        distances.assign(graph.getNumVertices(), numeric_limits<int>::max());
        shortestPath.assign(graph.getNumVertices(), -1);
        distances[start] = 0;
        pq.push({0, start});

        const vector<vector<int>>& adjacencyMatrix = graph.getAdjacencyMatrix();

        while (!pq.empty()) {
            auto [dist, current] = pq.top();
            pq.pop();

            if (current == end) {
                reconstructPath(start, end);
                return;
            }

            for (int neighbor = 0; neighbor < adjacencyMatrix.size(); ++neighbor) {
                if (adjacencyMatrix[current][neighbor] == 0) continue;
                int newDist = distances[current] + graph.getEdge(current, neighbor);
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    shortestPath[neighbor] = current;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }

    void reconstructPath(int start, int end) {
        shortestPathResult.clear();
        for (int v = end; v != -1; v = shortestPath[v]) {
            shortestPathResult.push_back(v);
        }
        reverse(shortestPathResult.begin(), shortestPathResult.end());
    }

public:
    Dijkstra(Graph& g);
    ~Dijkstra();

    void run(int start, int end, bool useCustomDataStructure);
    const char* describe() const override;
    const vector<int>& getShortestPath() const;
};