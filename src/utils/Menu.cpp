#include <iostream>
#include <vector>
#include <queue>
#include "algorithms/DFS.h"
#include "algorithms/BFS.h"
#include "algorithms/Dijkstra.h"
#include "tests/PerformanceTests.h"
#include "tests/ConcurrencyStackTests.h"
#include "tests/ConcurrencyQueueTests.h"
#include "tests/ConcurrencyPriorityQueueTests.h"
#include "utils/Menu.h"

int selectAction()
{
    cout << "\nChoose action:\n";
    cout << "1. Performance tests\n";
    cout << "2. Concurrency tests\n";
    cout << "3. Algorithms descriptions\n";
    cout << "4. Example algorithms runs\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
    int category;
    cin >> category;
    if (cin.fail() || category < 0 || category > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    return category;
}

void runPerformanceMenu(Graph &g)
{
    cout << "\nPerformance tests:\n";
    cout << "1. DFS Performance\n";
    cout << "2. BFS Performance\n";
    cout << "3. Dijkstra Performance\n";
    cout << "Your choice: ";
    int perfTest;
    cin >> perfTest;
    if (cin.fail() || perfTest < 1 || perfTest > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    switch (perfTest)
    {
    case 1:
        testDFSPerformance(g);
        break;
    case 2:
        testBFSPerformance(g);
        break;
    case 3:
        testDijkstraPerformance(g);
        break;
    default:
        cout << "Invalid performance test.\n";
        break;
    }
}

int selectThreadSafetyDataStructure()
{
    cout << "Choose data structure:\n";
    cout << "1. ThreadSafeStack<int>\n";
    cout << "2. std::stack<int>\n";
    cout << "3. ThreadSafeQueue<int>\n";
    cout << "4. std::queue<int>\n";
    cout << "5. ThreadSafePriorityQueue<int>\n";
    cout << "6. std::priority_queue<int>\n";
    cout << "Your choice: ";
    int dsType;
    cin >> dsType;
    if (cin.fail() || dsType < 1 || dsType > 6)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    return dsType;
}

void selectStackThreadSafetyTestType(int dsType)
{
    cout << "\nChoose Stack thread-safety test type:\n";
    cout << "1. Concurrent push\n";
    cout << "2. Concurrent pop\n";
    cout << "3. Concurrent top\n";
    cout << "4. Concurrent size\n";
    cout << "5. Concurrent empty\n";
    cout << "Your choice: ";
    int testType;
    cin >> testType;
    if (cin.fail() || testType < 1 || testType > 5)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }
    
    runStackThreadSafetyTest(dsType, testType);
}

void selectQueueThreadSafetyTestType(int dsType)
{
    cout << "\nChoose Queue thread-safety test type:\n";
    cout << "1. Concurrent push\n";
    cout << "2. Concurrent pop\n";
    cout << "3. Concurrent front\n";
    cout << "4. Concurrent back\n";
    cout << "5. Concurrent size\n";
    cout << "6. Concurrent empty\n";
    cout << "Your choice: ";
    int testType;
    cin >> testType;
    if (cin.fail() || testType < 1 || testType > 6)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }

    runQueueThreadSafetyTest(dsType, testType);
}

void selectPriorityQueueThreadSafetyTestType(int dsType)
{
    cout << "\nChoose Priority Queue thread-safety test type:\n";
    cout << "1. Concurrent push\n";
    cout << "2. Concurrent pop\n";
    cout << "3. Concurrent top\n";
    cout << "4. Concurrent size\n";
    cout << "5. Concurrent empty\n";
    cout << "Your choice: ";
    int testType;
    cin >> testType;
    if (cin.fail() || testType < 1 || testType > 5)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input.");
    }

    runPriorityQueueThreadSafetyTest(dsType, testType);
}

void runThreadSafetyMenu()
{
    int dsType = selectThreadSafetyDataStructure();
    int testType;

    if (dsType == 1 || dsType == 2)
    {
        selectStackThreadSafetyTestType(dsType);
    }
    else if (dsType == 3 || dsType == 4)
    {
        selectQueueThreadSafetyTestType(dsType);
    }
    else if (dsType == 5 || dsType == 6)
    {
        selectPriorityQueueThreadSafetyTestType(dsType);
    }
    else
    {
        cout << "Invalid data structure type.\n";
    }
}

