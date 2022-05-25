#pragma once

#include <iostream>
#include "myNode.h"

class BST1 {
public:
	BST1();
	~BST1();
	void insert(int data);
	void inorder();
	node* getRoot() { return root; }
private:
	node* root;
	node* makeEmpty(node* currentNode);
	node* insert(int data, node* currentNode);
	void inorder(node* currentNode);
};