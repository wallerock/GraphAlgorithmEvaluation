#include <queue>

using namespace std;

class PriorityQueue {
	private:
		struct Comparator {
			bool operator()(const int *array1, const int *array2) {return (*(array1+1) > *(array2+1));}
		};

		priority_queue <int*, vector<int*>, Comparator> pq;	
	public:
		PriorityQueue();
		void chgPrioirity(int element, int priority, int ancestor);  //changes the priority (node value) of queue element.
		void minPrioirty();                                          // removes the top element of the queue.
		bool contains(int element);                                  //does the queue contain queue_element
		void insert(int *element);                                   //insert queue_element into queue
		int get_priority(int element);                               //return elements's get priority
		int* top();                                                  //returns the top element of the queue.
		int size();                                                  //return the number of queue_elements.
};


/* use queue to save an integer array: int[0] keep the node number, 
  int[1] keep the cost to source, and int[2] keep the last conectors number*/
