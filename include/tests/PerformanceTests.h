#pragma once
#include "utils/Graph.h"

/**
 * Tests the performance of Depth-First Search (DFS) on the graph,
 * comparing the performance of a custom stack implementation versus the STL stack.
 *
 * @param g The graph to test.
 */
void testDFSPerformance(Graph &g);

/**
 * Tests the performance of Breadth-First Search (BFS) on the graph,
 * comparing the performance of a custom queue implementation versus the STL queue.
 *
 * @param g The graph to test.
 */
void testBFSPerformance(Graph &g);

/**
 * Tests the performance of Dijkstra's algorithm on the graph,
 * comparing the performance of a custom priority queue implementation versus the STL priority queue.
 *
 * @param g The graph to test.
 */
void testDijkstraPerformance(Graph &g);
