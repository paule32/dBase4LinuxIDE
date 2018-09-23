// --------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2018 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#include <QSettings>
#include <QColorDialog>
#include <QMessageBox>

#include "source/includes/asm/codeeditor.h"
#include "source/includes/dbase/selectcolorbutton.h"

SelectColorButton::SelectColorButton( QWidget* parent )
    : QPushButton(parent)
{
}

SelectColorButton::~SelectColorButton()
{
    QSettings settings("dBase4Linux","dbase");
    settings.setValue(color_object,QColor(color).name());
}

void SelectColorButton::init(CodeEditor *ed, QString ostr)
{
    QSettings settings("dBase4Linux","dbase");
        
    QColor ncolor = settings.value(ostr).value<QColor>();
    color_object  = ostr;
    setColor(ncolor);
    edit = ed;
    
    connect(this,
            &QPushButton::clicked,
            this,
            &SelectColorButton::changeColor);
}

void SelectColorButton::updateColor()
{
    setStyleSheet("background-color: " + color.name());
    QSettings settings("dBase4Linux","dbase");
    settings.setValue(color_object,QColor(color));
    
    if (color_object == "backgroundColor") {
        if (edit != nullptr)
        edit->setStyleSheet("background-color: " + color.name());
    }
    else if (color_object == "lineNumberPanelColor") {
        if (edit != nullptr)
        edit->lineNumberPanelColor = getColor();
    }
    else if (color_object == "lineNumberFontColor") {
        if (edit != nullptr)
        edit->lineNumberFontColor = getColor();
    }
    else if (color_object == "currentLineColor") {
        if (edit != nullptr)
        edit->currentLineColor = getColor();
    }
    else if (color_object == "debugLineColor") {
        if (edit != nullptr)
        edit->debugLineColor = getColor();
    }
}

void SelectColorButton::changeColor()
{
    QColor newColor = QColorDialog::getColor(color,parentWidget());
    if ( newColor != color )
    {
        setColor( newColor );
    }
}

void SelectColorButton::setColor( const QColor& color )
{
    this->color = color;
    updateColor();
}

const QColor& SelectColorButton::getColor()
{
    return color;
}
