#include <iostream>
#include <vector>
#include "utils/Graph.H"
#include "algorithms/DFS.h"
#include "tests/PerformanceTests.h"
#include "tests/ThreadSafeStackTest.h"

using namespace std;

int selectTestCategory() {
    cout << "\nChoose test category:\n";
    cout << "1. Performance tests\n";
    cout << "2. Thread-safety tests\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
    int category;
    cin >> category;
    if (cin.fail() || category < 0 || category > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    return category;
}

void runPerformanceMenu(Graph& g) {
    cout << "\nPerformance tests:\n";
    cout << "1. DFS Performance\n";
    cout << "Your choice: ";
    int perfTest;
    cin >> perfTest;
    if (cin.fail() || perfTest != 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    testDFSPerformance(g);
}

int selectThreadSafetyDataStructure() {
    cout << "Choose data structure:\n";
    cout << "1. ThreadSafeStack<int>\n";
    cout << "2. std::stack<int>\n";
    cout << "Your choice: ";
    int dsType;
    cin >> dsType;
    if (cin.fail() || dsType < 1 || dsType > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    return dsType;
}

int selectThreadSafetyTestType() {
    cout << "\nChoose thread-safety test type:\n";
    cout << "1. Concurrent push\n";
    cout << "2. Concurrent pop\n";
    cout << "3. Concurrent top\n";
    cout << "4. Concurrent size\n";
    cout << "5. Concurrent empty\n";
    cout << "Your choice: ";
    int testType;
    cin >> testType;
    if (cin.fail() || testType < 1 || testType > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    return testType;
}

void runThreadSafetyMenu() {
    int dsType = selectThreadSafetyDataStructure();
    int testType = selectThreadSafetyTestType();
    switch (testType) {
        case 1:
            if (dsType == 1) testStackConcurrentPush<ThreadSafeStack<int>>();
            else testStackConcurrentPush<stack<int>>();
            break;
        case 2:
            if (dsType == 1) testStackConcurrentPop<ThreadSafeStack<int>>();
            else testStackConcurrentPop<stack<int>>();
            break;
        case 3:
            if (dsType == 1) testStackConcurrentTop<ThreadSafeStack<int>>();
            else testStackConcurrentTop<stack<int>>();
            break;
        case 4:
            if (dsType == 1) testStackConcurrentSize<ThreadSafeStack<int>>();
            else testStackConcurrentSize<stack<int>>();
            break;
        case 5:
            if (dsType == 1) testStackConcurrentEmpty<ThreadSafeStack<int>>();
            else testStackConcurrentEmpty<stack<int>>();
            break;
        default:
            cout << "Invalid test type.\n";
            break;
    }
}

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

    while (true) {
        int category = selectTestCategory();
        if (category == 0) break;
        if (category == 1) {
            runPerformanceMenu(g);
        } else if (category == 2) {
            runThreadSafetyMenu();
        }
    }
}