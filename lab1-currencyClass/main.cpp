/*
Lab 2
This program allows user to choose between linked-based / stack-based operation 
User can add/remove currency, display/empty wallet.
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
#include "linkedList.h"
#include "listIF.h"
#include "node.h"
#include "linkedStack.h"


/*

Program will first ask user to choose between linked-based or stack-based operation.
Program will show the user a series of options for the wallet program
Ask user main prompts; add, remove, display, empty the entire contents of the wallet, or exit program

for linked-based operation, user can add and remove a specific currency.
the program will check if the currency exists in the wallet before adding / removing.
(add/delete/find anywhere)

for stack-based operation, user can add any currency.
the program will not check if the currency has previously been added. 
To remove a currency, the program will only remove the most recent currency in the wallet.
(push,pop,peek)

both operations are able to display and empty wallet.

*/

int displayMainMenu();
void displayOptions();
void saveFile(Wallet&);
using namespace std;

int main()
{
	int currnc = 0;
	int choice = 0;
	//LinkedStack<bool> aStack; //trying to test isEmpty function
	//LinkedStack<string> aStack;

	//Wallet wlet;
	Currency * dollar = new c_Dollar();
	Currency * euro = new c_Euro();
	Currency * rupees = new c_Rupee();
	Currency * yen = new c_Yen();
	Currency * yuan = new c_Yuan();

	Node <Currency*> temp_node;
	
	enum C_TYPE { USD = 1, EURO, YEN, RUPEES, YUAN };
	enum MAIN_MENU_CHOICE { ADD = 1, REMOVE, DISPLAY, EMPTY, EXIT };
	enum OPERATION_TYPE{ LIST = 1, STACK };
	
	LinkedList <Currency*> *wallet_list = nullptr;
	wallet_list = new LinkedList<Currency*>();

	LinkedStack <Currency*> *wallet_stack = nullptr;
	wallet_stack = new LinkedStack<Currency*>();

	int operation; 

	cout << "Please choose: 1)List-Based implementation or 2)Stack-based implementation: " << endl;
	cin >> operation;
	while (operation != LIST && operation != STACK)
	{
		cout << "Please enter 1 or 2 :";
	}

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
			
			if (currnc == USD) 
			{
				temp_node = dollar;
			}
			if (currnc == EURO) 
			{
				temp_node = euro;
			}
			if (currnc == RUPEES) 
			{
				temp_node = rupees;
			}
			if (currnc == YEN) 
			{
				temp_node = yen;
			}
			if (currnc == YUAN) 
			{
				temp_node = yuan;
			} 
			
			if (operation == LIST) 
			{
				bool empty = wallet_list->isEmpty();
				if (empty == true)//add first currency(node), list is empty
				{
					int position = wallet_list->getLength() + 1;
					bool insertSuccess = wallet_list->insert(position, temp_node.getItem());
					if (insertSuccess == true)
					{
						cout << "Currency insert successfull." << endl;
					}
					else
					{
						cout << "Currency insert failed." << endl;
					}

				}
				else if (empty == false) //find if the currency exist, else insert
				{
					int exist = wallet_list->contains(temp_node.getItem());
					if (exist <= 0) //currency does not exist
					{
						int position = wallet_list->getLength() + 1;
						bool insertSuccess = wallet_list->insert(position, temp_node.getItem());
						if (insertSuccess == true)
						{
							cout << "Currency insert successfull." << endl;
						}
						else
						{
							cout << "Currency insert failed." << endl;
						}
					}
					else  // currency exists
					{
						cout << "Currency is already in the list." << endl;
					}
				}		
			}
			else if (operation == STACK)
			{
				int pushSuccess = wallet_stack->push(temp_node.getItem());
				if (pushSuccess = true)
				{
					cout << "Currency added to stack successfully" << endl;
				}
				else
				{
					cout << "Currency has not been added to stack. " << endl;
				}
			}
			
			break;
		}//end ADD

		case REMOVE:
		{
			if (operation == LIST) 
			{
				cout << "Please select the type of currency you would like to remove." << endl;
				displayOptions();
				cin >> currnc;
				if (currnc == USD) {
					temp_node = dollar;
				}
				if (currnc == EURO) {
					temp_node = euro;
				}
				if (currnc == RUPEES) {
					temp_node = rupees;
				}
				if (currnc == YEN) {
					temp_node = yen;
				}
				if (currnc == YUAN) {
					temp_node = yuan;
				}

				int exist = wallet_list->contains(temp_node.getItem());
				if (exist == 0 || exist > wallet_list->getLength())
				{
					cout << "The currency has no information available, you may add this currency at the main menu. " << endl;
				}
				else if (exist >= 1 && exist <= wallet_list->getLength())
				{
					int position = wallet_list->getPosition(temp_node.getItem());
					bool removeSuccess = wallet_list->remove(position);
					if (removeSuccess == true)
					{
						cout << "Currency remove successfull." << endl;
					}
					else
					{
						cout << "Currency remove failed." << endl;
					}

				}
				
			}
			else if (operation == STACK)
			{
				bool emptyStack = wallet_stack->isEmpty();
				if (emptyStack == true)
				{
					cout << "The Wallet stack has no currency left :(" << endl << endl ;
				}
				else if (emptyStack == false)
				{
					int popStack;
					cout << "The most recent curency added to the wallet is " << wallet_stack->peek()->getName() << endl;
					cout << "Do you want to delete this? Yes = 1, No = 2" << endl;
					cout << "Please enter your choice : ";
					cin >> popStack;
					while (popStack != 1 && popStack != 2)
					{
						cout << "Please enter 1 or 2: " << endl;
					}
					if (popStack == 1)
					{
						bool popSuccess = wallet_stack->pop();
						if (popSuccess == true)
						{
							cout << "The most recent currency has been removed successfully." << endl << endl;
						}
						else if (popSuccess == false)
						{
							cout << "Failed to remove the currency." << endl << endl;
						}
					}
					else if (popStack == 2)
					{
						cout << "The currency will not be removed." << endl << endl;
					}
				}
			}
			
		
			break;
		}//end REMOVE
		case DISPLAY:
		{
			if (operation == LIST) {
				//display wallet 
				if (wallet_list->getLength() == 0)
				{
					cout << "The wallet is empty :(" << endl << endl;
				}
				else
				{
					cout << "WALLET INFO" << endl;
					cout << "==============================" << endl << endl;
					for (int i = 1; i <= wallet_list->getLength(); i++)
					{
						cout << wallet_list->getEntry(i)->getName() << endl;

					}
					cout << "\nAll Wallet contents displayed!" << endl << endl;
					//saveFile();

				}
			}
			
			else if (operation == STACK)
			{
				if (wallet_stack->isEmpty())
				{
					cout << "The wallet is empty :(" << endl << endl;
				}
				else
				{
					LinkedStack <Currency*> *duplicateStack = nullptr;
					duplicateStack = new LinkedStack<Currency*>(*wallet_stack);

					cout << "WALLET INFO" << endl;
					cout << "==============================" << endl << endl;
					while (!duplicateStack->isEmpty())
					{
						cout << duplicateStack->peek()->getName() << endl;
						int popToDisplayNext = duplicateStack->pop();
					}
					delete duplicateStack;
					duplicateStack = nullptr;
				}
			}
			break;
		}//end DISPLAY
		case EMPTY:
		{
			if (operation == LIST)
			{
				wallet_list->clear();
				cout << "\nWallet is now empty!" << endl;
			}
			else if (operation == STACK)
			{
				wallet_stack->clear();
				cout << "The wallet is now empty." << endl;

			}
			
			break;
		}//end EMPTY
		}//end SWITCH
		cout << "\nReturning to main menu!" << endl << endl;
		choice = displayMainMenu();
	}//end WHILE
		
	if (choice == EXIT)
	{
		//cout << "Before you exit...." << endl;
		//saveFile();
		cout << "The program will now exit. Thank you for using!" << endl;
	}
		
	system("pause");
	delete wallet_stack;
	delete wallet_list;
	delete dollar;
	delete euro;
	delete rupees;
	delete yen;
	delete yuan;
	wallet_stack = nullptr;
	wallet_list = nullptr;
	dollar = nullptr;
	euro = nullptr;
	rupees = nullptr;
	yen = nullptr;
	yuan = nullptr;
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
	cout << setw(10) << "" << "1. Insert a specific currency " << endl;
	cout << setw(10) << "" << "2. Remove currency " << endl;
	cout << setw(10) << "" << "3. Show the contents of your wallet " << endl;
	cout << setw(10) << "" << "4. Empty the contents of your wallet " << endl;
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