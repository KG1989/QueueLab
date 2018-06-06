#include "Queue.hpp"

Queue::Queue()
{
	head = NULL;
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		removeFront();
	}
}

bool Queue::isEmpty() const
{
	bool empty = false;

	if (head == NULL)
	{
		//cout << "There are no values in the queue" << endl << endl;
		return true;
	}
	else
	{
		//cout << "We got some values! " << endl;
		return false;
	}
}
void Queue::addBack(int addVal)
{
	QueueNode *n = new QueueNode;
	n->val = addVal;

	if (isEmpty())
	{
		//assign head to the new node cus its the first node entered
		head = n;
		//next points to head of list, prev points to head of list
		n->next = head;
		n->prev = head;
	}
	else
	{
		//links the prev part of the list cus head->prev always points to the end of the list
		//where the end of the list is the new node
		//head = n;
		n->next = head;
		head->prev->next = n;
		head->prev = n;
	}
}
int Queue::getFront()
{
	if (head == NULL)
	{
		cout << "The queue is empty. " << endl;
	}
	else
	{
		return head->val;
	}
}
void Queue::removeFront()
{
	//empty list case
	if (head == NULL)
	{
		cout << "List is empty, nothing to remove. " << endl;
	}
	//one node case, head->next points to head
	else if (head->next == head)
	{
		QueueNode *temp = head;
		head = NULL;
		delete temp;
	}
	else
	{
		QueueNode *temp = head;
		head->prev->next = head->next; //moves last node to head node
		head->next->prev = head->prev; //sets to front of queue
		head = head->next;
		delete temp;
	}
}
void Queue::printQueue() const
{
	//check if anything is in the list
	if (head == NULL)
	{
		cout << "The queue is empty. " << endl;
	}
	else
	{
		QueueNode *temp = NULL; //create a temp pointer to move through the list

		//assign this temp pointer to point where the head points
		temp = head;

		do
		{
			//cout the current value at that node
			cout << temp->val << endl;
			//move to the next node around the list
			temp = temp->next;
			//loop until we are back to the head again which will happen eventually
		} while (temp != head);
	}
}