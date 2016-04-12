#include <iostream>
#include "Sort.h"
#include "Graph.h"

using namespace std;

int main() {
	vector<int> nodes;
	nodes.push_back(1);
	nodes.push_back(2);
	nodes.push_back(3);
	nodes.push_back(4);

	vector<Edge<int, double>> edges;
	edges.push_back(Edge<int, double>(1, 2, 1.0));
	edges.push_back(Edge<int, double>(1, 3, 1.0));
	edges.push_back(Edge<int, double>(2, 4, 4.0));
	edges.push_back(Edge<int, double>(3, 4, 0.0));
	edges.push_back(Edge<int, double>(1, 4, 4.0));
	edges.push_back(Edge<int, double>(4, 1, -4.0));


	Graph<int, double> g(nodes, edges);
	bool neg = false;
	cout << g.bellman_ford(1, 4, neg) << endl;


	return 0;
}