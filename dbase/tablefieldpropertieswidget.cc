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
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>

#include "source/includes/sql/tablefieldpropertieswidget.h"

TableFieldPropertiesWidget::TableFieldPropertiesWidget(QWidget *parent)
    : QTableWidget(parent)
{
    
}

void TableFieldPropertiesWidget::init()
{
    init(6);
    init(7);
}

void TableFieldPropertiesWidget::init(int mode)
{
    enum Id   {
        Row = Qt::UserRole + 1,
        Col
    };
    
    int col = 1;
    int row = mode;
    
    auto *comboBox  = new QComboBox;
    auto *lineEdit  = new QLineEdit;
    auto *widthEdit = new QLineEdit;
    
    comboBox->insertItems(0, QString("No,Yes").split(","));
    comboBox->setItemData(0, row, Row);
    comboBox->setItemData(0, col, Col);

    connect(comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
    [=](const QString &text){ this->onComboBoxChanged(text); });

    setCellWidget(row, 0, comboBox);
    
    //
    lineEdit->insert("Input not valid.");
    setCellWidget(5, 0, lineEdit);
    
    //
    QValidator *valid = new QIntValidator(1,255,this);
    widthEdit->setValidator(valid);
    widthEdit->setText("20");
    setCellWidget(0, 0, widthEdit);
}

void TableFieldPropertiesWidget::onComboBoxChanged(const QString &text)
{
    enum Id   {
        Row = Qt::UserRole + 1,
        Col
    };

    QComboBox * comboBox = dynamic_cast<QComboBox *>(sender());
    if (comboBox) {
        int row = comboBox->itemData(0, Row).toInt();
        int col = comboBox->itemData(0, Col).toInt();

        item(row, col + 1)->setText(text);
    }
}
