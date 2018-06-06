#include "Queue.hpp"
#include "Util.hpp"

int main()
{
	std::vector<std::string> vec;
	int selection = 0;
	int num = 0;
	std::string input;
	Queue q;

	cout << "Welcome to the magical doubly linked circular queue! Mouthful I know. " << endl;
	cout << "Please enter 0 to see the menu, or 5 to exit. " << endl;
	

	while (selection != 5)
	{
		menu(selection, vec, "Add a value to the back of the queue. ", "Display the front value. ", "Remove the front node. ", "Display the queue's content. ", "Exit. ");

		switch (selection)
		{
		case 1:
			cout << "Please enter a number to be added to the end of the queue. " << endl;
			num = getInt(input, 0, 1000000);
			q.addBack(num);
			cout << "Please enter 0 to see the menu options again. " << endl;
			break;
		case 2:
			cout << "The front value of the queue is " <<  q.getFront() << endl;
			cout << "Please enter 0 to see the menu options again. " << endl;
			break;
		case 3:
			q.removeFront();
			cout << "Please enter 0 to see the menu options again. " << endl;
			break;
		case 4:
			q.printQueue();
			cout << "Please enter 0 to see the menu options again. " << endl;
			break;
		default:
			break;
		}

		//menu(selection, vec, "Add a value to the back of the queue. ", "Display the front value. ", "Remove the front node. ", "Display the queue's content. ", "Exit. ");
	}

	return 0;
}