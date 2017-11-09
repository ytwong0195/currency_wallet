/*
Lab 4
This program demonstrates three different sorts for a template array of data
By: Ying Tung Wong and Christian (Taro) Magpantay

*/

#include <iostream>
#include <fstream>
#include "ArrayBag.h"
using namespace std;




int main()
{
	int choice = 0;
	int size = 0;
	int index = 0;
	ofstream outfile;
	const string FILENAME = "ArrayBag.txt";
	outfile.open(FILENAME);

	cout << "This program will sort your data." << endl;
	cout << "What 'type' of data would you like to enter?" << endl;
	cout << "1. 'int'" << endl;
	cout << "2. 'double'" << endl;
	cout << "3. 'char'" << endl;
	cout << "4. 'string'" << endl;
	cout << "Please enter the number of your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "How many 'int' items would you like to enter? (Only up to 32)";
		cin >> size;
		int arr1[] = { 0 };
		for (int i = 0; i < size; i++)
		{
			cout << "Entry " << i + 1 << ":";

		}


		break;
	case 2:
		cout << "How many 'double' items would you like to enter? (Only up to 32)";
		cin >> size;
		double arr2[] = { 0.0 };
		for (int i = 0; i < size; i++)
		{
			cout << "Entry " << i + 1 << ":";


		}

		break;
	case 3:
		cout << "How many 'char' items would you like to enter? (Only up to 32)";
		cin >> size;
		char arr3[] = { ' ' };
		for (int i = 0; i < size; i++)
		{
			cout << "Entry " << i + 1 << ":";

		}


		break;
	case 4:
		cout << "How many 'string' items would you like to enter? (Only up to 32)";
		cin >> size;
		break;
	default:
		cout << "error";
		break;

	}

	if (outfile)
	{
		outfile << "Sorted Data" << endl;
		for (int i = 0; i < size; i++) 
		{
			outfile << endl;
		}
		outfile << "The file name " << FILENAME << " has been saved. " << endl;

	}
	else if (outfile.fail())
	{
		cout << "Sorry, the file cannot be saved currently!" << endl;
	}
	return 0;
} // end main