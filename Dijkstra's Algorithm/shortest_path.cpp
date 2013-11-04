#include "shortest_path.h"
#include <iostream>

//Constructor
ShortestPath::ShortestPath(Graph In) {
	g=In;
}


// Finds the shortest path and returns the sequence of vertices representing it
vector<int> ShortestPath::path(int target) {
	int vertices = g.V();
	int *temp;
	vector<int*> visited_nodes;
	vector<int> neighbors;
	int previous_node = -1;
        int previous_distance, pr;
	bool visited = false;
	bool found = false;

	temp = new int[3];
	temp[0] = temp[1] = 0;
	temp[2] = -1;
	pq.insert(temp);
	while (pq.size() > 0) {
		previous_node = pq.top()[0];
		previous_distance = pq.top()[1];
		pr = pq.top()[2];
		temp = new int[3];
		temp[0] = previous_node;
		temp[1] = previous_distance;
		temp[2] = pr;
		visited_nodes.insert(visited_nodes.begin(), temp);
		pq.minPrioirty(); 
		if (previous_node != (target)) {
			neighbors = g.neighbors(previous_node);
			for (int i = 0; i < neighbors.size(); i++) {
				visited = false; 
				for (int j = 0; j < visited_nodes.size(); j++) {
					if (neighbors[i] == visited_nodes[j][0]) {
						visited = true;
						if ((previous_distance + g.get_cost(previous_node, neighbors[i])) < visited_nodes[j][1]) {
							visited_nodes[j][1] = previous_distance + g.get_cost(previous_node, neighbors[i]);
							visited_nodes[j][2] = previous_node;
							break;
						}
						else 
							break;				
					}
				}	
				if (!visited) {
					if (pq.contains(neighbors[i])) {
						if ((previous_distance + g.get_cost(previous_node, neighbors[i])) < pq.get_priority       (neighbors[i])) {
							pq.chgPrioirity(neighbors[i], (previous_distance + g.get_cost(previous_node, neighbors[i])), previous_node);
						}
					}
					else {
						temp = new int[3];
						temp[0] = neighbors[i];
						temp[1] = previous_distance + g.get_cost(previous_node, neighbors[i]);
						temp[2] = previous_node;
						pq.insert(temp);
					}
				}
			}
		}
		for (int i = 0; i < visited_nodes.size(); i++) {
			if (visited_nodes[i][0] == (target) && pq.top()[1] >= visited_nodes[i][1]) {
				found = true;;
				break;	
			}
		}
		if (found) 
			break;
	}

	vector<int> path;
	if (!found) {
		return path;
	}
	else {
		int next_node = target;
		while (next_node != -1) {
			path.insert(path.begin(), next_node);
			for (int i = 0; i < visited_nodes.size(); i++) {
				if (visited_nodes[i][0] == next_node) {
					next_node = visited_nodes[i][2];
					break;	
				}
			}
		}
		return path;
	}
}

// Returns the path cost associated with the shortest path
int ShortestPath::path_size(vector<int> v) {
	int distance = 0.0;
	int previous_node = 0;
	
	for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
    	distance += g.get_cost(previous_node, v[i]);
		previous_node = v[i];
	}
	return distance;
}
