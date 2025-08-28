#include <iostream>
#include <vector>
#include "utils/Graph.h"
#include "utils/Menu.h"

using namespace std;

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 3);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 3, 6);

    Graph g1(10000);
    for (int i = 0; i < 9999; i++) {
        g1.addEdge(i, i+1);
    }

    int numNodes = 300;
    int numEdges = 1000;
    Graph g2(numNodes);

    srand(42);
    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % numNodes;
        int v = rand() % numNodes;
        if (u != v) {
            g2.addEdge(u, v);
        }
    }

    while (true) {
        system("cls");

        int action = selectAction();
        if (action == 0) break;
        if (action == 1) {
            runPerformanceMenu(g1);
        } else if (action == 2) {
            runThreadSafetyMenu();
        } else if (action == 3) {
            showAlgorithmDescriptions(g1);
        }
        else if (action == 4) {
            showExampleAlgorithmRuns(g);
        } else {
            cout << "Invalid action.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}