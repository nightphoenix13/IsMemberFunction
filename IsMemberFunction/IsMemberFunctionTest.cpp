// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1136, #8
// Program uses a recursive isMember function to determine if a value is located in an array

#include <fstream> // for using files
#include <iostream> // for cout and cin
#include <iomanip> // for formatting
#include <string> // for strings
#include <cstdlib> // for rand and srand
#include <vector> // for vectors
#include <cctype> // for character functions
#include <cstring> // for C-strings
#include <ctime> // for using time/date functions
#include <algorithm> // for STL algorithms
#include "conio.h" 
using namespace std;

// global constant
static const int SIZE = 20,
				 EXIT = 0;

// method prototypes
void fillArray(int[]);
void fillArray(double[]);
void fillArray(string[]);
int menu();
int submenu();

// template prototypes
template <class T>
void manipulateArray(T[]);
template <class T>
void displayArray(T[]);
template <class T>
T getValue(T[]);
template <class T>
bool isMember(T[], T, int, bool);

int main() // main method start
{
	// local variable
	int choice;

	// arrays
	int intArray[SIZE];
	double doubleArray[SIZE];
	string stringArray[SIZE];

	fillArray(intArray);
	fillArray(doubleArray);
	fillArray(stringArray);

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1: manipulateArray(intArray);
			break;
		case 2: manipulateArray(doubleArray);
			break;
		case 3: manipulateArray(stringArray);
			break;
		} // end switch
	} while (choice != EXIT);

	cout << "Have a good day.";
	_getch();
	return 0;
} // main method end

// overloaded fillArray method to fill array of int values
void fillArray(int array[]) // fillArray method start
{
	for (int x = 0; x < SIZE; x++)
	{
		array[x] = rand() % 50;
	} // end for
} //fillArray method end

// overloaded fillArray method to fill array of double values
void fillArray(double array[]) // fillArray method start
{
	for (int x = 0; x < SIZE; x++)
	{
		array[x] = (rand() % 5000) / 100.00;
	} // end for
} // fillArray method end

// overloaded fillArray method to fill array of string values
void fillArray(string array[]) // fillArray method start
{
	array[0] = "this";
	array[1] = "is";
	array[2] = "a";
	array[3] = "sorted";
	array[4] = "array";
	array[5] = "of";
	array[6] = "string";
	array[7] = "literals";
	array[8] = "try";
	array[9] = "to";
	array[10] = "enter";
	array[11] = "a";
	array[12] = "word";
	array[13] = "to";
	array[14] = "locate";
	array[15] = "in";
	array[16] = "this";
	array[17] = "collection";
	array[18] = "of";
	array[19] = "words";	
} // fillArray method end

// menu method displays the menu options and returns user selection
int menu() // menu method start
{
	// local variable
	int choice;

	// displaying menu choices and getting input
	cout << "Please choose what type of array to work with:\n";
	cout << "1. Integer array\n";
	cout << "2. Double array\n";
	cout << "3. String array\n";
	cout << "0. Exit the program\n";
	cout << "Enter selection: ";
	cin >> choice;

	// input validation
	while (choice < EXIT || choice > 3)
	{
		cout << "You did not enter a valid selection. Please try again.\n";
		cout << "Enter selection (0 - 3): ";
		cin >> choice;
	} // end while

	return choice;
} // menu method end

// manipulateArray template method displays options for working with an array
template <class T>
void manipulateArray(T array[]) // manipulateArray method start
{
	// local variable
	int choice;
	bool wasFound;
	T value;

	do
	{
		choice = submenu();
		switch (choice)
		{
		case 1: displayArray(array);
			break;
		case 2: value = getValue(array);
			wasFound = false;
			wasFound = isMember(array, value, 0, wasFound);
			if (wasFound)
			{
				cout << "\nThe value, " << value << ", was found in the array.\n\n";
			} // end if
			else
			{
				cout << "\nThe value, " << value << ", was NOT found in the array.\n\n";
			} // end else
			break;
		} // end switch
	} while (choice != 0);
} // manipulateArray method end

// submenu method displays submenu and returns user selection
int submenu() // submenu method start
{
	// local variable
	int choice;

	// displaying menu and getting input
	cout << "Please select an operation to perform:\n";
	cout << "1. Display contents of the array\n";
	cout << "2. Search array for specific value\n";
	cout << "0. Return to previous menu\n";
	cout << "Enter selection: ";
	cin >> choice;

	// input validation
	while (choice < EXIT || choice > 2)
	{
		cout << "You did not enter a valid selection. Please try again.\n";
		cout << "Enter selection (0 - 2): ";
		cin >> choice;
	} // end while

	return choice;
} // submenu method end

// displayArray template method displays the contents of an array
template <class T>
void displayArray(T array[]) // displayArray method start
{
	for (int x = 0; x < SIZE; x++)
	{
		cout << array[x] << "\t\t";
		if ((x + 1) % 5 == 0)
		{
			cout << "\n";
		} // end if
	} // end for
} // displayArray method end

// getValue template method gets specific value from user
template <class T>
T getValue(T array[]) // getValue method start
{
	// local variable
	T value;

	// prompting user for input
	cout << "\nPlease enter the value to search the array for: ";
	cin >> value;

	return value;
} // getValue method end

// recursive isMember template method searches array for specific value
template <class T>
bool isMember(T array[], T value, int index, bool found) // isMember method start
{
	if (index < SIZE)
	{
		if (array[index] == value || found == true)
		{
			return true;
		} // end if
		else
		{
			found = isMember(array, value, index + 1, found);
			return found;
		} // end else
	} // end if
	else
	{
		return found;
	} // end else
} // isMember method end