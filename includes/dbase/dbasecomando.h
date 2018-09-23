#ifndef DBASECOMANDO_H
#define DBASECOMANDO_H

#include "dbasevisitor.h"
#include <QDebug>

static QVariant lastValue;
class dBaseComando {
public:
    dBaseComando() { qDebug() << "dBaseComando"; }
    virtual void accept(class dBaseVisitor &v) = 0;
    QVariant getLastValue() {
        return lastValue;
    }
    
    template <typename T>
    void setLastValue(T val) {
        lastValue.setValue(val);
    }
};

#endif // DBASECOMANDO_H
