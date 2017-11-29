/*
 * Contact.h
 *
 *  Created on: Nov 29, 2017
 *      Author: annic
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using namespace std;

struct Contact{
	string name;
	string number;
public:
	Contact(string name, string number) { this->name = name; this->number = number; }
	Contact() { }
	void setName(string);
	void setNumber(string);
	string getName();
	string getNumber();
	friend ostream& operator<<(ostream&, const Contact&);
	friend bool operator!=(const Contact& p1, const Contact& p2);
	friend bool operator==(const Contact& p1, const Contact& p2);
	friend bool operator>(const Contact& p1, const Contact& p2);
	friend bool operator<(const Contact& p1, const Contact& p2);
	friend bool operator>=(const Contact& p1, const Contact& p2);
	friend bool operator<=(const Contact& p1, const Contact& p2);
};

void Contact::setName(string _name){
	name = _name;
}

void Contact::setNumber(string _number){
	number = _number;
}

string Contact::getName(){
	return name;
}

string Contact::getNumber(){
	return number;
}

ostream& operator<<(ostream& os, const Contact& con)
{
	os << con.name << " :" << con.number << endl;
	return os;
}

bool operator!=(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i == 0){
		return false;
	}
	else
		return true;
}

bool operator==(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i == 0){
		return true;
	}
	else
		return false;
}

bool operator>(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i > 0){
		return true;
	}
	else
		return false;
}

bool operator<(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i < 0){
		return true;
	}
	else
		return false;
}

bool operator>=(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i >= 0){
		return true;
	}
	else
		return false;
}

bool operator<=(const Contact& p1, const Contact& p2){
	int i = p1.name.compare(p2.name);
	if(i <= 0){
		return true;
	}
	else
		return false;
}

#endif /* CONTACT_H_ */
