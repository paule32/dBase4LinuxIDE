#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include "source/includes/dbase/mainwindow.h"
#include "ui_settings_dialog.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget: public QWidget
{
public:
    explicit SettingsWidget(QWidget *parent = 0);
protected:

private slots:

    void on_pushButton_3_pressed();
    void on_pushButton_2_pressed();
    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_toggled(bool checked);

    void on_listWidget_itemPressed(QListWidgetItem *item);
    
private:
    Ui::SettingsWidget *ui;
};

#endif // SETTINGS_DIALOG_H
