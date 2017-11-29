/*
 * MyPhonebookApplication.h
 *
 *  Created on: Nov 29, 2017
 *      Author: annic
 */

#ifndef MYPHONEBOOKAPPLICATION_H_
#define MYPHONEBOOKAPPLICATION_H_

#include "BinarySearchTree.h"

class myPhonebookApplication{
private:
	BinarySearchTree Contacts;
	void add();
	void load();
	void search();
	void print();
	void filter();
public:
	myPhonebookApplication() {}
	void run();
};

void myPhonebookApplication::run(){
	char input;

	cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	cout<<"A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) |Q(Quit):"<<endl;
	cin>>input;

	do{
		switch(input)
		{
			//Adds a contact
		case 'A':
		case 'a':
			add();
			break;
			//Loads contacts from file
		case 'L':
		case 'l':
			break;
			//Searches for contact by name
		case 'S':
		case 's':
			break;
			//Prints contacts in ascending order
		case 'P':
		case 'p':
			break;
			//Lists contacts before the inputed name
		case 'F':
		case 'f':
			break;
		case 'Q':
		case 'q':
			cout<<"Bye"<<endl;
			break;
		}

		cout<<endl<<"A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) |Q(Quit):"<<endl;
		cin>>input;

	}while(input != 'Q' && input != 'q');
}

void myPhonebookApplication::add(){
	string name;
	string number;

	cout<<"Enter name: ";
	cin>>name;

	cout<<"Enter phone: ";
	cin>>number;
}

void myPhonebookApplication::load(){

}

void myPhonebookApplication::search(){

}

void myPhonebookApplication:print(){

}

void myPhonebookApplication::filter(){

}

#endif /* MYPHONEBOOKAPPLICATION_H_ */
