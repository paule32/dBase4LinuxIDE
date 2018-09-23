#ifndef HELPDOCKER_H
#define HELPDOCKER_H

#include "source/includes/dbase/mainwindow.h"

class helpDocker : public QWidget
{
public:
    explicit helpDocker(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *target, QEvent *event);
    void closeEvent(QCloseEvent * event);
private:
    bool onHelpClose();
};

#endif // HELPDOCKER_H
