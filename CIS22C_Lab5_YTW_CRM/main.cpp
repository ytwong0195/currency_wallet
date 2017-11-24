#pragma warning( disable : 4290 )  
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
	ifstream inFile;
	string word;
	string name, bday;
	const string inFileName = "list.txt";
	inFile.open(inFileName);
	
	BinarySearchTree<string>* namePtr = new BinarySearchTree<string>();
	BinarySearchTree<string>* bdayPtr = new BinarySearchTree<string>();

	//if (inFile.is_open())
	//{
	//	string word;
	//	while (!inFile.eof())
	//	{
	//		inFile >> name->add("word");
	//		inFile.ignore();
	//		inFile >> name

	//	}
	//}

	cout << "Enter name";
	cin >> name;
	namePtr->add(name);
	cout << "Enter birthday";
	cin >> bday;
	bdayPtr->add(bday);

	system("pause");

	
	
	//ofstream outfile;
	//const string FILENAME = "name.txt";
	//const string FILENAME2 = "birthday.txt";
	//outfile.open(FILENAME);
	//if (outfile)
	//{
	//	cout << "The file name " << FILENAME << " has been saved. " << endl;
	//}
	//else (outfile.fail()) 
	//{
	//	cout << "Sorry, the file cannot be saved!" << endl;
	//}

	//outfile.close();


}

int displayMenu()
{
	int choice = 0;

	cout << "Please choose the 'number' of the following options:" << endl;
	cout << "1. Add";
	cout << "2. Remove";
	cout << "3. Modify";
	cout << "4. Search";
	cout << "5. Exit Program";

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