#include "addDialog.h"
#include "RadioEquipmentItem.h"

AddDialog::AddDialog(QWidget* parent) : QDialog(parent) {
	productGroupEdit = new QLineEdit;
	itemBrandEdit = new QLineEdit;
	itemAcceptanceDateEdit = new QLineEdit;
	itemExecutionDateEdit = new QLineEdit;
	itemTrimEdit = new QLineEdit;
	QLabel* productGroupLabel = new QLabel("&Product group");
	QLabel* itemBrandLabel = new QLabel("&Item brand");
	QLabel* itemAcceptanceDateLabel = new QLabel("&Acceptance date");
	QLabel* itemExecutionDateLabel = new QLabel("&Execution date");
	QLabel* itemTrimLabel = new QLabel("&Trim");
	productGroupLabel->setBuddy(productGroupEdit);
	itemBrandLabel->setBuddy(itemBrandEdit);
	itemAcceptanceDateLabel->setBuddy(itemAcceptanceDateEdit);
	itemExecutionDateLabel->setBuddy(itemExecutionDateEdit);
	itemTrimLabel->setBuddy(itemTrimEdit);
	QPushButton* okButton = new QPushButton("&Ok");
	QPushButton* cancelButton = new QPushButton("&Cancel");
	connect(okButton, SIGNAL(clicked()), SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(productGroupLabel, 0, 0);
	layout->addWidget(itemBrandLabel, 1, 0);
	layout->addWidget(itemAcceptanceDateLabel, 2, 0);
	layout->addWidget(itemExecutionDateLabel, 3, 0);
	layout->addWidget(itemTrimLabel, 4, 0);
	layout->addWidget(productGroupEdit, 0, 1);
	layout->addWidget(itemBrandEdit, 1, 1);
	layout->addWidget(itemAcceptanceDateEdit, 2, 1);
	layout->addWidget(itemExecutionDateEdit, 3, 1);
	layout->addWidget(itemTrimEdit, 4, 1);
	layout->addWidget(okButton, 5, 0);
	layout->addWidget(cancelButton, 5, 1);

	setLayout(layout);
}
RadioEquipmentItem AddDialog::radioEquipmentItem() const {
	std::string productGroup = productGroupEdit->text().toStdString();
	std::string itemBrand = itemBrandEdit->text().toStdString();
	std::string itemAcceptanceDate = itemAcceptanceDateEdit->text().toStdString();
	std::string itemExecutionDate = itemExecutionDateEdit->text().toStdString();
	std::string itemTrim = itemTrimEdit->text().toStdString();
	return RadioEquipmentItem(productGroup, itemBrand, itemAcceptanceDate, itemExecutionDate, itemTrim);
}