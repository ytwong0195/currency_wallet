#ifndef YEN_H
#define YEN_H

#include "currency.h"

class c_Yen : public Currency
{
private:
	//
public:
	 c_Yen() :Currency("Yen", "sen") {};
	 ~c_Yen() {};
};

#endif // !YEN_H
