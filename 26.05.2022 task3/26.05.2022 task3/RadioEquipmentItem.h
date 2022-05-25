#ifndef RADIOEQUIPMENTITEM_H
#define RADIOEQUIPMENTITEM_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>

class RadioEquipmentItem {
public:
	RadioEquipmentItem(const std::string& productGroup = "",
		const std::string& itemBrand = "",
		const std::string& itemAcceptanceDate = "",
		const std::string& itemExecutionDate = "",
		const std::string& itemTrim = "");
	~RadioEquipmentItem() = default;
	std::string getItemProductGroup() const;
	std::string getItemBrand() const;
	std::string getItemAcceptanceDate() const;
	std::string getItemExecutionDate() const;
	std::string getItemTrim() const;
	bool operator< (const RadioEquipmentItem& compareRadioEquipmentItem) const;
private:
	enum class productGroup {
		TELEVISOR,
		RADIOTELEPHONE,
		OTHER
	};
	productGroup itemProductGroup;
	std::string itemBrand;
	std::string itemAcceptanceDate;
	std::string itemExecutionDate;
	enum class Trim {
		READY,
		NOT_READY
	};
	Trim itemTrim;
};

std::istream& operator>>(std::istream& in, RadioEquipmentItem& radioEquipmentItem);
std::ostream& operator<<(std::ostream& out, RadioEquipmentItem& radioEquipmentItem);
void loadFromFile(std::list<RadioEquipmentItem>& radioEquipmentItems, const std::string& fileName);
void saveToFile(std::list<RadioEquipmentItem>& radioEquipmentItems, const std::string& fileName);

#endif