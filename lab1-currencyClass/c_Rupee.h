#ifndef RUPEE_H

#include "currency.h"
class c_Rupee : public Currency
{
private:
	//
public:
	c_Rupee() :Currency("Rupee", "paise") {};
	~c_Rupee() {};

};

#endif // !RUPEE_H

