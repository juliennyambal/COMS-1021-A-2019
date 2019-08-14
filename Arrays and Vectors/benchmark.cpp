#include <iostream>
#include <ctime>
using namespace std;

int main() {

	

	clock_t start, end;
	double secondsPassed;
	int interval = 100;
	const int size = 100000;
	const int time_int = int(size / interval);
	int* arr = new int[size];
	double time_sep[time_int];
	start = clock();
	cout << "start ----------------------------> " << start << " second(s)." << endl;
	/*
	for (int i = 0; i <= size; i = i + interval){
		start = clock();
			for (int j = 0; j < i; j++) {
				arr[j] = j;
				if (j % 5 == 0) {
					clog << arr[j] << endl;
				}
				
			}
		
		end = (clock() - start) / (double)CLOCKS_PER_SEC;

		//cout << "Start " << end << " second(s)." << endl;
		//cout << "End " << end << " second(s)." << endl;
		cout << "It took " << end << " second(s)." << endl;
		//time_sep[i][0] = i;
	}

	// Calculating total time taken by the program. 

	//cout << "Time taken by program is : " << fixed
	//	<< time_taken << setprecision(5);
	//cout << " sec " << endl;


	
	tend = time(0);
	cout << "It took " << difftime(tend, tstart) << " second(s)." << endl;
	cout << "It took " << tstart << " second(s)." << endl;
	cout << "It took " << tend << " second(s)." << endl;
	

	for (int i = 0; i < time_int; i++) {
		cout << "time_int " << i << ": "<< time_sep[i] << endl;
	}
*/
	
	for (int j = 0; j < 100000; j++) {
		arr[j] = j;
		if (j % 5 == 0) {
			clog << arr[j] << endl;
		}
	}
	//cout << "It took " << difftime(clock(), start) << " second(s)." << endl;
	secondsPassed = (clock() - start);
	cout << "CLOCKS_PER_SEC " << CLOCKS_PER_SEC << endl;
	cout << "clock " << clock() << " second(s)." << endl;
	cout << "start " << start   << " second(s)." << endl;
	//cout << "time_int " << secondsPassed << endl;

}