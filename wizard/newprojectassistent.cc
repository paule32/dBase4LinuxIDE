#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "source/includes/wizard/newprojectassistent.h"
#include "ui_newprojectassistent.h"

NewProjectAssistent2::NewProjectAssistent2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectAssistent)
{
    ui->setupUi(this);
    
    connect(ui->tableWidget,
        &QTableWidget::itemClicked,
        this,
        &NewProjectAssistent2::on_tableWidget_itemClicked);
}

NewProjectAssistent2::~NewProjectAssistent2()
{
    delete ui;
}

void NewProjectAssistent2::on_tableWidget_itemClicked(QTableWidgetItem *item)
{

}
