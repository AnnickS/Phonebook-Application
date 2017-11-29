/*
 * MyPhonebookApplication.h
 *
 *  Created on: Nov 29, 2017
 *      Author: annic
 */

#ifndef MYPHONEBOOKAPPLICATION_H_
#define MYPHONEBOOKAPPLICATION_H_

#include <algorithm>
#include "BinarySearchTree.h"
#include "Contact.h"

class myPhonebookApplication{
private:
	BinarySearchTree<Contact> contactList;
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

			search();
			break;

			//Prints contacts in ascending order
		case 'P':
		case 'p':

			print();
			break;

			//Lists contacts before the inputed name
		case 'F':
		case 'f':

			filter();
			break;

			//Quits
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

	if(std::any_of(name.begin(), name.end(), ::isdigit)){
			cout<<"Invalid input."<<endl;
			return;
	}

	cout<<"Enter phone: ";
	cin>>number;

	Contact adding = Contact(name, number);

	contactList.insert(adding);
}

void myPhonebookApplication::load(){
	string name;

	cout<<"Enter file name: ";
	cin>>name;

}

void myPhonebookApplication::search(){
	string name;
	Contact search;

	cout<<"Enter name: ";
	cin>>name;

	search.setName(name);

	Contact* found = &contactList.search(search)->data;
	if(found != NULL){
		cout<<"Phone: "<<found->getNumber();
	}
	else
		cout<<"Could not find contact.";

}

void myPhonebookApplication::print(){
	contactList.inOrder();
}

void myPhonebookApplication::filter(){
	string name;
	Contact con;

	cout<<"Enter name: ";
	cin>>name;

	int i = contactList.inOrderTo(con);

	cout<<i<<" contacts..."<<endl;
}

#endif /* MYPHONEBOOKAPPLICATION_H_ */
