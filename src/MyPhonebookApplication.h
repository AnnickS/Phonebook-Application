/*
 * MyPhonebookApplication.h
 *
 *  Created on: Nov 29, 2017
 *      Author: annic
 */

#ifndef MYPHONEBOOKAPPLICATION_H_
#define MYPHONEBOOKAPPLICATION_H_

#include <algorithm>
#include <fstream>
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

	do{
		cin.clear();

		cout<<endl<<"A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) |Q(Quit):"<<endl;
		cin>>input;

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

			load();
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
			contactList.destroyTree();
			cout<<"Bye"<<endl;
			break;
		}

	}while(input != 'Q' && input != 'q');
}

void myPhonebookApplication::add(){
	string name;
	string number;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout<<"Enter name: ";
	getline(cin, name);
	if(name[name.length() - 1] == '\r') name = name.substr(0, name.length() - 1);

	if(std::any_of(name.begin(), name.end(), ::isdigit)){
			cout<<"Invalid input."<<endl;
			return;
	}

	cout<<"Enter phone: ";
	getline(cin, number);

	Contact adding = Contact(name, number);

	contactList.insert(adding);
}

void myPhonebookApplication::load(){
	Contact c;
	string name;
	string nameLast;
	string number;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout<<"Enter file name: ";
	cin>>name;

	ifstream inFile;
	inFile.open(name);
//	ofstream onFile;
//	onFile.open("phonebook1.txt");

	while(inFile >> name)
	{
		//cout<<"does it get here?"<<endl;
		inFile >> nameLast;
		inFile >> number;
		name += " " +nameLast;
		c = Contact(name, number);
		contactList.insert(c);
	}
}

void myPhonebookApplication::search(){
	string name;
	Contact search;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout<<"Enter name: ";
	getline(cin, name);
	if(name[name.length() - 1] == '\r') name = name.substr(0, name.length() - 1);

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

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout<<"Enter name: ";
	cin>>name;

	con.setName(name);

	int i = contactList.inOrderTo(con);

	cout<<i<<" contacts..."<<endl;
}

#endif /* MYPHONEBOOKAPPLICATION_H_ */
