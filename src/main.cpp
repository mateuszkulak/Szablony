#include <iostream>
#include <vector>
#include "utils/Graph.H"
#include "algorithms/DFS.h"

using namespace std;

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 6);

    g.printGraph();
    DFS dfs(g);
    dfs.run(0, false);
}