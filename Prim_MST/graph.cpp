#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graph.h"
#include <fstream>

// Default constructor
Graph::Graph() {

}

// Constructor
Graph::Graph(int v, float d, int c) {
	vertices = v;    //set vertices
	density = d;
	max_cost = c;
	edges=0;
	// Memory allocation to cost array
	costMatrix = new int*[vertices];
	for (int i = 0; i < vertices; i++) {
		costMatrix[i] = new int[vertices];
	}

	srand(time(NULL));// set Seed pseudo-random number generator 	
	
	// Fill cost array by random generator
	for (int i = 0; i < vertices; i++) {
		for (int j = i; j < vertices; j++) {
			if (i == j)	
				costMatrix[i][j] = 0;   //same node are no cost
			else {
				if (((double) rand() / (RAND_MAX)) < density) {
					costMatrix[i][j] = costMatrix[j][i] = rand() % max_cost + 1;  //set cost from 1-max cost
                                        edges++;
				}
				else {
					costMatrix[i][j] = costMatrix[j][i] = -1;  //no connecton
				}
			}
		}
	}

}

//hw3:constructor which read file.
Graph::Graph(char* filename){
    
    ifstream file;
    int node_a;
    int node_b;
    int cost;

    file.open(filename);

    if(!file){
    cout<<"File open error! check filename!\n";
    return;
    }

    file>>vertices;
    
    edges=0;

    // Memory allocation to cost array
    costMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
	costMatrix[i] = new int[vertices];
    }
    
    //init the costMatrix
    for (int i = 0; i < vertices; i++) {
		for (int j = i; j < vertices; j++) {
			if (i == j)	
				costMatrix[i][j] = 0;   //same node are no cost
			else {
				costMatrix[i][j]=-1;  //no connection;
			}
		}
	}

    while(file!=NULL){
        file>>node_a;
        file>>node_b;
        file>>cost;
        //cout<< node_a<<" "<<node_b<<" "<<cost<<endl;
        add_edge(node_a,node_b,cost);
    }
    
    file.close();
}





// get number of vertices
int Graph::V() {
	return vertices;
}

// Get number of edges
int Graph::E() {
	return edges;
}

// Tests whether there is an edge from node x to node y
bool Graph::adjacent(int x, int y) {
	if (costMatrix[x][y] > 0)
		return true;
	else
		return false;
}

// Lists all nodes y such that there is an edge from x to y
vector<int> Graph::neighbors(int x) {
	vector<int> neighbors;   //return vector

	for (int i = 0; i < vertices; i++) {
		if (costMatrix[x][i] > 0)
			neighbors.insert(neighbors.begin(), i);  //put i into vector neighbors
	}

	return neighbors;
}

// Adds the edge from x to y, if it is not there
void Graph::add_edge(int x, int y) {
	if (costMatrix[x][y] < 0) {
		srand(time(0));
		costMatrix[x][y] = costMatrix[y][x] = rand() % max_cost + 1;
                edges++;
	}
}

//HW3 add edge from file.
void Graph:: add_edge(int x, int y, int cost){
    if(costMatrix[x][y]<0){
    costMatrix[x][y] = costMatrix[y][x]=cost;
    edges++;
    }
}

// Removes the edge from x to y, if it is there
void Graph::delete_edge(int x, int y) {
	if (costMatrix[x][y] > 0) {
		costMatrix[x][y] = costMatrix[y][x] = -1;
                edges--;
	}	
}

// Returns the distance between two nodes
int Graph::get_cost(int x, int y) {
        if(x==y)
          return 0;

	if (costMatrix[x][y] > 0)
		return costMatrix[x][y];
	else
		return -1; //no conection
}
