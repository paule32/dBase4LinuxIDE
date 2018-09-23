#include "source/includes/dbase/mainwindow.h"
#include "source/parser/pro/projectitem.h"

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>

MyProjectItem::MyProjectItem(QTreeWidget *parent, QString name, int t)
    : QTreeWidgetItem(parent) {
    setValues(name,t);
}

MyProjectItem::MyProjectItem(QTreeWidgetItem *parent, QString name, int t)
    : QTreeWidgetItem(parent) {
    setValues(name,t);
}

void MyProjectItem::setValues(QString name, int t)
{
    QString item_text = name;
    QFont   item_font;

        item_type  = t;
    if (item_type == 1) {
        item_text.append(" [master]");
        item_font.setBold(true);
    }   item_font.setPointSize(10);
    
    if (item_type == 2) {
        item_font.setItalic(true);
    }
    setText(0,item_text);
    setFont(0,item_font);
}

MyProjectItem::~MyProjectItem()
{

}
