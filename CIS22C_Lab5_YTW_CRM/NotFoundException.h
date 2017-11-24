#pragma warning( disable : 4290 )  
#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION
#include <stdexcept>
#include <string>
using namespace std;

class NotFoundException : public logic_error
{
public:
	NotFoundException(const string& message = "") :
		logic_error("Precondition Violated Exception: " + message) {};
};

#endif