/*
Lab 1

This program simulates a wallet during a foreign trip
by adding or subracting different currencies by the user or
displaying or emptying the contents of the wallet.

By Ying Tung Wong, Christian Magpantay

Assumptions:


*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "currency.h"
#include "c_Dollar.h"
#include "c_Euro.h"
#include "c_Yen.h"
#include "c_Yuan.h"
#include "wallet.h"
#include "wallet.cpp"

using namespace std;

/*
Main
Psuedocode:
	Program will show the user a series of options for the wallet program

	Ask user main prompts; add, remove, display, empty the entire contents of the wallet, or exit program
		while loop ( while choice is not exit program )
			if add,
				ask which currency
				ask how much will be added
				input validation for program
					if positive,
						output, input validation to user
						output, amount has added
						back to main
					if negative,
						output, unable to use negative
						ask for input

			if remove,
				ask which currency
				input validation for program
					try/catch
					try if input is within bounds
					catch if input is greater than amount in wallet
					output if amount subtracted is greater than amount in wallet
				input validation to user
				output amount has removed
				back to main

			if show,
				display wallet array

			if empty,
				print current state of wallet
				output to user of emptying contents
				back to main

			if exit,
				exit program

*/

int main()
{
	int currnc, choice, confirm;
	int whAm, frAm;
	double totalAm;
	bool tryAgain = true;
	Wallet wlet;

	//Prompt the user which option he would like to choose
	//from their wallet.

	cout << "This wallet program will contain all of your currencies during your trip!" << endl;
	cout << "Would you like to.." << endl;
	cout << "1. Add to a specific currency? " << endl;
	cout << "2. Subtract from a specific currency? " << endl;
	cout << "3. Show the contents of your wallet? " << endl;
	cout << "4. Empty the contents of your wallet? " << endl;
	cout << "5. Exit the program." << endl << endl;
	cout << "Please enter the number of your choice." << endl;
	cin >> choice;

	while (choice != 5)
	{
		if (choice == 1)
		{
			cout << "Please select the type of currency you would like to add." << endl;
			cout << "1. Dollars" << endl;
			cout << "2. Euros" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupees" << endl;
			cout << "5. Yuan" << endl;
			cin >> currnc;

			if (currnc == 1)
			{
				cout << " How many 'dollars' would you like to add?" << endl;
				cin >> amount;
				while (tryAgain)
				{
					try
					{
						//wallet array object
						//wlet.set[0](amount);
						tryAgain = false;
					}
					catch (Currency::invalidAdd)
					{
						cout << "The value of the amount must be a positive value." << endl;
						cout << " How many 'dollars' would you like to add?" << endl;
						cin >> amount;
					}
				}

				cout << "Is " << "'" << amount << "'" << "  the correct amount?" << endl;
				cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
				cin >> confirm;

				if (confirm == 1)
				{
					//wlet.set[](amount);
					cout << "'" << amount << "'" << " has been added."
				}
				else if (confirm == 2)
				{
					cout << "How many 'dollars' would you like to add?" << endl;
					cin >> amount;
					//Add Input validation
				}



			}
			// I'll repeat the function above for the other currencies
		}
		else if (choice == 2)
		{
			cout << "Please select the type of currency you would like to subtract." << endl;
			cout << "1. Dollars" << endl;
			cout << "2. Euros" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupees" << endl;
			cout << "5. Yuan" << endl;
			cin >> currnc;

			if (currnc == 1)
			{
				cout << "How many 'dollars' would you like to subtract?" << endl;
				cin >> amount;
				while (tryAgain)
				{
					try
					{
						//wallet array object
						//wlet.set[0](amount);
						tryAgain = false;
					}
					catch (Currency::invalidAdd)
					{
						cout << "The value of the amount must be a positive value." << endl;
						cout << " How many 'dollars' would you like to add?" << endl;
						cin >> amount;
					}
				}


				cout << "Is " << "'" << amount << "'" << "  the correct amount?" << endl;
				cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
				cin >> confirm;

				if (confirm == 1)
				{
					//wlet.set[](amount);
				}
				else if (confirm == 2)
				{
					cout << "How many 'dollars' would you like to add?" << endl;
					cin >> amount;
					//Add Input validation
				}
			}

			// I'll repeat the function above for the other currencies as well
		}
		else if (choice == 3)
		{
			//display wallet array object
		}
		else if (choice == 4)
		{
			//reset wallet array object
		}
		else
			cout << "Invalid input.";
			cout << "Enter the number of your choice: ";
			cin >> choice;

	}

}
