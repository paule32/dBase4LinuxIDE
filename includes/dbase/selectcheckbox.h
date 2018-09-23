#ifndef SELECTCHECKBOX_H
#define SELECTCHECKBOX_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QString>

#include "source/includes/dbase/selectcolorbutton.h"
#include "source/includes/asm/codeeditor.h"

class SelectCheckBox : public QCheckBox
{
public:
    explicit SelectCheckBox(QWidget *parent = 0);
    ~SelectCheckBox();
    
    void init(SelectColorButton*,CodeEditor*,QString);
    void on_stateclick();
    void on_highchange();
    
    SelectColorButton *btn;
    
    QString color_object;
    QColor  color;
    
    CodeEditor *edit;
};

#endif // SELECTCHECKBOX_H
