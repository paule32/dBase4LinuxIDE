#ifndef SELECTCOLORBUTTON_H
#define SELECTCOLORBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QColor>

#include "source/includes/asm/codeeditor.h"

class SelectColorButton : public QPushButton
{
public:
    explicit SelectColorButton( QWidget* parent );
    ~SelectColorButton();

    void init(CodeEditor*,QString);
    void setColor( const QColor& color );
    
    const QColor& getColor();

    void updateColor();
    void changeColor();

    CodeEditor *edit = nullptr;
private:
    QColor  color;
    QString color_object;
};

#endif // SELECTCOLORBUTTON_H
