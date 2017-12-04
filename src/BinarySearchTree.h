/*
 * BinarySearchTree.h
 *
 *  Created on: Nov 29, 2017
 *      Author: annic
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;

template<class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template<class T>
class BinarySearchTree{
	node<T>* root;
private:
	void inOrderT(node<T>*);
	void preOrderT(node<T>*);
	void postOrderT(node<T>*);
	int inOrderToT(node<T>*, T&);
	int heightT(node<T>*);
	int countT(node<T>*);
	void insertT(node<T>*&, T&);
	node<T>* searchT(node<T>*, T&);
	void deleteNodeT(node<T>*&, T&);
	int leafCount(node<T>*);
	node<T>* findMaxT(node<T>*);
	node<T>* findMinT(node<T>*);
	void destroyT(node<T>*);

public:
	BinarySearchTree() {}
	void inOrder();
	void preOrder();
	void postOrder();
	int inOrderTo(T&);
	int height();
	int count();
	void insert(T&);
	node<T>* search(T&);
	void deleteNode(T&);
	int numOfNodes();
	int numOfLeaves();
	node<T>* findMax();
	node<T>* findMin();
	void destroyTree();
};

template<class T>
void BinarySearchTree<T>::inOrder(){
	inOrderT(root);
	/*
	 * Stack<node<T>*> s;
	 * node<T>* p = root;
	 * while(p != NULL || !s.isEmpty){
	 * 	if(p != NULL){
	 * 		s.push(p);
	 * 		p=p->left;
	 * 	} else {
	 * 		p = s.pop()'
	 * 		cout<<p->data;
	 * 		p = p->right;
	 */
}

template<class T>
void BinarySearchTree<T>::inOrderT(node<T>* p){
	if(p != NULL){
		inOrderT(p->left);
		cout<<p->data;
		inOrderT(p->right);
	}
}

template<class T>
void BinarySearchTree<T>::preOrder(){
	preOrderT(root);
}

template<class T>
void BinarySearchTree<T>::preOrderT(node<T>* p){
	if(p != NULL){
		cout<<p->data;
		inOrderT(p->left);
		inOrderT(p->right);
	}
}

template<class T>
void BinarySearchTree<T>::postOrder(){
	postOrderT(root);
}

template<class T>
void BinarySearchTree<T>::postOrderT(node<T>* p){
	if(p != NULL){
		inOrderT(p->left);
		inOrderT(p->right);
		cout<<p->data;
	}
}

template<class T>
int BinarySearchTree<T>::inOrderTo(T& item){
	return inOrderToT(root, item);
}

template<class T>
int BinarySearchTree<T>::inOrderToT(node<T>* p, T& item){
	if(p != NULL ){
		if(p->data > item){
			inOrderToT(p->left, item);
		}
		else{
			int i;
			i = inOrderToT(p->left, item);
			cout<<p->data;
			return 1+i+inOrderToT(p->right, item);

			return 0;
		}
	}
	else
		return 0;
}

template<class T>
int BinarySearchTree<T>::height(){
	//if the index starts at 0 add the minus 1
	return heightT(root)-1;
}

template<class T>
int BinarySearchTree<T>::heightT(node<T>* p){
	if(p == NULL)
		return 0;
	return 1+max(heightT(p->left), heightT(p->right));
}

template<class T>
int BinarySearchTree<T>::count(){
	return countT(root);
}

template<class T>
int BinarySearchTree<T>::countT(node<T>* p){
	if(p == NULL){
		return 0;
	}
	else{
		return 1+countT(p->left)+countT(p->right);
	}
}

template<class T>
int BinarySearchTree<T>::numOfLeaves(){
	return leafCount(root);
}

template<class T>
int BinarySearchTree<T>::leafCount(node<T>* p){
	if(p == NULL){
		return 0;
	}
	else if(p->left == NULL && p->right == NULL){
		return 1;
	}
	else
		return leafCount(p->left)+leafCount(p->right);
}

template<class T>
void BinarySearchTree<T>::insert(T& item){
	insertT(root, item);
}

template<class T> //The notation *& is a reference to a pointer. You're not creating
void BinarySearchTree<T>::insertT(node<T>*& p, T& item){ // a new one. So you change
	if(p == NULL){										 // the original.
		//Now you're making a new node but not a new address
		p = new node<T>;
		p->data = item;
		p->right=p->left=NULL;
	} else {
		if(p->data < item){
			insertT(p->right, item);
		}
		else if(p->data > item){
			insertT(p->left, item);
		}
	}
}

template<class T>
node<T>* BinarySearchTree<T>::search(T& item){
	return searchT(root, item);
}

template<class T>
node<T>* BinarySearchTree<T>::searchT(node<T>* p, T& item){
	if(p == NULL){
		return NULL;
	}
	else if(item < p->data){
		return searchT(p->left, item);
	}
	else if(item > p->data){
		return searchT(p->right, item);
	}
	else
		return p;
}

template<class T>
void BinarySearchTree<T>::deleteNode(T& item){
	deleteNodeT(root, item);
}

template<class T>
void BinarySearchTree<T>::deleteNodeT(node<T>*& p, T& item){
	if(p == NULL){
		return;
	}
	else if(item < p->data){
		deleteNodeT(p->left, item);
	}
	else if(item > p->data){
		deleteNodeT(p->right, item);
	}
	else{ //item == p->data
		if(p->right != NULL && p->left != NULL){
			p->data = findMax(p->left)->data;
			deleteNodeT(p->left, p->data);
		}
		else{
			node<T>* temp=p;
			if(p->left != NULL){
				p = p->left;
			}
			else{
				p = p->right;
			}
			delete temp;
		}
	}
}

template<class T>
node<T>* BinarySearchTree<T>::findMax(){
	return findMaxT(root);
}

template<class T>
node<T>* BinarySearchTree<T>::findMaxT(node<T>* p){
	if(p == NULL){
		return NULL;
	}
	else if(p->right == NULL){
		return p;
	}
	else
		return findMaxT(p->right);
}

template<class T>
node<T>* BinarySearchTree<T>::findMin(){
	return findMinT(root);
}

template<class T>
node<T>* BinarySearchTree<T>::findMinT(node<T>* p){
	if(p == NULL){
		return  NULL;
	}
	else if(p->left == NULL){
		return p;
	}
	else
		return findMinT(p->left);
}

template<class T>
void BinarySearchTree<T>::destroyTree(){
	destroyT(root);
}

template<class T>
void BinarySearchTree<T>::destroyT(node<T>* p){
	if(p != NULL){
		destroyT(p->left);
		destroyT(p->right);
		delete p;
	}
}

#endif /* BINARYSEARCHTREE_H_ */
