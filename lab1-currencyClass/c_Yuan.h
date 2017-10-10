#ifndef YUAN_H
#define YUAN_H
#include "currency.h"

class c_Yuan : public Currency
{
private:
	//
public:
	 c_Yuan() :Currency("Yuan", "fen") {};
	 ~c_Yuan() {};

};


#endif // !YUAN_H

