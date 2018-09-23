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

#include "source/includes/asm/codeeditor.h"
#include "source/includes/dbase/selectcolorbutton.h"
#include "source/includes/dbase/selectcheckbox.h"

SelectCheckBox::SelectCheckBox(QWidget *parent)
    : QCheckBox(parent)
{
    
}

SelectCheckBox::~SelectCheckBox()
{
    QSettings settings("dBase4Linux","dbase");
    if (isChecked()) {
        settings.setValue(color_object,QColor(color)) ; 
        settings.setValue(color_object+"checked",true);
    } else {
        settings.setValue(color_object,QColor(255,255,255));
        settings.setValue(color_object+"checked",false);
    }
}

void SelectCheckBox::on_stateclick()
{
    QSettings settings("dBase4Linux","dbase");
    if (!isChecked()) {
        setChecked(false);
        settings.setValue(color_object+"checked",false);
    } else {
        setChecked(true);
        settings.setValue(color_object+"checked",true);
    }
    
    on_highchange();
}

void SelectCheckBox::init(SelectColorButton *cb, CodeEditor *ed, QString col)
{
    QSettings settings("dBase4Linux","dbase");
    color = settings.value(col,QColor(255,255,255)).value<QColor>();
    color_object = col;

    if (settings.value(color_object+"checked",false).
    value<bool>() == true)
    setChecked(true); else
    setChecked(false);
    
    connect(this,
            &QCheckBox::clicked,
            this,
            &SelectCheckBox::on_stateclick);
            
    edit = ed;
    btn  = cb;

    on_highchange();
}

void SelectCheckBox::on_highchange()
{
    QSettings settings("dBase4Linux","dbase");
    color = settings.value(color_object,QColor(255,255,255)).value<QColor>();
    if (color_object == "backgroundColor") {
        if (edit != nullptr) {
            if (isChecked()) {
                edit->setStyleSheet("background-color: " + color.name() + ";");
                btn ->setColor(color);
            } else {
                edit->setStyleSheet("background-color: rgb(255,255,255);");
                btn ->setColor(QColor(255,255,255));
            }
        }
    }
    else if (color_object == "lineNumberPanelColor") {
        if (edit != nullptr) {
            if (isChecked()) {
                edit->lineNumberPanelColor = color;
                btn ->setColor(color);
            } else {
                edit->lineNumberPanelColor = QColor(
                palette().color(QPalette::Window));
                btn ->setColor(
                palette().color(QPalette::Window));
            }
        }
    }
    else if (color_object == "lineNumberFontColor") {
        if (edit != nullptr) {
            if (isChecked()) {
                edit->lineNumberFontColor = color;
                btn ->setColor(color);
            } else {
                edit->lineNumberFontColor = QColor(
                palette().color(QPalette::Text));
                btn ->setColor(
                palette().color(QPalette::Text));
            }
        }
    }
    else if (color_object == "currentLineColor") {
        if (edit != nullptr) {
            if (isChecked()) {
                edit->currentLineColor = color;
                btn ->setColor(color);
            } else {
                edit->currentLineColor = QColor(232, 232, 255);
                btn ->setColor(QColor(232, 232, 255));
            }
        }
    }
    else if (color_object == "debugLineColor") {
        if (edit != nullptr) {
            if (isChecked()) {
                edit->debugLineColor = color;
                btn ->setColor(color);
            } else {
                edit->debugLineColor = QColor(235, 200, 40);
                btn ->setColor(QColor(235, 200, 40));
            }
        }
    }
    settings.setValue(color_object,color);
}
