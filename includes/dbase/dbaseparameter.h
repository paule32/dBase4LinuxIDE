#ifndef DBASEPARAMETER_H
#define DBASEPARAMETER_H

#include <QDebug>
#include "dbasecomando.h"
#include "dbasevisitor.h"

class dBaseParameter: public dBaseComando {
public:
    dBaseParameter(QString vname) {
        setName(vname);
        qDebug() << "dBaseParameter: " << vname;
    }
    
    virtual void accept(class dBaseVisitor &v);
    
    // getter
    QString  getName (void) { return obj_name ; }
        
    // setter
    void setName (QString name) { obj_name  = name; }

private:
    QString  obj_name;
};

#endif // DBASEPARAMETER_H
