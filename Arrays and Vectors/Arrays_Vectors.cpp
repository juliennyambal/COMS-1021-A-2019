#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()


/*

|--------------------------------------------------------------|
|Data Type  |    Description                                   |
|--------------------------------------------------------------|
|int	    | A 32-bit integer
|double	    | A double-precision float
|bool	    | A Boolean value
|char	    | A single character
|int *	    | A pointer to an int (the address of an int)
|double *	| A pointer to a double (the address of a double)
|bool *	    | A pointer to a bool (the address of a bool)
|char *	    | A pointer to a char (the address of a char)
|--------------------------------------------------------------|

*/

{
	/*This will give you the size of the most common data type*/
	cout << "Size of an int: " << sizeof(int)<<endl;
	cout << "Size of an double: " << sizeof(double) << endl;
	cout << "Size of an char: " << sizeof(char) << endl;
	cout << "Size of an bool: " << sizeof(bool) << endl;
	cout << "Size of an float: " << sizeof(float) << endl;

	cout << "\n" << endl;

	int a = 10;
	double b = 10.0;
	char c = 'c';
	bool d = 1;
	float e = 10.0;

	//Pointers and derefrencing
	//We are defining a pointer ptr which has the address of a
	int* ptr = &a;
	
	//Address of a pointer
	cout << "Address of a is " << ptr << endl;

	//Value of that a pointer is pointing
	cout << "Value of a is " << *ptr << endl;

	int& var = a;
	cout <<"&var = "<< var << endl;

	cout << "\n" << endl;

	//conditions
	if (a > 10) {
		cout << "a is greater than 10" << endl;
	}
	else {
		cout << "a is less or equal to 10" << endl;
	}

	cout << "\n" << endl;

	//while loop
	while (a <20) {
		cout <<"while loop :"<<a << endl;
		a++;
	}

	cout << "\n" << endl;

	//for loop 
	for (int i = 1; i <= a; i++) {
		cout <<"For loop: "<< i << endl;
	}

	cout << "\n" << endl;

	//----------------------------------------------------------------------Arithmetic---------------------------------------------------------------------------

	int arr[5];     // 'a' is declared to be an array of 5 integers

	arr[0] = 5;    // the first (index 0) entry is set to 95
	arr[1] = 10;
	arr[2] = 12;
	arr[3] = 89;
	arr[4] = 78;    // the last (index 4) entry is set to 36

	for (int i = 0; i < 5; ++i) {
		cout << "The entry at index " << i << " is " << arr[i] << endl;
	}
	cout << " " << endl;

	cout << "Address of our array in memory: " << &arr << endl;
	cout << "Address of our array in memory: " << &arr[1] << endl;
	
	cout << " " << endl;

	int* ptr_arr = arr;

	cout << "Address of arr[0] " << (ptr_arr)<< " holds the value: "<< *(ptr_arr) << endl;
	cout << "Address of arr[1] " << (ptr_arr + 1) << " holds the value: "<< *(ptr_arr + 1) << endl;
	cout << "Address of arr[2] " << (ptr_arr + 2) << " holds the value: "<< *(ptr_arr + 2) << endl;
	cout << "Address of arr[3] " << (ptr_arr + 3) << " holds the value: " << *(ptr_arr + 3) << endl;
	cout << "Address of arr[4] " << (ptr_arr + 4) << " holds the value: " << *(ptr_arr + 4) << endl;

	//no boundary checking
	cout << "Address of arr[5] " << (ptr_arr + 5) << " holds the value: " << *(ptr_arr + 5) << endl;

	cout << "\n" << endl;
	

	//-------stack---------------

	string words[5];

	words[0] = "coms";
	words[1] = "wits";
	words[2] = "msl";
	words[3] = "laptop";
	words[4] = "space";
	string* wordsPtr = words;
	
	cout << wordsPtr << endl;

	//---------heap-----------------

	string *words_heap =  new string[5];

	words_heap[0] = "coms";
	words_heap[1] = "wits";
	words_heap[2] = "msl";
	words_heap[3] = "laptop";
	words_heap[4] = "space";
	string* wordsPtrHeap = words_heap;

	cout << wordsPtrHeap << endl;

	delete[] wordsPtrHeap;




	//-------------------------------------------------------------------------------------------------------------------------------------------------

	//int* null_ptr = 0;
	int* null_ptr = nullptr; 
	cout << "The null pointer:  " << null_ptr << endl;

	//DO NOT DEREFERENCE THE NULL POINTER, otherwise you program will simply crash!
	//cout << *null_ptr << endl;

	int *ptr_new = new int(42);   // ask for new memory from the OS

	cout << "The pointer storing the address " << ptr_new << endl;
	cout << "The value stored there is " << *ptr_new << endl;

	*ptr_new = 256;

	cout << "The pointer is still storing the address " << ptr_new << endl;
	cout << "The value stored there is now " << *ptr_new << endl;

	delete ptr_new;            // give the memory back to the OS
	ptr_new = 0;               // set the pointer to 0

	//------------------------------------------------------------------------------------------------------------------------------------------------

	int* arrD = new int[5];  //<-- Pointer to a memory in the heap 
	arrD[0] = 5;
	arrD[1] = 6;
	arrD[2] = 7;
	arrD[3] = 8;
	arrD[4] = 9;

	//----------------------------------------------------------------Resizing------------------------------------------

	//Initialize array size
	int arr_size = 5;
	int* our_array = new int[5];

	our_array[0] = 1;
	our_array[1] = 2;
	our_array[2] = 3;
	our_array[3] = 4;
	our_array[4] = 5;

	for (int i = 0; i < 5; i++) {
	
		cout << "our_array[" << i << "]: " << our_array[i] << endl;

	}


	int* tmp = nullptr;

	//make tmp have twice the size of the original pointer
	tmp = new int[2 * arr_size];

	//fill in the space
	for (int i = 0; i < arr_size; ++i) {
		tmp[i] = our_array[i];
	}

	//delete  that array pointed by our_arr
	delete[] our_array;
	//assign nullptr to the the old pointer
	our_array = nullptr;

	//make the old pointer point to the tmp 
	our_array = tmp;

	//make tmp point to null pointer
	tmp = 0;

	arr_size *= 2;

	//--------------------vectors

	vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	//--------------------------------------------arrays




	return 0;
}