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
	Currency * nextLoc;

public:
	Currency();
	Currency(std::string, std::string);

	~Currency();

	std::string getName() const;
	std::string getFracName() const;


	Currency operator + (const Currency &);

	Currency operator - (const Currency &);

	friend std::ostream &operator<<(std::ostream &, const Currency &);

	friend std::istream &operator>>(std::istream  &, Currency &);


	


};
#endif //


