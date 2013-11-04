#include <vector>
#include <iostream>

using namespace std;

class Graph {
	private:
		int vertices;		// Number of vertices
		int edges;	        // Number of edges
		float density; 	        // Density of the graph
		int max_cost;	        // Maximum cost between two vertices
		int **costMatrix;	// Distance cost matrix
	public:
		Graph();                         //default constructor
		Graph(int v, float d, int c);    //constructor arg:vertices, density, cost
		int V();                         //get_number_of_vertices
		int E();                         //get_number_of_edges
		bool adjacent(int x, int y);     //tests whether there is an edge from node x to node y.
		vector<int> neighbors(int x);    //lists all nodes y such that there is an edge from x to y.
		void add_edge(int x, int y);     // adds to G the edge from x to y, if it is not there.
		void delete_edge(int x, int y);	 //removes the edge from x to y, if it is there.
		int get_cost(int x, int y);      //get edge's cost between node x and node y
};

