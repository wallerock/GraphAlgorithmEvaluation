#include "priority_queue.h"
#include "graph.h"

class ShortestPath {
	private:
		PriorityQueue pq;
		Graph g;	
	public:
		ShortestPath(Graph In);
                vector<int> vertices();//list of vertices in G(V,E).
		vector<int> path(int target);
		int path_size(vector<int>); // return the path cost associated with the shortest path.
};




