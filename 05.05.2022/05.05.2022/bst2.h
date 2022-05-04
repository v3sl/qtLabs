#pragma once

#include "myArrayNode.h" 

class BST2 {
public:
	BST2();
	~BST2();
	void insert(int data);
	void inorder();
	myArrayNode getLeafByIndex(int index);
private:
	myArrayNode* BSTArray;
	int BSTArraySize;
	void resize(int size);
	void insert(int data, int index);
	void inorder(int index);
};