// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cstdlib"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class SearchableArray {
	int length;
	int highestnum;
	int* myarr;
public:
	SearchableArray(int, int);
	int get_length();
	void print_data();
	void generate_random();
	int binary_search(int);
	void sort_me();
};

SearchableArray::SearchableArray(int inlength, int inhighestnum) {
	myarr = new int[inlength];
	length = inlength;
	highestnum = inhighestnum;
}

int SearchableArray::get_length() {
	return length;
}

void SearchableArray::print_data() {
	
	string str;

	str += "ARRAY: (";

	for (int i = 0; i < length; i++) {
		str += to_string(myarr[i]);
		str += ", ";
	}

	str += ")";

	cout << str << endl;

}

void SearchableArray::generate_random() {

	for (int i = 0; i < length; i++) {
		myarr[i] = rand() % highestnum;
	}
}

int SearchableArray::binary_search(int seek) {

	int i = length / 2;

	cout << "SEARCHING ALGORITHM OPERATIONAL... " << endl;

	while (i != 0 && i < length) {
		cout << "I:'" << i << "'; [I]:'" << myarr[i] << "', ";
		if (myarr[i] == seek) { cout << endl;  return i; } 
		if (myarr[i] < seek) { i += (length - i) / 2; } 
		else { i = i / 2; }
	}

	cout << endl;

	return -1;

}

void SearchableArray::sort_me() {
	sort(myarr, myarr + length);
}

int main()
{
	int arrsize;
	int arrmax;
	// Get sizes from user
	cout << "Array size?: ";
	cin >> arrsize;
	cout << "Array max number? (Min is 0)";
	cin >> arrmax;
	// Create our searchable array
	SearchableArray arr1 = SearchableArray(arrsize, arrmax);
	arr1.generate_random();
	// Sort the array and show its length
	arr1.print_data();
	cout << "LENGTH: " << arr1.get_length() << endl;
	arr1.sort_me();
	arr1.print_data();
	// Ask the user what to search for and search for it
	int toseek;
	cout << "What to seek for?: ";
	cin >> toseek;
	int seeker = arr1.binary_search(toseek);
	cout << "BIN SEARCH FOR: '" << toseek << "' RETURNED INDEX: " << seeker << endl;

	// Pause execution to stop window from closing
	cin.get();
	cin.get();
    return 0;
}


