#ifndef DBASEASSIGN_H
#define DBASEASSIGN_H

#include <QDebug>
#include "dbasecomando.h"
#include "dbasevisitor.h"

class dBaseAssign: public dBaseComando {
public:
    dBaseAssign(QString vname, QVariant value) {
        setName(vname);
        setValue(value);
        setLastValue(value);
        
        qDebug() << "dBaseAssign";
    }
    
    virtual void accept(class dBaseVisitor &v);
    
    // getter
    QString  getName (void) { return obj_name ; }
    QVariant getValue(void) { return obj_value; }
    
    // setter
    void setName (QString name) { obj_name  = name; }
    void setValue(QVariant val) { obj_value = val ; }
private:
    QString  obj_name;
    QVariant obj_value;
};

#endif // DBASEASSIGN_H
