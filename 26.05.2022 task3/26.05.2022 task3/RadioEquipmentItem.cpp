#include "RadioEquipmentItem.h"

RadioEquipmentItem::RadioEquipmentItem(const std::string& itemProductGroup,
	const std::string& itemBrand,
	const std::string& itemAcceptanceDate,
	const std::string& itemExecutionDate,
	const std::string& itemTrim) : itemBrand(itemBrand),
	itemAcceptanceDate(itemAcceptanceDate),
	itemExecutionDate(itemExecutionDate) {
	if (itemProductGroup == "televisor")
		this->itemProductGroup = RadioEquipmentItem::productGroup::TELEVISOR;
	else if (itemProductGroup == "radiotelephone")
		this->itemProductGroup = RadioEquipmentItem::productGroup::RADIOTELEPHONE;
	else
		this->itemProductGroup = RadioEquipmentItem::productGroup::OTHER;
	if (itemTrim == "ready")
		this->itemTrim = RadioEquipmentItem::Trim::READY;
	else
		this->itemTrim = RadioEquipmentItem::Trim::NOT_READY;
}
std::string RadioEquipmentItem::getItemProductGroup() const {
	switch (itemProductGroup) {
	case RadioEquipmentItem::productGroup::TELEVISOR:
		return "televisor";
	case RadioEquipmentItem::productGroup::RADIOTELEPHONE:
		return "radiotelephone";
	case RadioEquipmentItem::productGroup::OTHER:
		return "other";
	default:
		return "";
	}
}
std::string RadioEquipmentItem::getItemBrand() const { return itemBrand; }
std::string RadioEquipmentItem::getItemAcceptanceDate() const { return itemAcceptanceDate; }
std::string RadioEquipmentItem::getItemExecutionDate() const { return itemExecutionDate; }
std::string RadioEquipmentItem::getItemTrim() const {
	switch (itemTrim) {
	case RadioEquipmentItem::Trim::READY:
		return "ready";
	case RadioEquipmentItem::Trim::NOT_READY:
		return "not ready";
	default:
		return "";
	}
}
bool RadioEquipmentItem::operator< (const RadioEquipmentItem& compareRadioEquipmentItem) const {
	std::string firstItemExecutionYear = this->itemExecutionDate.substr(6, 4);
	std::string secondItemExecutionYear = compareRadioEquipmentItem.itemExecutionDate.substr(6, 4);
	if (firstItemExecutionYear > secondItemExecutionYear)
		return true;
	else if (firstItemExecutionYear < secondItemExecutionYear)
		return false;
	else {
		std::string firstItemExecutionMonth = this->itemExecutionDate.substr(3, 2);
		std::string secondItemExecutionMonth = compareRadioEquipmentItem.itemExecutionDate.substr(3, 2);
		if (firstItemExecutionMonth > secondItemExecutionMonth)
			return true;
		else if (firstItemExecutionMonth < secondItemExecutionMonth)
			return false;
		else {
			std::string firstItemExecutionDay = this->itemExecutionDate.substr(0, 2);
			std::string secondItemExecutionDay = compareRadioEquipmentItem.itemExecutionDate.substr(0, 2);
			if (firstItemExecutionDay > secondItemExecutionDay)
				return true;
			else if (firstItemExecutionDay < secondItemExecutionDay)
				return false;
			else
				return false;
		}
	}
	return false;
}
std::istream& operator>>(std::istream& in, RadioEquipmentItem& radioEquipmentItem) {
	std::string productGroup;
	std::string itemBrand;
	std::string itemAcceptanceDate;
	std::string itemExecutionDate;
	std::string itemTrim;
	in >> productGroup >>
		itemBrand >>
		itemAcceptanceDate >>
		itemExecutionDate >>
		itemTrim;
	radioEquipmentItem = RadioEquipmentItem(productGroup, itemBrand, itemAcceptanceDate, itemExecutionDate, itemTrim);
	return in;
}
std::ostream& operator<<(std::ostream& out, RadioEquipmentItem& radioEquipmentItem) {
	out << radioEquipmentItem.getItemProductGroup() << " " <<
		radioEquipmentItem.getItemBrand() << " " <<
		radioEquipmentItem.getItemAcceptanceDate() << " " <<
		radioEquipmentItem.getItemExecutionDate() << " " <<
		radioEquipmentItem.getItemTrim() << '\n';
	return out;
}
void loadFromFile(std::list<RadioEquipmentItem>& radioEquipmentItems, const std::string& fileName) {
	std::ifstream inputFile(fileName);
	RadioEquipmentItem tempRadioEquipmentItem;
	while (inputFile >> tempRadioEquipmentItem)
		radioEquipmentItems.push_back(tempRadioEquipmentItem);
}
void saveToFile(std::list<RadioEquipmentItem>& radioEquipmentItems, const std::string& fileName) {
	std::ofstream outputFile(fileName);
	for (RadioEquipmentItem& radioEquipmentItem : radioEquipmentItems)
		outputFile << radioEquipmentItem;
}