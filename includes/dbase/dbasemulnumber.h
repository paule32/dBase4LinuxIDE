#ifndef DBASEMULNUMBER_CC
#define DBASEMULNUMBER_CC

#include "dbasevisitor.h"
#include "dbasecomando.h"

#include <QDebug>

class dBaseMULnumber: public dBaseComando {
public:
    template <typename TA, typename T1, typename T2>
    dBaseMULnumber(TA *cmd, T1 lhs, T2 rhs) {
        qDebug() << "dBaseMULnumber: int, int";
        lhs_value.setValue(lhs);
        rhs_value.setValue(rhs);
        res = lhs * rhs;
        dBaseAssign *p = dynamic_cast<TA*>(cmd);
        if (p) {
            QVariant vl = p->getValue();
            res += vl.toFloat();
            p->setValue (vl);
            setLastValue(res);
        }
    }
    
    template <typename TA, typename T1>
    dBaseMULnumber(TA *cmd, T1 rhs) {
        qDebug() << "dBaseMULnumber: int";
        rhs_value.setValue(rhs);
        res = rhs;
        dBaseAssign *p = dynamic_cast<TA*>(cmd);
        if (p) {
            qDebug() << "f: " << getLastValue();
            qDebug() << "r: " << res;
            
            res = getLastValue().toFloat() * res;
            setLastValue(res);
            
            QVariant vl = res;
            p->setValue (vl);
        }
        else {
            qDebug() << "not trfa";
        }
    }
    
    virtual void accept(class dBaseVisitor &v);
    
    QVariant getResult(void) {
        return res;
    }

private:
    QVariant lhs_value;
    QVariant rhs_value;
    float    res;
};

#endif // DBASEMULNUMBER_CC
