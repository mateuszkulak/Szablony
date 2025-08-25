#include <iostream>
#include <vector>
#include "utils/Graph.H"
#include "algorithms/DFS.h"
#include "tests/PerformanceTests.h"

using namespace std;

int main() {
    int numNodes = 300;
    int numEdges = 1000;
    Graph g(numNodes);

    srand(42);
    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % numNodes;
        int v = rand() % numNodes;
        if (u != v) {
            g.addEdge(u, v);
        }
    }

    testDFSPerformance(g);
}