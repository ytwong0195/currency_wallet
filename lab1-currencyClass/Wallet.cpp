#include "Wallet.h"
//#include "Currency.h"

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

void Wallet::addCurrency(Currency*input)
{
	if (numberOfCurrencies>=5)
	{
		std::cout << "You have reached maximum number of currencies allowed. " << std::endl;
	}
	else
	{
		if (currencyCheck(input) >= 0 ) 
		{
			c_array[currencyCheck(input)] = *input;
		}
		else if (currencyCheck(input) == -1)
		{
			c_array[numberOfCurrencies] = *input;
			numberOfCurrencies += 1;
		}
	}
}

void Wallet::addValue(Currency *input)
{
	int c_type = currencyCheck(input);
	int confirm;
	Currency temp;
	do
	{
		std::cout << "How many " << c_array[c_type].getName() << " would you like to add?" << std::endl;
		std::cout << "If you'd like to return to the previous menu, enter 0 amount and confirm :";
		std::cin >> temp;
		std::cout << "Is " << temp << "  the correct amount?" << std::endl;
		std::cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
		std::cin >> confirm;
		if (confirm == 1)
		{
			c_array[c_type] = c_array[c_type] + temp;
			std::cout << temp << " has been added." << std::endl;
			std::cout << "The total is now " << c_array[c_type];
		}

	} while (confirm == 2);
	

}

void Wallet::subtract(Currency*input) //TODO: not yet validate negative result
{
	int c_type = currencyCheck(input);
	int confirm;
	Currency temp;
	do
	{
		std::cout << "How many " << c_array[c_type].getName() << " would you like to use?" << std::endl;
		std::cout << "If you'd like to return to the previous menu, enter 0 amount and confirm :";
		std::cin >> temp;
		std::cout << "Is " << temp << "  the correct amount?" << std::endl;
		std::cout << "Enter 1 for 'Yes' or 2 for 'No'. ";
		std::cin >> confirm;
		if (confirm == 1)
		{
			c_array[c_type] = c_array[c_type] - temp;
			std::cout << temp << " has been deducted." << std::endl;
			std::cout << "The total is now " << c_array[c_type];
		}

	} while (confirm == 2);


}


void Wallet::emptyWallet()
{
	int confirm = 2;

	std::cout << "Are you sure if you want to empty your wallet? All data will be deleted." << std::endl;
	std::cout << "YES = 1, NO and RETURN to previous = 2" << std::endl;
	std::cout << "Please enter your option: ";

	if (confirm == 1) 
	{
		Currency nullCurrency;
		for (int i = 0; i < MAX; i++)
		{
			c_array[i] = nullCurrency;
		
		}
		numberOfCurrencies = 0;
	}


}

int Wallet::currencyCheck(Currency* input)
{
	int currencyPosition = -1;
	for (int pos = 0; pos < numberOfCurrencies; pos++)
	{
		if (input->getName() == c_array[pos].getName()) 
		{
			currencyPosition = pos;
		}
	}
	return currencyPosition;
}
