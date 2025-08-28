all:
	g++ -std=c++17 -I./include -o app src/main.cpp src/algorithms/DFS.cpp src/algorithms/BFS.cpp src/algorithms/Dijkstra.cpp src/algorithms/Algorithm.cpp src/utils/Graph.cpp src/tests/PerformanceTests.cpp src/utils/Menu.cpp

run: all
	./app.exe
