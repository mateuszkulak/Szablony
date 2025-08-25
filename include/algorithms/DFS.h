#pragma once
#include "Algorithm.h"
#include "utils/Graph.h"
#include <vector>

using namespace std;

class DFS : public Algorithm {
private:
    void dfsStlSearch(int v);
    void dfsCustomSearch(int v);

    vector<bool> visited;
    vector<int> visitedOrder;
    Graph& graph;

public:
    DFS(Graph& g);
    ~DFS();

    void run(int start, bool useCustomDataStructure);
    const vector<int>& getVisitedOrder() const;
};
