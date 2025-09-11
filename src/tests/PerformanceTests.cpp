#include "tests/PerformanceTests.h"
#include "algorithms/DFS.h"
#include "algorithms/BFS.h"
#include "algorithms/Dijkstra.h"
#include "custom_data_structures/ThreadSafePriorityQueue.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>

using namespace std::chrono;

void testDFSPerformance(Graph &g)
{
    DFS dfs(g);

    auto start = high_resolution_clock::now();
    dfs.run(0, true);
    auto end = high_resolution_clock::now();
    auto duration_custom = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time custom: " << duration_custom << " ms\n";

    start = high_resolution_clock::now();
    dfs.run(0, false);
    end = high_resolution_clock::now();
    auto duration_stl = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time STL: " << duration_stl << " ms\n";
}

void testBFSPerformance(Graph &g)
{
    BFS bfs(g);

    auto start = high_resolution_clock::now();
    bfs.run(0, true);
    auto end = high_resolution_clock::now();
    auto duration_custom = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time custom: " << duration_custom << " ms\n";

    start = high_resolution_clock::now();
    bfs.run(0, false);
    end = high_resolution_clock::now();
    auto duration_stl = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time STL: " << duration_stl << " ms\n";
}

void testDijkstraPerformance(Graph &g)
{
    Dijkstra dijkstra(g);

    auto start = high_resolution_clock::now();
    auto pq = ThreadSafePriorityQueue<pair<int, int>, greater<pair<int, int>>>();
    dijkstra.runTemplate(0, g.getNumVertices() - 1, &pq);
    auto end = high_resolution_clock::now();
    auto duration_custom = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time custom: " << duration_custom << " ms\n";

    start = high_resolution_clock::now();
    auto pq1 = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    dijkstra.runTemplate(0, g.getNumVertices() - 1, &pq1);
    end = high_resolution_clock::now();
    auto duration_stl = duration_cast<milliseconds>(end - start).count();
    std::cout << "Time STL: " << duration_stl << " ms\n";
}
