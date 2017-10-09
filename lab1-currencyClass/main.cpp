/*
Lab 1
This program simulates a wallet during a foreign trip
by adding or subracting different currencies by the user or
displaying or emptying the contents of the wallet.
By Ying Tung Wong, Christian Magpantay
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
#include "c_Rupee.h"
#include "wallet.h"



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
int displayMainMenu();
using namespace std;

int main()
{
	int currnc = 0;
	int choice = 0;
	Wallet wlet;

	Currency * dollar = new c_Dollar();
	Currency * euro = new c_Euro();
	Currency * rupee = new c_Rupee();
	Currency * yen = new c_Yen();
	Currency * yuan = new c_Yuan();

	enum C_TYPE { USD = 1, EURO, YEN, RUPEES, YUAN };
	enum MAIN_MENU_CHOICE { ADD = 1, SUBTRACT, DISPLAY, EMPTY, EXIT };

	cout << "This wallet program will contain all of your currencies during your trip!" << endl;

	choice = displayMainMenu();
	while (choice != EXIT)
	{

		switch (choice)
		{
		case ADD:
		{
			cout << "Please select the type of currency you would like to add." << endl;
			cout << "1. Dollars" << endl;
			cout << "2. Euros" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupees" << endl;
			cout << "5. Yuan" << endl;
			cin >> currnc;

			if (currnc == USD)
			{
				//cout << "if currnc==usd" << endl;
				int exist = wlet.currencyCheck(dollar, wlet);
				if (exist == -1)
				{
					//cout << "if exist = -1" << endl;
					wlet.addCurrency(dollar, wlet);
					wlet.addValue(dollar, wlet);
					//cout << "Currency added!" << endl;
					//cout << wlet[0] << endl;
				}
				else if (exist != -1)
				{
					//cout << "if exist != -1" << endl;
					wlet.addValue(dollar, wlet);
					//cout << "Value added!" << endl;
					//cout << "Returning to main menu!" << endl << endl;

				}
			}
			break;
			// function repeats for other currencies
		}//end ADD

		case SUBTRACT:
		{
			cout << "Please select the type of currency you would like to subtract." << endl;
			cout << "1. Dollars" << endl;
			cout << "2. Euros" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupees" << endl;
			cout << "5. Yuan" << endl;
			cin >> currnc;

			if (currnc == USD)
			{
				int exist = wlet.currencyCheck(dollar, wlet);
				if (exist == -1)
				{
					cout << "The currency has information available, you may add this currency at the main menu. " << endl;
					cout << "The program will return to main menu now." ;
				}
				else 
				{

					wlet.subtract(dollar, wlet);
					cout << "Returning to main menu!" << endl << endl;
				}
			}
			break;
			//function repeats for other currencies
		}//end SUBTRACT
		case DISPLAY:
		{
			//display wallet array object
			for (int i = 0; i < wlet.getNumCurrencies(); i++)
			{
				wlet.displayWallet(i,wlet);
			}
			cout << "All Wallet contents displayed!" << endl;
			cout << "Returning to main menu!" << endl << endl;
			
			break;
		}//end DISPLAY
		case EMPTY:
		{
			wlet.emptyWallet(wlet);
			cout << "Wallet is now empty!" << endl;
			cout << "Returning to main menu!" << endl << endl;
			
			break;
		}//end EMPTY
		}//end SWITCH
		choice = displayMainMenu();
	}//end WHILE
		
	if (choice == EXIT)
	{
		cout << "The program will now exit. Thank you for using!" << endl;
	}
		
	system("pause");

	return 0;
}

/*
Display Main Menu
Pseudocode:
Show user a series of options
do while
choice is in between 1-5
*/
int displayMainMenu()
{
	int choice = 0;		// Menu choice from user's input

	cout << endl << endl;
	cout << "Would you like to.." << endl;
	cout << "1. Add to a specific currency? " << endl;
	cout << "2. Subtract from a specific currency? " << endl;
	cout << "3. Show the contents of your wallet? " << endl;
	cout << "4. Empty the contents of your wallet? " << endl;
	cout << "5. Exit the program." << endl << endl;
	cout << "Please enter the number of your choice." << endl;
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
