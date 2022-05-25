#include "bst1.h"

BST1::BST1() { root = nullptr; }
BST1::~BST1() { root = makeEmpty(root); }
void BST1::insert(int data) { root = insert(data, root); }
void BST1::inorder() { inorder(root); }
node* BST1::makeEmpty(node* currentNode) {
	if (currentNode == nullptr)
		return nullptr;
	makeEmpty(currentNode->left);
	makeEmpty(currentNode->right);
	delete currentNode;
	return nullptr;
}
node* BST1::insert(int data, node* currentNode) {
	if (currentNode == nullptr) {
		currentNode = new node;
		currentNode->data = data;
		currentNode->left = currentNode->right = nullptr;
	}
	else if (data < currentNode->data)
		currentNode->left = insert(data, currentNode->left);
	else if (data > currentNode->data)
		currentNode->right = insert(data, currentNode->right);
	return currentNode;
}
void BST1::inorder(node* currentNode) {
	if (currentNode == nullptr)
		return;
	inorder(currentNode->left);
	std::cout << currentNode->data << " ";
	inorder(currentNode->right);
}
