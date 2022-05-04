#include "bst.h"

bst::bst() {
	bstArraySize = 0;
}
bst::~bst() {
	delete bstArray;
}
void bst::resize(int size) {
	bstArraySize += size;
	int* newBstArray = new int[bstArraySize];
	for (int i = 0; i < bstArraySize; ++i)
		newBstArray[i] = bstArray[i];
	delete[] bstArray;
	bstArray = newBstArray;
}

void bst::insert(int data) {
}

void bst::insert(int data, int index) {
	if (index > bstArraySize -1 ) {
		resize(bstArraySize - index);
		bstArray[index] = data;
		return;
	}
	else if()
}

