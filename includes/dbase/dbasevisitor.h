#ifndef DBASEVISITOR_H
#define DBASEVISITOR_H

#include "dbaseassign.h"
#include "dbasemulnumber.h"
#include "dbaseaddnumber.h"
#include "dbaseparameter.h"

#include <QDebug>

class dBaseVisitor {
public:
    dBaseVisitor() { qDebug() << "dBaseVisitor"; }
    
    virtual void visit(dBaseAssign *e) = 0;
    virtual void visit(dBaseMULnumber *e) = 0;
    virtual void visit(dBaseADDnumber *e) = 0;
    
    virtual void visit(dBaseParameter *e) = 0;
    virtual void visit(float *e) = 0;
};

#endif // DBASEVISITOR_H
