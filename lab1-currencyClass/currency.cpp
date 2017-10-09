#include "currency.h"

Currency::Currency() 
{

};

Currency::Currency(std::string name, std::string fractionName)
{
	c_name = name;
	c_fractionName = fractionName;
	c_wholepart = 0;
	c_fractionPart = 0;
	
}

Currency::~Currency()
{

};

std::string Currency::getName() const
{
	return c_name;
}

std::string Currency::getFracName() const
{
	return c_fractionName;
}

void Currency::setNext(Currency *nextC) 
{
	nextLoc = nextC;
}

Currency* Currency::getNext() const
{
	return nextLoc;
}

Currency Currency::operator+(const Currency &right)
{
	Currency temp;
	temp.c_wholepart = c_wholepart +  right.c_wholepart;
	temp.c_fractionPart = c_fractionPart + right.c_fractionPart;
	return temp;
}

Currency Currency::operator-(const Currency &right)
{
	Currency temp;
	temp.c_wholepart = c_wholepart - right.c_wholepart;
	temp.c_fractionPart = c_fractionPart - right.c_fractionPart;
	return temp;
}



std::ostream & operator<<(std::ostream &ostrm, const Currency &obj)
{
	ostrm << obj.c_wholepart << " " << obj.c_name << " " << obj.c_fractionPart*100 << " " << obj.c_fractionName;
	//assuming fraction part is stored as 0.xx value
	return ostrm;

}

std::istream & operator>>(std::istream &istrm, Currency &obj)
{
	std::cout << "Please enter an amount more than 0: ";
	double total = 0.0;
	istrm >> obj.c_wholepart;
	total = obj.c_wholepart;
	obj.c_wholepart = floor(total);
	obj.c_fractionPart = total - obj.c_wholepart;
	return istrm;

}


//Currency::Currency(double initialValue) 
//{
//	c_wholepart = floor(initialValue);
//	c_fractionPart = (initialValue - c_wholepart); //assuming to store fraction as 0.xx
//}

//void Currency::setValue(double whole, double fraction)
//{
//	c_wholepart = whole;
//	c_fractionPart = fraction;
//}

//double Currency::getTotal() const
//{
//	return c_wholepart + c_fractionPart;
//}



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