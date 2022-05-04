#include "myArrayNode.h"

myArrayNode::myArrayNode(int data, bool fill) {
	this->data = data;
	this->fill = fill;
}
myArrayNode::~myArrayNode() = default;
myArrayNode myArrayNode::operator=(myArrayNode inputNode) {
	data = inputNode.data;
	fill = inputNode.fill;
	return *this;
}
int myArrayNode::getData() { return data; }
bool myArrayNode::isFilled() { return fill; }
bool myArrayNode::operator<(myArrayNode compareNode) { return(this->data < compareNode.data); }
bool myArrayNode::operator>(myArrayNode compareNode) { return(this->data > compareNode.data); }
std::ostream& operator<<(std::ostream & out, myArrayNode node) {
	out << node.data;
	return out;
}
