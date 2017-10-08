#include "currency.h"

Currency::Currency() //initialize to 0 
{
	c_wholepart = 0;
	c_fractionPart = 0;
}

Currency::Currency(double initialValue) 
{
	c_wholepart = floor(initialValue);
	c_fractionPart = (initialValue - c_wholepart); //assuming to store fraction as 0.xx
}

//void Currency::setValue(double whole, double fraction)
//{
//	c_wholepart = whole;
//	c_fractionPart = fraction;
//}

double Currency::getAmount() const
{
	return c_wholepart + c_fractionPart;
}

double Currency::operator+(double increment)
{

}

double Currency::operator-(double decrement)
{
}

//
//void Currency::emptyCurrency()
//{
//	c_wholepart = 0;
//	c_fractionPart = 0;
//}
//
//void Currency::addMoney(double increment)
//{
//	double addToWhole = 0, addToFraction = 0;
//	addToWhole = floor(increment);
//	addToFraction = (increment - addToWhole);
//	c_wholepart += addToWhole;
//	c_fractionPart += addToFraction;
//	while (c_fractionPart >= 1)
//	{
//		c_fractionPart -= 1;
//		c_wholepart += 1;
//	}
//	
//}
//
//void Currency::subtractMoney(double decrement)
//{
//	double addToWhole = 0, addToFraction = 0;
//	addToWhole = floor(decrement);
//	addToFraction = (decrement - addToWhole) * 100;
//	c_wholepart += addToWhole;
//	c_fractionPart += addToFraction;
//}
