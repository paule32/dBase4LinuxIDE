#ifndef CONNECTTOBDE_H
#define CONNECTTOBDE_H

#include <QWidget>
#include <QColumnView>

class ConnectToBDE : public QColumnView
{
public:
    explicit ConnectToBDE(QWidget * parent = 0);
    void init();
};

#endif // CONNECTTOBDE_H
