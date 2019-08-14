#include<iostream>
using namespace std;

class Node
{
    public:
	int value;
	Node* next;

	Node(int val) {	
		this->value = val;
		next = nullptr;	
	}

	//Node(int val) : value(value), next(nullptr) {}
};

/*struct Node {
	int value;
	Node * next;
	Node(int v) : value(v), next(nullptr) {}
};
*/
class LinkedList {
    public:
	Node* head;
	LinkedList() {
		head = nullptr;
	}
	//~LinkedList();
	//LinkedList() : head(nullptr) {}
};

int main() {

	// The head of the list never changes
	LinkedList myList;
	// These allow us to traverse the list
	Node* curr, * newLink;
	int i;

	// Start at the beginning, insert items at the back
	myList.head = new Node(1); //head is a pointer and Node(1) is also a pointer, that's why we don't use ->
							   // head -> next = 10 ~ (*head).next = 10 0
	curr = myList.head;

	for (i = 2; i < 10; i++) {
		// Create a new link
		newLink = new Node(i * i);
		// The last item should point to the new one
		curr->next = newLink;
		// The new one is now the last item
		curr = newLink;
	}
	// The last item still points to nullptr‘

	// To print the list
	// Get the first item in the list
	curr = myList.head;
	while (curr != nullptr) {
		// Print the current item’s value
		cout << curr->value << endl;
		// Move to the next item
		curr = curr->next;
	}

}

