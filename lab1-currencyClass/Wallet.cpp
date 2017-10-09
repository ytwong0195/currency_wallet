#include "Wallet.h"

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
			c_array[numberOfCurrencies] = *input
		}
	}
}

void Wallet::removeCurrency(Currency*input) 
{

}

void Wallet::emptyWallet()
{

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
