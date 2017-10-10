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
void displayOptions();
void saveFile(Wallet&);
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
	Currency * temp_curr = nullptr;

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
			displayOptions();
			cin >> currnc;
			
			if (currnc == USD) {
				temp_curr = dollar;
			}
			if (currnc == EURO) {
				temp_curr = euro;
			}
			if (currnc == RUPEES) {
				temp_curr = rupee;
			}
			if (currnc == YEN) {
				temp_curr = yen;
			}
			if (currnc == YUAN) {
				temp_curr = yuan;
			}
				int exist = wlet.currencyCheck(temp_curr, wlet);
				if (exist == -1)
				{
					wlet.addCurrency(temp_curr, wlet);
					wlet.addValue(temp_curr, wlet);
				}
				else if (exist != -1)
				{
					wlet.addValue(temp_curr, wlet);
				}
			
			break;
		}//end ADD

		case SUBTRACT:
		{
			cout << "Please select the type of currency you would like to subtract." << endl;
			displayOptions();
			cin >> currnc;
			if (currnc == USD) {
				temp_curr = dollar;
			}
			if (currnc == EURO) {
				temp_curr = euro;
			}
			if (currnc == RUPEES) {
				temp_curr = rupee;
			}
			if (currnc == YEN) {
				temp_curr = yen;
			}
			if (currnc == YUAN) {
				temp_curr = yuan;
			}
			
			int exist = wlet.currencyCheck(temp_curr, wlet);
			if (exist == -1)
			{
				cout << "The currency has no information available, you may add this currency at the main menu. " << endl;
			}
			else 
			{

				wlet.subtract(temp_curr, wlet);
				
			}
		
			break;
		}//end SUBTRACT
		case DISPLAY:
		{
			//display wallet array object
			if (wlet.getNumCurrencies() == 0) 
			{
				cout << "The wallet is empty :(" << endl;
			}
			else
			{
				cout << "WALLET INFO" << endl;
				cout << "==============================" << endl;
				for (int i = 0; i < wlet.getNumCurrencies(); i++)
				{
					wlet.displayWallet(i, wlet);
				}
				cout << "All Wallet contents displayed!" << endl;
				saveFile(wlet);
			}
			
			break;
		}//end DISPLAY
		case EMPTY:
		{
			wlet.emptyWallet(wlet);
			cout << "\nWallet is now empty!" << endl;
			
			break;
		}//end EMPTY
		}//end SWITCH
		cout << "Returning to main menu!" << endl << endl;
		choice = displayMainMenu();
	}//end WHILE
		
	if (choice == EXIT)
	{
		cout << "Before you exit...." << endl;
		saveFile(wlet);
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
	cout << setw(10) << "" << "Main Menu" << endl;
	cout << setw(10) << "" << "============================" << endl;
	cout << setw(10) << "" << "1. Add to a specific currency? " << endl;
	cout << setw(10) << "" << "2. Subtract from a specific currency? " << endl;
	cout << setw(10) << "" << "3. Show the contents of your wallet? " << endl;
	cout << setw(10) << "" << "4. Empty the contents of your wallet? " << endl;
	cout << setw(10) << "" << "5. Exit the program." << endl << endl;
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


void displayOptions()
{
	cout << setw(10) << "" << "1. Dollars" << endl;
	cout << setw(10) << "" << "2. Euros" << endl;
	cout << setw(10) << "" << "3. Yen" << endl;
	cout << setw(10) << "" << "4. Rupees" << endl;
	cout << setw(10) << "" << "5. Yuan" << endl;
}

void saveFile(Wallet &myWallet)
{
	int option;
	cout << "Would you like to save the current information to a new file? " << endl;
	cout << "Yes = 1, No = 2" << endl;
	cout << "Please enter your option: ";
	cin >> option;

	if (option == 1)
	{
		ofstream outfile;
		const string FILENAME = "My_Wallet.txt";
		outfile.open(FILENAME);
		if (outfile) {
			outfile << "Current Balance: " << endl;
			for (int i = 0; i < myWallet.getNumCurrencies(); i++) {
				outfile << myWallet[i] << endl;
			}
			cout << "The file name " << FILENAME << " has been saved. " << endl;
			
		}
		else if (outfile.fail()) {
			cout << "Sorry, the file cannot be saved currently!" << endl;
		}
		outfile.close();
	}
	else if (option == 2)
	{
		cout << "No file saved." << endl;
	}
	else {

		cout << "\nInvalid input!" << endl;
		return;
	}

	return;
}