/************************************************
   This is the header file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member 
   functions are just accessors and input/output functions.
       John Dolan	Spring 2014	Ohio University
***********************************************************/

#include<iostream>
#include<string>
#include "date.h"
#ifndef FRIEND_H
#define FRIEND_H


class Friend{
    public:
	Friend();
	std::string get_name()const;
	Date get_bday()const;
	void set_name(std::string n);
	void set_bday(Date bd);
	bool operator == (const Friend& other)const;
	bool operator != (const Friend& other)const;
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
    private:
	std::string name;
	// I used lname for testing purposes and now the program crashes if I try to remove it
	std::string lname;
	Date bday;
};

std::istream& operator >>(std::istream& ins,Friend& f);
std::ostream& operator <<(std::ostream& outs,const Friend& f);

#endif
