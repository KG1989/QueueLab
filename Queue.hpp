#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using std::endl;
using std::cout;

class Queue 
{
private:
	struct QueueNode 
	{
		QueueNode* next;
		QueueNode* prev;
		int val;
		/*
		QueueNode(int val, QueueNode* next = NULL, QueueNode* prev = NULL) {
			this->val = val;
			this->next = next;
			this->prev = prev;
		}
		*/
	};

	QueueNode* head;

public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void addBack(int);
	int getFront();
	void removeFront();
	void printQueue() const;
};

#endif