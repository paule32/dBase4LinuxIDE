#ifndef SQLGRAPHICSDESIGNER_H
#define SQLGRAPHICSDESIGNER_H

#include <QtWidgets/QGraphicsView>
#include "pch.h"
#include "source/includes/designer/designeritem.h"

class SQLgraphicsDesigner : public QGraphicsView
{
public:
    explicit SQLgraphicsDesigner(QWidget * parent = 0);
    Scene *getScene(void) { return scene; }
protected:
    virtual void dropEvent(QDropEvent *event);
    virtual void dragMoveEvent(QDragMoveEvent *event);
private:
    Scene* scene;
};

#endif // SQLGRAPHICSDESIGNER_H
