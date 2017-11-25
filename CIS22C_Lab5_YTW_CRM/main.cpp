#pragma warning( disable : 4290 )  
#define _CRT_SECURE_NO_WARNINGS

/*
Lab 5:
This program maintains a database containing birthdays and names.
By: Ying Tung Wong, Christian (Taro) Magpantay
*/

#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"
using namespace std;

int displayMenu();

int main()
{
	ifstream inFile("list.txt");
	string word;
	string fname, lname, bday, fullname, bdayNew;
	bool success;
	//const string inFileName = "list.txt";
	int uChoice = 0;
	int opt = 0;
	int mod = 0;

	BinarySearchTree<string>* namePtr = new BinarySearchTree<string>();
	BinarySearchTree<string>* bdayPtr = new BinarySearchTree<string>();
	enum MENU { ADD = 1, REMOVE, MODIFY, SEARCH, EXIT };
	int counter = 0;
	while (inFile.is_open() && !inFile.eof())
	{
		//add to name or birthday alternatively using counter to keep track of odd even line.
		if (counter % 2 == 0) 
		{
			getline(inFile, word);
			namePtr->add(word);
		}
		else
		{
			getline(inFile, word);
			bdayPtr->add(word);
		}
		counter++;
	}

	//bdayPtr->add("1999-12-03");
	//bdayPtr->add("1942-01-08");
	//bdayPtr->add("1942-01-17");
	//bdayPtr->add("1643-01-04");
	//bdayPtr->add("1706-01-17");
	//namePtr->add("Stephen Hawking");
	//namePtr->add("Muhammad Ali");
	//namePtr->add("Issac Newton");
	//namePtr->add("Orlando Bloom");
	//namePtr->add("Lady Gaga");

	cout << "The file has been read into a binary search tree." << endl << endl;

	while (uChoice != EXIT)
	{
		uChoice = displayMenu();
		switch (uChoice)
		{
		case ADD:
			cout << endl;
			cout << "Would you like to add a 'name' or 'birthday'?" << endl;
			cout << "Enter 1 for 'name' or 2 for 'birthday': ";
			cin >> opt;
			if (opt == 1)
			{
				cout << endl;
				cout << "Follow the instructions to enter a 'name': " << endl;
				cout << "First name: ";
				cin >> fname;
				cout << "Last name: ";
				cin >> lname;
				fullname = fname + " " + lname;
				namePtr->add(fullname);
				cout << "'" << fullname << "'" << "has been added." << endl;
				cout << "Returning to Main Menu." << endl << endl;
			}
			else if (opt == 2)
			{
				cout << endl;
				cout << "Follow the instructions to enter a 'birthday': " << endl;
				cout << "The birthday must be entered in this format, YYYY-MM-DD " << endl;
				cout << "Please enter the birthday: ";
				cin >> bday;
				bdayPtr->add(bday);
				cout << "'" << bday << "'" << "has been added." << endl;
				cout << "Returning to Main Menu." << endl << endl;
			}
			else
			{
				cout << "Invalid entry." << endl;
				cout << "Returning to Main Menu" << endl << endl;
			}
			break;
		case REMOVE:
			cout << endl;
			cout << "Would you like to remove a 'name' or 'birthday'?" << endl;
			cout << "Enter 1 for 'name' or 2 for 'birthday: ";
			cin >> opt;
			if (opt == 1)
			{
				cout << endl;
				cout << "Follow the instructions to remove a 'name': " << endl;
				cout << "Enter 1 for removal by looking up 'first name' or 2 for 'last name': " << endl;
				cin >> mod;
				if (mod == 1)
				{
					cout << "What is the person's 'first name' ?" << endl;
					cin >> fname;

				}
			}
			else if (opt == 2)
			{
				cout << endl;
				cout << "Follow the instructions to remove a 'birthday': " << endl;
				cout << "The birthday must be entered in this format, YYYY-MM-DD " << endl;
				cout << "Please enter the birthday: ";
				cin >> bday;
				success = bdayPtr->remove(bday);
				if (success = true)
				{
					cout << endl;
					cout << "'" << bday << "'" << "removed. " << endl;
					cout << "Returning to Main Menu." << endl << endl;
				}
				else
				{
					cout << endl;
					cout << "'" << bday << "'" << "does not exist and cannot be removed." << endl;
					cout << "Returning to Main Menu." << endl << endl;
				}

			}
			else
			{
				cout << endl;
				cout << "Invalid entry." << endl;
				cout << "Returning to Main Menu" << endl << endl;
			}
			break;
		case MODIFY:
			cout << endl;
			cout << "Would you like to modify a 'name' or 'birthday'?" << endl;
			cout << "Enter 1 for 'name' or 2 for 'birthday: ";
			cin >> opt;
			if (opt == 1)
			{
				cout << endl;
				cout << "Follow the instructions to modify a 'name': " << endl;
				cout << "Enter 1 for modifying by looking up 'first name' or 2 for 'last name': " << endl;
				cin >> mod;
				if (mod == 1)
				{
					cout << "What is the person's 'first name' ?" << endl;
					cin >> fname;
				}
				else if (mod = 2)
				{

				}
			}
			else if (opt == 2)
			{
				cout << endl;
				cout << "Follow the instructions to modify a 'birthday': " << endl;
				cout << "The birthday must be entered in this format, YYYY-MM-DD " << endl;
				cout << "Please enter the birthday: ";
				cin >> bday;
				cout << "Please enter the new birthday: ";
				cin >> bdayNew;
				success = bdayPtr->replace(bday, bdayNew);
				if (success = true)
				{
					cout << endl;
					cout << "'" << bday << "'" << "has been changed to " << "'" << bdayNew << "'" << endl;
					cout << "Returning to Main Menu." << endl << endl;
				}
				else
				{
					cout << endl;
					cout << "'" << bday << "'" << "does not exist and cannot be modified." << endl;
					cout << "Returning to Main Menu." << endl << endl;
				}

			}
			else
			{
				cout << endl;
				cout << "Invalid entry." << endl;
				cout << "Returning to Main Menu" << endl << endl;
			}
			break;
		case SEARCH:
			cout << endl;
			cout << "Would you like to search for a 'name' or 'birthday'?" << endl;
			cout << "Enter 1 for 'name' or 2 for 'birthday: ";
			cin >> opt;
			if (opt == 1)
			{
				cout << endl;
				cout << "Follow the instructions to remove a 'name': " << endl;
				cout << "Enter 1 for looking up 'first name' or 2 for 'last name': " << endl;
				cin >> mod;
				if (mod == 1)
				{
					cout << "What is the person's 'first name' ?" << endl;
					cin >> fname;

				}
			}
			else if (opt == 2)
			{
				cout << endl;
				cout << "Follow the instructions to search for a 'birthday': " << endl;
				cout << "The birthday must be entered in this format, YYYY-MM-DD " << endl;
				cout << "Please enter the birthday: ";
				cin >> bday;
				success = bdayPtr->search(bdayPtr, bday);

			}
			else
			{
				cout << endl;
				cout << "Invalid entry." << endl;
				cout << "Returning to Main Menu" << endl << endl;
			}
			break;
		case EXIT:
			//save file
			cout << endl;
			cout << "BST has been saved and the program will now close." << endl << endl;
			system("pause");
			break;
		}
	}


	return 0;
}



int displayMenu()
{
	int choice = 0;

	cout << "Please choose the 'number' of the following options for the BST:" << endl;
	cout << "1. Add" << endl;
	cout << "2. Remove" << endl;
	cout << "3. Modify" << endl;
	cout << "4. Search" << endl;
	cout << "5. Exit Program" << endl;
	cout << "Option: ";
	cin >> choice;

	do
	{
		if (cin.fail() || (choice < 1 || choice > 5))
		{
			cout << "Invalid entry. Please reenter: ";
			cin.clear();
			cin.ignore();
			cin >> choice;
		}

	} while (choice < 1 || choice > 5);

	return choice;
}
