#pragma once

#include "currency.h"



class Wallet : public Currency
{
	private:
		
		int numberOfCurrencies;
		Currency c_array[5];
		
	public:
		Wallet();
		~Wallet();
		int getNumCurrencies() const;
		bool isEmpty();
		void addCurrency(Currency*, Wallet);
		void addValue(Currency*, Wallet);
		void subtract(Currency*, Wallet);
		void emptyWallet(Wallet);

		int currencyCheck(Currency*, Wallet);

		void displayWallet(int, Wallet);
		double operator[] (int);
	



};



