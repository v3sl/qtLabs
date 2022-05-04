#pragma once

#include <iostream>

class myArrayNode {
public:
	myArrayNode(int data = 0, bool fill = 0);
	~myArrayNode();
	myArrayNode operator=(myArrayNode inputNode);
	int getData();
	bool isFilled();
	bool operator < (myArrayNode compareNode);
	bool operator > (myArrayNode compareNode);
	friend std::ostream& operator <<(std::ostream& out, myArrayNode node);
private:
	int data;
	bool fill;
};