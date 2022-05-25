#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets/QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <list>
#include <time.h>
#include "RadioEquipmentItem.h"
#include "adddialog.h"

class MainWidget : public QWidget {
	Q_OBJECT
public:
	MainWidget(QWidget* parent = Q_NULLPTR);
	~MainWidget() = default;
protected slots:
	void openChosenFile();
	void saveInformationAsFile();
	void addInputRadioEquipmentItem();
	void deleteCurrentRadioEquipmentItem();
	void sortByDate();
	void getIncompletedOrders();
	void getCurrentDayReadiness();
	void onChangedSearchFiled();
private:
	QMenuBar* menuBar;
	QMenu* fileMenu;
	QAction* openFileAction;
	QAction* saveFileAction;
	QAction* addRadioEquipmentItemAction;
	QAction* deleteRadioEquipmentItemAction;
	QMenu* editMenu;
	QAction* sortAction;
	QMenu* infoMenu;	
	QAction* getIncompletedOrdersAction;
	QAction* getCurrentDayReadinessAction;
	QLineEdit* searchField;
	QLabel* searchFieldTitle;
	QListWidget* radioEquipmentListWidget;
	std::list<RadioEquipmentItem> radioEquipmentItems;
	void createMenuBar();
	void createFileMenu();
	void createFileActions();
	void createOpenFileAction();
	void createSaveFileAction();
	void createAddAction();
	void createDeleteAction();
	void createEditMenu();
	void createEditActions();
	void createSortAction();
	void createInfoMenu();
	void createInfoActions();
	void createGetCurrentDayReadinessAction();
	void createGetIncompletedOrdersAction();
	void createLabels();
	void createListWidgets();
	void createLayout();
	void addRadioEquipmentItemInformation(QString& information, const RadioEquipmentItem& radioEquipmentItem);
	bool isIncompletedOrder(const RadioEquipmentItem& radioEquipmentItem);
	QString getCurrentDate();
	int compareDates(const QString& firstDate, QString& secondDate);
	QString correctDate(QString& string);
	void showRadioEquipmentItems();
	void showRadioEquipmentItem(const RadioEquipmentItem& radioEquipmentItem);
};

#endif