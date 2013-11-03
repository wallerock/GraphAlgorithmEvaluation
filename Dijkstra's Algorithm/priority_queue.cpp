#include <iostream>
#include "priority_queue.h"

using namespace std;

// default Constructor
PriorityQueue::PriorityQueue() {

}

// Changes the priority of queue element
void PriorityQueue::chgPrioirity(int element, int priority, int ancestor) {
        //alloc memory for an array
	int **elements = new int*[pq.size()];

       
	for (int i = 0; i < pq.size(); i++)
		elements[i] = new int[3];

	int index = 0;	
	bool found = false;

	while (!pq.empty()) {
		elements[index] = pq.top();
		pq.pop();
		if (elements[index][0] == element) {
			found	= true;
			elements[index][1] = priority;
			elements[index][2] = ancestor;	//last connection node
		}
		index++;
		if (found)
			break;
	}
	
        //put elements back in queue
	for (int i = 0; i < index; i++)
		pq.push(elements[i]);
}

// Removes the top element of the queue
void PriorityQueue::minPrioirty() {
	pq.pop(); //pop one element
}

// Checks if the queue contains element
bool PriorityQueue::contains(int element) {
	int **elements = new int*[pq.size()];
	for (int i = 0; i < pq.size(); i++)
		elements[i] = new int[3];

	int index = 0;	
	bool found = false;

	while (!pq.empty()) {
		elements[index] = pq.top();
		pq.pop();
		if (elements[index][0] == element) {
			found	= true;	
		}
		index++;
		if (found)
			break;
	}
	
	for (int i = 0; i < index; i++)
		pq.push(elements[i]);

	return found;
}

// Inserts element into queue
void PriorityQueue::insert(int *element) {
	pq.push(element);  //put into queue
}

// Returns the priority of the element
int PriorityQueue::get_priority(int element) {
	int priority;	
	
	int **elements = new int*[pq.size()];
	for (int i = 0; i < pq.size(); i++)
		elements[i] = new int[3];

	int index = 0;	
	bool found = false;

	while (!pq.empty()) {
		elements[index] = pq.top();
		pq.pop();
		if (elements[index][0] == element) {
			found	= true;
			priority = elements[index][1];
		}
		index++;
		if (found)
			break;
	}
	
	for (int i = 0; i < index; i++)
		pq.push(elements[i]);

	return priority;
}

// Returns the top element of the queue
int* PriorityQueue::top() {
	return pq.top();
}

// Returns the number of queue_elements
int PriorityQueue::size() {
	return pq.size();
}
