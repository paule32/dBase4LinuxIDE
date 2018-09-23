#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QtWidgets/QWidget>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QMainWindow>

class KeyPress : public QWidget
{
public:
    explicit KeyPress(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent * e);
};

#endif // KEYPRESS_H
