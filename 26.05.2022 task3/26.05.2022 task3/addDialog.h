#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class RadioEquipmentItem;
class AddDialog : public QDialog {
public:
	AddDialog(QWidget* parent = nullptr);
	RadioEquipmentItem radioEquipmentItem() const;
private:
	QLineEdit* productGroupEdit;
	QLineEdit* itemBrandEdit;
	QLineEdit* itemAcceptanceDateEdit;
	QLineEdit* itemExecutionDateEdit;
	QLineEdit* itemTrimEdit;
};

#endif  