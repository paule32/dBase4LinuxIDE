#ifndef NEWTABLEDEFINITIONPLACEHOLDER_H
#define NEWTABLEDEFINITIONPLACEHOLDER_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QKeyEvent>

#include "newtabledefinitionplaceholder.h"

class NewTableDefinitionPlaceHolder : public QTableWidget
{
public:
    NewTableDefinitionPlaceHolder(QWidget *parent = 0);
    void init();
    void init(int mode);

protected:
    void keyPressEvent(QKeyEvent *event);
    
private slots:
    void onComboBoxChanged(const QString &text);
};

#endif // NEWTABLEDEFINITIONPLACEHOLDER_H
