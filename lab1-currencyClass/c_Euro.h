#ifndef EURO_H
#include "currency.h"

class c_Euro : public Currency
{
private:
	//
public:
	c_Euro() :Currency("Euro", "cent") {};
	~c_Euro() {};
};

#endif // !EURO_H