void runStackThreadSafetyTest(int dsType, int testType)
{
    switch (testType)
    {
    case 1:
        if (dsType == 1)
            testStackConcurrentPush<ThreadSafeStack<int>>();
        else
            testStackConcurrentPush<stack<int>>();
        break;
    case 2:
        if (dsType == 1)
            testStackConcurrentPop<ThreadSafeStack<int>>();
        else
            testStackConcurrentPop<stack<int>>();
        break;
    case 3:
        if (dsType == 1)
            testStackConcurrentTop<ThreadSafeStack<int>>();
        else
            testStackConcurrentTop<stack<int>>();
        break;
    case 4:
        if (dsType == 1)
            testStackConcurrentSize<ThreadSafeStack<int>>();
        else
            testStackConcurrentSize<stack<int>>();
        break;
    case 5:
        if (dsType == 1)
            testStackConcurrentEmpty<ThreadSafeStack<int>>();
        else
            testStackConcurrentEmpty<stack<int>>();
        break;
    default:
        cout << "Invalid test type.\n";
        break;
    }
}

void runQueueThreadSafetyTest(int dsType, int testType)
{
    switch (testType)
    {
    case 1:
        if (dsType == 3)
            testQueueConcurrentPush<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentPush<queue<int>>();
        break;
    case 2:
        if (dsType == 3)
            testQueueConcurrentPop<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentPop<queue<int>>();
        break;
    case 3:
        if (dsType == 3)
            testQueueConcurrentFront<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentFront<queue<int>>();
        break;
    case 4:
        if (dsType == 3)
            testQueueConcurrentBack<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentBack<queue<int>>();
        break;
    case 5:
        if (dsType == 3)
            testQueueConcurrentSize<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentSize<queue<int>>();
        break;
    case 6:
        if (dsType == 3)
            testQueueConcurrentEmpty<ThreadSafeQueue<int>>();
        else
            testQueueConcurrentEmpty<queue<int>>();
        break;
    default:
        cout << "Invalid test type.\n";
        break;
    }
}

void runPriorityQueueThreadSafetyTest(int dsType, int testType)
{
    switch (testType)
    {
    case 1:
        if (dsType == 5)
            testPriorityQueueConcurrentPush<ThreadSafePriorityQueue<int>>();
        else
            testPriorityQueueConcurrentPush<priority_queue<int>>();
        break;
    case 2:
        if (dsType == 5)
            testPriorityQueueConcurrentPop<ThreadSafePriorityQueue<int>>();
        else
            testPriorityQueueConcurrentPop<priority_queue<int>>();
        break;
    case 3:
        if (dsType == 5)
            testPriorityQueueConcurrentTop<ThreadSafePriorityQueue<int>>();
        else
            testPriorityQueueConcurrentTop<priority_queue<int>>();
        break;
    case 4:
        if (dsType == 5)
            testPriorityQueueConcurrentSize<ThreadSafePriorityQueue<int>>();
        else
            testPriorityQueueConcurrentSize<priority_queue<int>>();
        break;
    case 5:
        if (dsType == 5)
            testPriorityQueueConcurrentEmpty<ThreadSafePriorityQueue<int>>();
        else
            testPriorityQueueConcurrentEmpty<priority_queue<int>>();
        break;
    default:
        cout << "Invalid test type.\n";
        break;
    }
}

void showAlgorithmDescriptions(Graph &g)
{
    cout << "Algorithm descriptions:\n";
    BFS bfs(g);
    DFS dfs(g);
    Dijkstra dijkstra(g);
    int idx = 1;
    cout << idx++ << ". " << bfs.describe() << endl;
    cout << idx++ << ". " << dfs.describe() << endl;
    cout << idx++ << ". " << dijkstra.describe() << endl;

    bfs.~BFS();
    dfs.~DFS();
    dijkstra.~Dijkstra();
}

void showExampleAlgorithmRuns(Graph &g)
{
    cout << "Example algorithm runs for graph:\n";
    g.printGraph();
    cout << endl;

    cout << "Dijkstra algorithm from node 0 to 4:\n";
    cout << "Result using custom Priority Queue:\n";
    auto pq = ThreadSafePriorityQueue<pair<int, int>, greater<pair<int, int>>>();
    Dijkstra dijkstra(g);
    dijkstra.runTemplate(0, 4, &pq);
    cout << "Result using STL Priority Queue:\n";
    auto pq1 = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    Dijkstra dijkstra2(g);
    dijkstra2.runTemplate(0, 4, &pq1);

    cout << "DFS algorithm from node 0:\n";
    cout << "Result using custom Stack:\n";
    DFS dfs(g);
    dfs.run(0, 4);
    cout << "Result using STL Stack:\n";
    DFS dfs2(g);
    dfs2.run(0, 4);

    cout << "BFS algorithm from node 0:\n";
    cout << "Result using custom Queue:\n";
    BFS bfs(g);
    bfs.run(0, 4);
    cout << "Result using STL Queue:\n";
    BFS bfs2(g);
    bfs2.run(0, 4);
}
