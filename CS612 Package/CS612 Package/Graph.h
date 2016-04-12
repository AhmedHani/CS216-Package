#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#define Max 200 + 5
#define INF 1000000000

template <class T, class W>
struct Edge {
	T from;
	T to;
	W weight;

	Edge(T from, T to, W weight) {
		this->from = from;
		this->to = to;
		this->weight = weight;
	}
};

template <class T, class W>
class Graph {
private:
	vector<T> nodes;
	vector<vector<T>> adjacency_matrix;
	vector<vector<T>> adjacency_list;
	vector<Edge<T, W>> edge_list;

public:
	Graph() {

	}

	Graph(vector<T> nodes) {
		this->nodes = nodes;
	}

	Graph(vector<T> nodes, vector<vector<T>> adjacency_matrix, bool matrix = false) {
		this->nodes = nodes;

		if(matrix == true)
			this->adjacency_matrix = adjacency_matrix;
		else
			this->adjacency_list = adjacency_list;
	}

	Graph(vector<T> nodes, vector<Edge<T, W>> edge_list) {
		this->nodes = nodes;
		this->edge_list = edge_list;
	}

	 vector<Edge<T, W>> get_nodes() {
		 return this->nodes;
	 }

	 void set_adjacency_nodes(vector<T> nodes) {
		 this->nodes = nodes;
	 }

	 vector<vector<T>> get_adjacency_matrix() {
		 return this->adjacency_matrix;
	 }

	 void set_adjacency_matrix(vector<vector<T>> adjacency_matrix) {
		 this->adjacency_matrix = adjacency_matrix;
	 }

	 vector<vector<T>> get_adjacency_list() {
		 return this->adjacency_list;
	 }

	 void set_adjacency_list(vector<vector<T>> adjacency_list) {
		 this->adjacency_list = adjacency_list;
	 }

	 vector<Edge<T, W>> get_edge_list() {
		 return this->edge_list;
	 }

	 void set_edge_list(vector<Edge<T, W>> edge_list) {
		 this->edge_list = edge_list;
	 }

	 W bellman_ford(T source, T destination, bool has_negative_cycles) {
		 vector<W> distance(this->nodes.size() + 1); // distance to reach a vertex
		 vector<T> predecessor(this->nodes.size() + 1); // pointer for the predecessor of nodes, could be replaced by successor

		 //initialize with inf.
		 for (size_t i : this->nodes) {
			 distance[i] = INF;
			 predecessor[i] = INF;
		 }

		 distance[source] = (W)0;

		 //edges relaxation step
		 for (size_t i = 1; i < this->nodes.size() - 1; i++) {
			 for (Edge<T, W> edge : this->edge_list) {
				 T from = edge.from;
				 T to = edge.to;
				 W weight = edge.weight;

				 if (distance[from] + weight < distance[to]) {
					 distance[to] = distance[from] + weight;
					 predecessor[to] = from;
				 }
			 }
		 }

		 //checking if there are negative cycles through the graph
		 for (Edge<T, W> edge : this->edge_list) {
			 T from = edge.from;
			 T to = edge.to;
			 W weight = edge.weight;

			 if (distance[to] + weight < distance[from])
				 has_negative_cycles = true;
		 }

		 if (has_negative_cycles) puts("The graph contains negative cycles!");

		 return distance[destination];
	 }

	 W dijkstra(T source, T destination) {

	 }
};