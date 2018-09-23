#ifndef MYPROJECTITEM
#define MYPROJECTITEM

#include <QWidget>
#include <QTreeWidget>
#include <QTableWidgetItem>

class MyProjectItem : public QTreeWidgetItem {
public:
    MyProjectItem(QTreeWidgetItem *parent, QString name, int t);
    MyProjectItem(QTreeWidget     *parent, QString name, int t);
    ~MyProjectItem();
    
    void setValues(QString name, int t);
private:
    int item_type;
};

#endif
