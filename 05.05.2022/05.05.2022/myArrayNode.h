#pragma once

#include <iostream>

class myArrayNode {
public:
	myArrayNode(int data = 0, bool fill = 0);
	int getData() const;
	bool isFilled();
	bool operator < (const myArrayNode& compareNode);
	bool operator > (const myArrayNode& compareNode);
private:
	int data;
	bool fill;
};
std::ostream& operator <<(std::ostream& out, const myArrayNode& node);
