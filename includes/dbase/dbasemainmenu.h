#ifndef DBASEMAINMENU_H
#define DBASEMAINMENU_H

#include <QMenu>
#include <QEvent>
#include <QString>

class dBaseMainMenu : public QMenu
{
public:
    explicit dBaseMainMenu(class QWidget * parent=0);

protected:
    void enterEvent(class QEvent * event);
    void leaveEvent(class QEvent * event);

private:
    QString style_old;
    QString style_new;
};

#endif // DBASEMAINMENU_H
