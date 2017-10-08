#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <iomanip>
#include <string>

//using namespace std; //not sure if we can use namespace std here

class Currency
{
private:
	std::string c_name;
	std::string c_fractionName;
	double c_wholepart;
	double c_fractionPart;

public:
	Currency();
	Currency(double);
	void setValue(double, double);
	double getAmount() const;
	//virtual void addMoney(double);
	//virtual void subtractMoney(double);
	//void emptyCurrency();

	double operator + (double);

	double operator - (double);


};
#endif //


