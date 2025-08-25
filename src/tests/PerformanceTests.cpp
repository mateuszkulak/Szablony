#include "tests/PerformanceTests.h"
#include "algorithms/DFS.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;

void testDFSPerformance(Graph& g) {
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
