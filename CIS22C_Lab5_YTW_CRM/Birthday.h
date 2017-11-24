#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <string>
#include <iostream>
class Birthday
{
private:
	std::string f_name;
	std::string l_name;
	std::string birthday;

public:
	Birthday(std::string, std::string, std::string);
	void set_firstn(std::string);
	void set_lastn(std::string);
	void set_birthday(std::string);

	std::string getFirst();
	std::string getLast();
	std::string getBirthday();
	std::string getFullName();

	friend std::ostream &operator<< (std::ostream &output, const Birthday &item) {
		output << getFullName() << "\n" << getBirthday() << "\n" ;
		return output;
	}
};



inline Birthday::Birthday(std::string first, std::string last, std::string birthdate)
{
	f_name = first;
	l_name = last;
	birthday = birthdate;
}

inline void Birthday::set_firstn(std::string firstname) {
	f_name = firstname;
}

inline void Birthday::set_lastn(std::string lastname) {
	l_name = lastname;
}

inline void Birthday::set_birthday(std::string birthdate) {
	birthday = birthdate;
}

inline std::string Birthday::getFirst() {
	return f_name;
}

inline std::string Birthday::getLast() {
	return l_name;
}

std::string Birthday::getBirthday() {
	return birthday;
}

inline std::string Birthday::getFullName() {
	std::string fullName = f_name + " " + l_name;
	return fullName;
}


#endif // !1

