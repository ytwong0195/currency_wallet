#include "Wallet.h"
#include "currency.h"
//#include "c_Dollar.h"
//#include "c_Euro.h"
//#include "c_Rupee.h"
//#include "c_Yen.h"
//#include "c_Yuan.h"

 const int MAX_CURR = 5;


Wallet::Wallet() 
{
	numberOfCurrencies = 0;

}

Wallet::~Wallet() 
{

}

int Wallet::getNumCurrencies() const 
{
	return numberOfCurrencies;
}


bool Wallet::isEmpty() 
{
	if (numberOfCurrencies == 0) 
	{
		return true;
	}
	return false;
}

Currency Wallet::operator[](int index)
{
	Currency error ;
	if (index >= 5)
	{
		std::cout << "error - index out of bound" << std::endl;
		return error;//or return first element? 
	}
	else
	{
		return c_array[index];

	}
}

void Wallet::addCurrency(Currency*input, Wallet &myWallet)
{
	if (myWallet.getNumCurrencies()>=MAX_CURR)
	{
		std::cout << "You have reached maximum number of currencies allowed. " << std::endl;
	}
	else
	{
		
		 if (currencyCheck(input, myWallet) == -1)
		{
			std::cout << "The currency '" << input->getName() << "' has no previous record. " << std::endl;
			myWallet.c_array[myWallet.getNumCurrencies()] = *input;
			myWallet.numberOfCurrencies += 1;
			std::cout << "The currency '" << input->getName() << "' will be added to this wallet. " << std::endl;
		}
	}
}

void Wallet::addValue(Currency *input, Wallet &myWallet)
{
	int c_type = currencyCheck(input, myWallet);
	int confirm;
	Currency temp(*input);
	do
	{
		std::cout << "How many " << myWallet.c_array[c_type].getName() << " would you like to add?" << std::endl;
		std::cout << "If you'd like to return to the previous menu, enter 0 amount and confirm :" <<std::endl;
		std::cin >> temp;
		std::cout << "Is " << temp << "  the correct amount?" << std::endl;
		std::cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
		std::cin >> confirm;
		if (confirm == 1)
		{

			myWallet.c_array[c_type] = myWallet.c_array[c_type] + temp;
			std::cout << temp << " has been added." << std::endl;
			std::cout << "The total is now " << myWallet[c_type];
		}

	} while (confirm == 2);
	

}

void Wallet::subtract(Currency*input, Wallet &myWallet) //TODO: not yet validate negative result
{
	int c_type = currencyCheck(input, myWallet);
	int confirm;
	Currency temp(*input);
	do
	{
		std::cout << "How many " << myWallet.c_array[c_type].getName() << " would you like to use?" << std::endl;
		std::cout << "If you'd like to return to the previous menu, enter 0 amount and confirm "<<std::endl;
		std::cin >> temp;
		std::cout << "Is " << temp << "  the correct amount?" << std::endl;
		std::cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
		std::cin >> confirm;
		if (confirm == 1)
		{
			myWallet.c_array[c_type] = myWallet.c_array[c_type] - temp;
			
			std::cout << "The total is now " << myWallet.c_array[c_type] << std::endl;
		}

	} while (confirm == 2);


}


void Wallet::emptyWallet(Wallet &myWallet)
{
	int confirm = 2;

	std::cout << "Are you sure if you want to empty your wallet? All data will be deleted." << std::endl;
	std::cout << "YES = 1, NO and RETURN to previous = 2" << std::endl;
	std::cout << "Please enter your option: ";
	std::cin >> confirm;

	if (confirm == 1) 
	{
		Currency nullCurrency;
		for (int i = 0; i < MAX_CURR; i++)
		{
			myWallet.c_array[i] = nullCurrency;
		
		}
		numberOfCurrencies = 0;
	}


}

int Wallet::currencyCheck(Currency* input, Wallet myWallet)
{
	int currencyPosition;
	for (int pos = 0; pos < 5; pos++)
	{
	
		if (input->getName() == myWallet.c_array[pos].getName()) 
		{
			currencyPosition = pos;
			return currencyPosition;
		}
	}

	return -1;
	
}

void Wallet::displayWallet(int index, Wallet &myWallet)
{
	std::cout << "Current Balance: " << myWallet.c_array[index].getTotal() << " " << myWallet.c_array[index].getName() << std::endl << std::endl;
}

