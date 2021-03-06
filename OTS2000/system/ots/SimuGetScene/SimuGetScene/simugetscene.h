#ifndef SIMUGETSCENE_H
#define SIMUGETSCENE_H

#include "ui_simugetscene.h"
#include "/home/ems/system/ots/ots_hdb/inc/ots_hdb.h" 

#define ITEM_TYPE	0
#define ITEM_STN_ID		1
#define ITEM_DEV_ID		2
#define ITEM_DATA_TYPE	3
class SimuGetSceneTable : public QDialog,public Ui_CSimuGetScene
{
	Q_OBJECT
public:
	SimuGetSceneTable(QWidget *parent=0);
protected:
	void showEvent(QShowEvent *event);
private:
	QStandardItemModel *pointSourceModel;
	QSortFilterProxyModel *pointModel;
	QItemSelectionModel *selectionModel;
	short pointMode,pointShowType;
	QHash<QString,QPair<short, short>> hashPoint;
	void updateParentItem(QTreeWidgetItem* item);
	void updateParentItem();
	void displayStnDevTree();
	private slots:
		void displayPoint(QTreeWidgetItem *current, QTreeWidgetItem *previous);
		void treeItemChanged(QTreeWidgetItem *item,int column);
		void filterChanged(const QString &text);
		void selectAll();
		void selectOff();
		void selectInvert();
		void pointModeChange(int);
		void pointShowTypeChange(int);
		void pointClicked(const QModelIndex & index);
		void saveAllChange();
};
#endif