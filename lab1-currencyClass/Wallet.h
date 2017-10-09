#ifndef WALLET_H
#include"currency.h"
//#include "c_Dollar.h"
//#include "c_Euro.h"
//#include "c_Rupee.h"
//#include "c_Yen.h"
//#include "c_Yuan.h"

const int MAX = 5;


class Wallet
{
	private:
		int numberOfCurrencies;
		Currency c_array[MAX];
		
	public:
		Wallet();
		~Wallet();
		int getNumCurrencies() const;
		bool isEmpty();
		void addCurrency(Currency*);
		void removeCurrency(Currency*);
		void emptyWallet();

		int currencyCheck(Currency*);



};




#endif // !WALLET_H

