#ifndef DBASEDOWNVISITOR_H
#define DBASEDOWNVISITOR_H

#include "dbasevisitor.h"
#include "dbaseassign.h"
#include "dbaseaddnumber.h"
#include "dbasemulnumber.h"
#include "dbaseparameter.h"

#include <QDebug>

class dBaseDownVisitor: public dBaseVisitor {
public:
    dBaseDownVisitor() { qDebug() << "dBaseDownVisitor"; }
    virtual void visit(dBaseAssign *e) {
        qDebug() << "mov Down on: " << e->getName() << "=" << e->getValue();
    }
    virtual void visit(dBaseParameter *e) {
        qDebug() << "get parameter: " << e->getName();
    }
    virtual void visit(dBaseMULnumber *e) {
        qDebug() << "mul Down on: " << e->getResult() << " old: " << e->getLastValue();
    }
    virtual void visit(dBaseADDnumber *e) {
        qDebug() << "add Down on: " << e->getResult() << " old: " << e->getLastValue();
    }
    virtual void visit(float *e) {
        qDebug() << "val Down on: " << e;
    }
};

#endif // DBASEDOWNVISITOR_H
