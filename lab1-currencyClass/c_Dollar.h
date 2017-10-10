#ifndef DOLLAR_H
#define DOLLAR_H

#include "currency.h"

class c_Dollar : public Currency
{
protected:
	//
public:
	 c_Dollar() :Currency("Dollar", "cent") {};
	 ~c_Dollar() {};
};

#endif // !DOLLAR_H

