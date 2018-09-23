#ifndef DBASEADDNUMBER_H
#define DBASEADDNUMBER_H

#include "dbasevisitor.h"
#include "dbasecomando.h"

#include <QDebug>

class dBaseADDnumber: public dBaseComando {
public:
    template <typename TA, typename T1, typename T2>
    dBaseADDnumber(TA *cmd, T1 lhs, T2 rhs) {
        qDebug() << "dBaseADDnumber: int, int";
        lhs_value.setValue(lhs);
        rhs_value.setValue(rhs);
        res = lhs + rhs;
        dBaseAssign *p = dynamic_cast<TA*>(cmd);
        if (p != nullptr) {
            res = p->getValue().toFloat();
            p->setValue (res);
            setLastValue(res);
            qDebug() << "2: " << res;
        }
        else {
            qDebug() << "mtdddd";
        }
    }
/*
 * template<typename T> struct S {
	static void print() {
		const auto  &ti = typeid(T);
		cout << ti.name() << '\n';
	}
};
int main() {
	S<int>::print();
	S<S<float>>::print();
	return 0;
}
*/    
    template <typename TA, typename T1>
    dBaseADDnumber(TA *cmd, T1 rhs) {
        qDebug() << "dBaseADDnumber: int";
        rhs_value.setValue(rhs);
        qDebug() << "rhs: " << rhs_value;
        res = rhs_value.toFloat() + getLastValue().toFloat();
        qDebug() << "res: " << res;
        dBaseAssign *p = dynamic_cast<TA*>(cmd);
        if (p != nullptr) {
            p->setValue (res);
            setLastValue(res);

            qDebug() << "res3: " << res;
        }
        else {
            qDebug() << "33131222";
        }
    }
    
    virtual void accept(class dBaseVisitor &v);
    
    QVariant getResult(void) {
        return res;
    }

private:
    QVariant lhs_value;
    QVariant rhs_value;
    float res;
};

#endif // DBASEADDNUMBER_H
