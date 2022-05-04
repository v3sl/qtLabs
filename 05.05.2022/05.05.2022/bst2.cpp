#include<iostream>
#include "bst2.h"

BST2::BST2() {
	BSTArraySize = 0;
	BSTArray = new myArrayNode[BSTArraySize];
}
BST2::~BST2() { delete[] BSTArray; }
void BST2::insert(int data) { insert(data, 0); }
void BST2::inorder() { inorder(0); }
myArrayNode BST2::getLeafByIndex(int index) { return BSTArray[index]; };
void BST2::resize(int size) {
	myArrayNode* newBSTArray = new myArrayNode[BSTArraySize + size];
	for (int i = 0; i < BSTArraySize; ++i)
		newBSTArray[i] = BSTArray[i];
	BSTArraySize += size;
	delete[] BSTArray;
	BSTArray = newBSTArray;
	myArrayNode temp(0, 0);
	for (int i = 0; i < size; ++i)
		BSTArray[BSTArraySize + i] = temp;
}
void BST2::insert(int data, int index) {
	if (index > BSTArraySize - 1) {
		resize(index - BSTArraySize + 1);
		myArrayNode leaf(data, 1);
		BSTArray[index] = leaf;
	}
	else if (BSTArray[index].isFilled() == 0) {
		myArrayNode leaf(data, 1);
		BSTArray[index] = leaf;
	}
	else {
		myArrayNode temp(data, 1);
		if (temp > BSTArray[index])
			insert(data, 2 * index + 2);
		else if (temp < BSTArray[index])
			insert(data, 2 * index + 1);
	}
}
void BST2::inorder(int index) {
	if (index > BSTArraySize - 1 || BSTArray[index].isFilled() == 0)
		return;
	inorder(index * 2 + 1);
	std::cout << BSTArray[index];
	inorder(index * 2 + 2);
}