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

double Currency::getTotal() const
{
	double total;
	total = c_wholepart + c_fractionPart;
	return total;
}

Currency Currency::operator+(const Currency &right)
{
	Currency temp;
	temp.c_wholepart = this->c_wholepart +  right.c_wholepart;
	temp.c_fractionPart = this->c_fractionPart + right.c_fractionPart;
	std::cout << "overload operator +" << std::endl;
	while (temp.c_fractionPart >= 1) 
	{
		temp.c_wholepart += 1;
		temp.c_fractionPart -= 1;

	}
	return temp;
}

Currency Currency::operator-(const Currency &right)
{
	Currency temp;
	temp.c_fractionPart = this-> c_fractionPart - right.c_fractionPart;
	while (temp.c_fractionPart < 0)
	{
		temp.c_wholepart -= 1;
		temp.c_fractionPart += 1;
	}
	temp.c_wholepart = this->c_wholepart - right.c_wholepart;
	
	return temp;
}



std::ostream & operator<<(std::ostream &ostrm, const Currency &obj)
{
	ostrm << obj.c_wholepart << " " << obj.getName() << " " << obj.c_fractionPart*100 << " " << obj.getFracName() << std::endl;
	//assuming fraction part is stored as 0.xx value
	return ostrm;

}

std::istream & operator>>(std::istream &istrm, Currency &obj)
{
	std::cout << "Please enter 0 or other positive amount: ";
	double total = 0.0;
	istrm >> obj.c_wholepart;
	total = obj.c_wholepart;
	obj.c_wholepart = floor(total);
	obj.c_fractionPart = total - obj.c_wholepart;
	return istrm;

}


