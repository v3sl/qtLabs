#include "myArrayNode.h"

myArrayNode::myArrayNode(int data, bool fill) {
	this->data = data;
	this->fill = fill;
}
int myArrayNode::getData() const { return data; }
bool myArrayNode::isFilled() { return fill; }
bool myArrayNode::operator<(const myArrayNode& compareNode) { return(this->data < compareNode.data); }
bool myArrayNode::operator>(const myArrayNode& compareNode) { return(this->data > compareNode.data); }

std::ostream& operator<<(std::ostream& out, const myArrayNode& node) {
	out << node.getData() << ' ';
	return out;
}
