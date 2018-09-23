#ifndef LOCALCONNECTDATABASE_H
#define LOCALCONNECTDATABASE_H

#include <QDialog>

#include ".uic/ui_localconnectdatabase.h"

namespace Ui {
class LocalConnectDataBase;
}

class LocalConnectDataBase : public QDialog
{
    Q_OBJECT
    
public:
    explicit LocalConnectDataBase(QWidget *parent = 0);
    ~LocalConnectDataBase();
    
private:
    Ui::LocalConnectDataBase *ui;
};

#endif // LOCALCONNECTDATABASE_H
