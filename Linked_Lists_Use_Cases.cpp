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

	//Some problem with this line
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

/*
It gives this
1 -> 4 -> 9 -> 16 -> 25 -> 36 -> 49 -> 64 -> 81
 */
//---------------------------------------------------------------------------------------------Insert at the head---------------------------------------------------------------------------------
	    /*Now let's insert 0 to replace 1 from the 1st position */
    
    // To print the list
	// Get the first item in the list
	curr = myList.head;
	while (curr != nullptr) {
		// Print the current item’s value
		cout << curr->value << " -> ";
		// Move to the next item
		curr = curr->next;
	}
	cout << endl;
    /*Now let's insert 0 to replace 1 from the 1st position */

    Node* new_head = new Node(0); 

    new_head ->next = myList.head;

    myList.head = new_head;

    	curr = myList.head;
	while (curr != nullptr) {
		// Print the current item’s value
		cout << curr->value << " -> ";
		// Move to the next item
		curr = curr->next;
	}
    	cout << endl;

/*Should return this
0 -> 1 -> 4 -> 9 -> 16 -> 25 -> 36 -> 49 -> 64 -> 81 
 */

//---------------------------------------------------------------------------------------------Insert in the middle---------------------------------------------------------------------------------

    /*Now let's insert 10 that should come afte 9 */


	// To print the list
	// Get the first item in the list and go until before 9

	curr = myList.head;
	while (curr != nullptr && curr -> value < 9) {
		// Print the current item’s value
		cout << curr->value << " -> ";
		// Move to the next item
		curr = curr->next;
	}
	cout << endl;
//Now we have the value of curr

Node* new_middle = new Node(10);

new_middle -> next = curr -> next;

curr -> next = new_middle;


    	curr = myList.head;
	while (curr != nullptr) {
		// Print the current item’s value
		cout << curr->value << " -> ";
		// Move to the next item
		curr = curr->next;
	}

	cout << endl;
//---------------------------------------------------------------------------------------------Insert in the middle---------------------------------------------------------------------------------

    /*Now let's insert 100 that should come afte 81 or the last position */
//if curr is the null pointer, it means that curr is on the last node. We need to assign the pointer of the last node the new node that will be the new last. 
//we need to go back at the head node
	curr = myList.head;
	while (curr -> next != nullptr) {
		// Print the current item’s value
		cout << curr->value << " -> ";
		// Move to the next item
		curr = curr->next;
        cout << curr << endl;
	}
    	cout << endl;

Node* new_last = new Node(100);

curr -> next  = new_last;

//we need to go back at the head node
	curr = myList.head;
	while (curr != nullptr) {
		// Print the current item’s value
		cout << curr->value << " ---> ";
		// Move to the next item
        
		curr = curr->next;
	}
    	cout << endl;

}

