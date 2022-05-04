#pragma once
class bst {
public:
	bst();
	~bst();
	void insert(int data);
private:
	int bstArraySize;
	int* bstArray = new int[bstArraySize];
	void resize(int size);
	void remove();
	void insert(int data, int index);
};