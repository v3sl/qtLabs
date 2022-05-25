#include "mainwidget.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent) {
	createMenuBar();
	createLabels();
	createListWidgets();
	createLayout();
}
void MainWidget::openChosenFile() {
	QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
	loadFromFile(radioEquipmentItems, fileName.toStdString());
	showRadioEquipmentItems();
}
void MainWidget::saveInformationAsFile() {
	QString fileName = QFileDialog::getSaveFileName(0, "Save Dialog", "", "*.txt");
	saveToFile(radioEquipmentItems, fileName.toStdString());
}
void MainWidget::addInputRadioEquipmentItem() {
	AddDialog* addDialog = new AddDialog(this);
	if (addDialog->exec() == QDialog::Accepted) {
		RadioEquipmentItem tempRadioEquipmentItem = addDialog->radioEquipmentItem();
		radioEquipmentItems.push_back(tempRadioEquipmentItem);
		showRadioEquipmentItems();
	}
}
void MainWidget::deleteCurrentRadioEquipmentItem() {
	int radioEquipmentItemIndex = radioEquipmentListWidget->currentRow();
	if (radioEquipmentItemIndex == -1)
		return;
	radioEquipmentListWidget->takeItem(radioEquipmentItemIndex);
	std::list<RadioEquipmentItem>::iterator iterator = radioEquipmentItems.begin();
	for (int i = 0; i < radioEquipmentItemIndex; ++i, ++iterator);
	radioEquipmentItems.erase(iterator);
}
void MainWidget::sortByDate() {
	radioEquipmentItems.sort();
	showRadioEquipmentItems();
}
void MainWidget::getCurrentDayReadiness() {
	std::list<RadioEquipmentItem> currentDayItems;
	QString localDate = getCurrentDate();
	for (RadioEquipmentItem& radioEquipmentItem : radioEquipmentItems) {
		if (compareDates(QString::fromStdString(radioEquipmentItem.getItemExecutionDate()), localDate) == 0)
			currentDayItems.push_back(radioEquipmentItem);
	}
	QString incompletedOrdersString = "";
	for (RadioEquipmentItem& radioEquipmentItem : currentDayItems) {
		if (radioEquipmentItem.getItemProductGroup() == "televisor")
			addRadioEquipmentItemInformation(incompletedOrdersString, radioEquipmentItem);
	}
	incompletedOrdersString += '\n';
	for (RadioEquipmentItem& radioEquipmentItem : currentDayItems) {
		if (radioEquipmentItem.getItemProductGroup() == "radiotelephone")
			addRadioEquipmentItemInformation(incompletedOrdersString, radioEquipmentItem);
	}
	incompletedOrdersString += '\n';
	for (RadioEquipmentItem& radioEquipmentItem : currentDayItems) {
		if (radioEquipmentItem.getItemProductGroup() == "other")
			addRadioEquipmentItemInformation(incompletedOrdersString, radioEquipmentItem);
	}
	QMessageBox* incompletedOrdersInformation = new QMessageBox(this);
	incompletedOrdersInformation->setText(incompletedOrdersString);
	incompletedOrdersInformation->exec();
}
void MainWidget::getIncompletedOrders() {
	std::list<RadioEquipmentItem> incompletedOrders;
	for (RadioEquipmentItem& radioEquipmentItem : radioEquipmentItems) {
		if (isIncompletedOrder(radioEquipmentItem))
			incompletedOrders.push_back(radioEquipmentItem);
	}
	QString incompletedOrdersString = "";
	for (RadioEquipmentItem& radioEquipmentItem : incompletedOrders)
		addRadioEquipmentItemInformation(incompletedOrdersString, radioEquipmentItem);
	QMessageBox* incompletedOrdersInformation = new QMessageBox(this);
	incompletedOrdersInformation->setText(incompletedOrdersString);
	incompletedOrdersInformation->exec();
}
void MainWidget::onChangedSearchFiled() {
	QString searchedString = searchField->text();
	radioEquipmentListWidget->clear();
	for (RadioEquipmentItem& radioEquipmentItem : radioEquipmentItems) {
		if (radioEquipmentItem.getItemProductGroup().substr(0, searchedString.size()) == searchedString.toStdString() ||
			radioEquipmentItem.getItemAcceptanceDate().substr(0, searchedString.size()) == searchedString.toStdString() ||
			radioEquipmentItem.getItemExecutionDate().substr(0, searchedString.size()) == searchedString.toStdString())
			showRadioEquipmentItem(radioEquipmentItem);
	}
}
void MainWidget::createMenuBar() {
	createFileMenu();
	createEditMenu();
	createInfoMenu();
	menuBar = new QMenuBar(this);
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(editMenu);
	menuBar->addMenu(infoMenu);
}
void MainWidget::createFileMenu() {
	createFileActions();
	fileMenu = new QMenu("file");
	fileMenu->addSeparator();
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(saveFileAction);
	fileMenu->addAction(addRadioEquipmentItemAction);
	fileMenu->addAction(deleteRadioEquipmentItemAction);
}
void MainWidget::createFileActions() {
	createOpenFileAction();
	createSaveFileAction();
	createAddAction();
	createDeleteAction();
}
void MainWidget::createOpenFileAction() {
	openFileAction = new QAction("open", this);
	openFileAction->setShortcuts(QKeySequence::New);
	openFileAction->setStatusTip(tr("open file"));
	connect(openFileAction, &QAction::triggered, this, &MainWidget::openChosenFile);
}
void MainWidget::createSaveFileAction() {
	saveFileAction = new QAction("&save as", this);
	saveFileAction->setShortcut(QKeySequence(Qt::SHIFT + Qt::CTRL + Qt::Key_S));
	saveFileAction->setStatusTip(tr("save file as"));
	connect(saveFileAction, &QAction::triggered, this, &MainWidget::saveInformationAsFile);
}
void MainWidget::createAddAction() {
	addRadioEquipmentItemAction = new QAction("&add item", this);
	addRadioEquipmentItemAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_N));
	addRadioEquipmentItemAction->setStatusTip(tr("add radio equipment item"));
	connect(addRadioEquipmentItemAction, &QAction::triggered, this, &MainWidget::addInputRadioEquipmentItem);
}
void MainWidget::createDeleteAction() {
	deleteRadioEquipmentItemAction = new QAction("&delete item", this);
	deleteRadioEquipmentItemAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Delete));
	deleteRadioEquipmentItemAction->setStatusTip("delete radio equipment item");
	connect(deleteRadioEquipmentItemAction, &QAction::triggered, this, &MainWidget::deleteCurrentRadioEquipmentItem);
}
void MainWidget::createEditMenu() {
	createEditActions();
	editMenu = new QMenu("&view");
	editMenu->addAction(sortAction);
}
void MainWidget::createEditActions() { createSortAction(); }
void MainWidget::createSortAction() {
	sortAction = new QAction("&sort", this);
	sortAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_S));
	sortAction->setStatusTip(tr("sort by date"));
	connect(sortAction, &QAction::triggered, this, &MainWidget::sortByDate);
}
void MainWidget::createInfoMenu() {
	createInfoActions();
	infoMenu = new QMenu("&info");
	infoMenu->addAction(getCurrentDayReadinessAction);
	infoMenu->addAction(getIncompletedOrdersAction);
}
void MainWidget::createInfoActions() {
	createGetCurrentDayReadinessAction();
	createGetIncompletedOrdersAction();
}
void MainWidget::createGetCurrentDayReadinessAction() {
	getCurrentDayReadinessAction = new QAction("&current day readiness", this);
	getCurrentDayReadinessAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
	getCurrentDayReadinessAction->setStatusTip(tr("get current day readiness"));
	connect(getCurrentDayReadinessAction, &QAction::triggered, this, &MainWidget::getCurrentDayReadiness);
}
void MainWidget::createGetIncompletedOrdersAction() {
	getIncompletedOrdersAction = new QAction("&incompleted orders", this);
	getIncompletedOrdersAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
	getIncompletedOrdersAction->setStatusTip(tr("get incompleted orders"));
	connect(getIncompletedOrdersAction, &QAction::triggered, this, &MainWidget::getIncompletedOrders);
}
void MainWidget::createLabels() {
	searchFieldTitle = new QLabel("Search:", this);
	searchField = new QLineEdit(this);
	searchField->setFixedHeight(30);
	connect(searchField, SIGNAL(textChanged(const QString&)), SLOT(onChangedSearchFiled()));
}
void MainWidget::createListWidgets() { radioEquipmentListWidget = new QListWidget(this); }
void MainWidget::createLayout() {
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setMenuBar(menuBar);
	layout->addWidget(searchFieldTitle);
	layout->addWidget(searchField);
	layout->setContentsMargins(5, 5, 5, 5);
	layout->addWidget(radioEquipmentListWidget);
	this->setLayout(layout);
}
void MainWidget::addRadioEquipmentItemInformation(QString& information, const RadioEquipmentItem& radioEquipmentItem) {
	information += QString::fromStdString(radioEquipmentItem.getItemProductGroup() + " " +
		radioEquipmentItem.getItemBrand() + " " +
		radioEquipmentItem.getItemAcceptanceDate() + " " +
		radioEquipmentItem.getItemExecutionDate() + " " +
		radioEquipmentItem.getItemTrim() + '\n');
}
bool MainWidget::isIncompletedOrder(const RadioEquipmentItem& radioEquipmentItem) {
	QString itemExecutionDate = QString::fromStdString(radioEquipmentItem.getItemExecutionDate());
	QString localDate = getCurrentDate();
	if (compareDates(QString::fromStdString(radioEquipmentItem.getItemExecutionDate()), localDate) == -1 &&
		radioEquipmentItem.getItemTrim() == "not ready")
		return true;
	return false;
}
QString MainWidget::getCurrentDate() {
	time_t PCTime;
	PCTime = time(NULL);
	struct tm* currentTime;
	currentTime = localtime(&PCTime);
	QString localDate = QString::number((currentTime->tm_mday)) + "." + QString::number(currentTime->tm_mon + 1) + "." + QString::number(currentTime->tm_year + 1900);
	return localDate;
}
int MainWidget::compareDates(const QString& firstDate, QString& secondDate) {
	secondDate = correctDate(secondDate);
	secondDate = correctDate(secondDate);
	std::string firstItemExecutionYear = firstDate.toStdString().substr(6, 4);
	std::string secondItemExecutionYear = secondDate.toStdString().substr(6, 4);
	if (firstItemExecutionYear > secondItemExecutionYear)
		return 1;
	else if (firstItemExecutionYear < secondItemExecutionYear)
		return -1;
	else {
		std::string firstItemExecutionMonth = firstDate.toStdString().substr(3, 2);
		std::string secondItemExecutionMonth = secondDate.toStdString().substr(3, 2);
		if (firstItemExecutionMonth > secondItemExecutionMonth)
			return 1;
		else if (firstItemExecutionMonth < secondItemExecutionMonth)
			return -1;
		else {
			std::string firstItemExecutionDay = firstDate.toStdString().substr(0, 2);
			std::string secondItemExecutionDay = secondDate.toStdString().substr(0, 2);
			if (firstItemExecutionDay > secondItemExecutionDay)
				return 1;
			else if (firstItemExecutionDay < secondItemExecutionDay)
				return -1;
		}
	}
	return 0;
}
QString MainWidget::correctDate(QString& date) {
	if (date.size() == 9) {
		std::string tempDate = date.toStdString();
		tempDate.insert(3, "0");
		date = QString::fromStdString(tempDate);
	}
	return date;
}
void MainWidget::showRadioEquipmentItems() {
	radioEquipmentListWidget->clear();
	for (const RadioEquipmentItem& radioEquipmentItem : radioEquipmentItems)
		showRadioEquipmentItem(radioEquipmentItem);
}
void MainWidget::showRadioEquipmentItem(const RadioEquipmentItem& radioEquipmentItem) {
	QString radioEquipmentItemInformation;
	radioEquipmentItemInformation += QString::fromStdString(radioEquipmentItem.getItemProductGroup());
	radioEquipmentItemInformation += " ";
	radioEquipmentItemInformation += QString::fromStdString(radioEquipmentItem.getItemBrand());
	radioEquipmentItemInformation += " ";
	radioEquipmentItemInformation += QString::fromStdString(radioEquipmentItem.getItemAcceptanceDate());
	radioEquipmentItemInformation += " ";
	radioEquipmentItemInformation += QString::fromStdString(radioEquipmentItem.getItemExecutionDate());
	radioEquipmentItemInformation += " ";
	radioEquipmentItemInformation += QString::fromStdString(radioEquipmentItem.getItemTrim());
	radioEquipmentListWidget->addItem(radioEquipmentItemInformation);
}