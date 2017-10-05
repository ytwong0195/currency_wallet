#pragma once // <----what is this?
#include <iostream>
#include <iomanip>
#include <string>

//using namespace std; //not sure if we can use namespace std here

class Currency
{
private:
	std::string c_name;
	std::string c_fractionName;
	int c_wholepart;
	double c_fractionPart;

public:
	Currency();
	//more constructors to set name and fractional name + initial value


};
