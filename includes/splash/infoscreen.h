#ifndef LIZENZDIALOG_H
#define LIZENZDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QAbstractButton>
#include <QWidget>
#include <QString>

#include "ui_infoscreen.h"

namespace Ui {
class LizenzDialog;
}

class LizenzDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LizenzDialog(QWidget *parent = 0);
    ~LizenzDialog();

    QString getZipContent(QString hfile);
    int exit_code;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::LizenzDialog *ui;
};

#endif // LIZENZDIALOG_H
