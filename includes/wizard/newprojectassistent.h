#ifndef NEWPROJECTASSISTENT_H
#define NEWPROJECTASSISTENT_H

#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

#include ".uic/ui_newprojectassistent.h"

namespace Ui {
class NewProjectAssistent;
}

class NewProjectAssistent2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewProjectAssistent2(QWidget *parent = 0);
    ~NewProjectAssistent2();
    
    void on_tableWidget_itemClicked(QTableWidgetItem *item);
    
private:
    Ui::NewProjectAssistent *ui;
};

#endif // NEWPROJECTASSISTENT_H
