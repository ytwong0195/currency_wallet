/*
Lab 1
This program emulates a wallet by adding, removing or emptying the entire contents of the
wallet with different currencies.
Ying Tung Wong, Christian Magpantay

Assumptions:
Default values will start off as zero, then we can only add to the wallet first

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

using namespace std;

/*
Main
Psuedocode:
	Program will ask user which currency they would like to add first
		ask user how much will be added
		input validation for program
			if positive,
				output, input validation to user
				output, amount has added
				lead user to main prompts

			if negative,
				output, unable to use negative
				ask for proper input

	Ask user main prompts; either to add, remove or empty the entire contents of the wallet, or exit program
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

			if empty,
				print current state of wallet
				output to user of emptying contents
				back to main

			if exit,
				exit program

*/

int main()
{
	int currnc, choice;
	double amount;

	//allow the user to add a maximum of 5 different currency types to the wallet in the form of the base currency array
	cout << "Which currency would you like to add to your wallet? Input number: " << endl;
	cout << "(Dollars = 1, Euros = 2, Yen = 3, Rupees = 4, Yuans = 5)";
	cin >> currnc;

	//insert into object

	cout << "How much would you like to add of this currency?";
	cin >> amount;

	cout << "Is " << "'" << amount << "'" << "  the correct amount?";

	//able to add or remove as many currency values for any of the five currency types
	//able to empty the wallet and print relevant information about the operation
	cout << "Would you like to add more, remove or empty from your wallet? Enter 0 to exit. " << endl;
	cout << "(Add = 1, Remove = 2, Empty = 3)";
	cin >> choice;


	//demonstrate the overloaded subscript operator for the Wallet class

	cout << "";

	//output the total value by name of the currencies in the wallet
	//wallet output array


}
