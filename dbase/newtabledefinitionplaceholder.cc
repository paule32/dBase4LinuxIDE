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
#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QList>

#include "source/includes/dbase/mainwindow.h"
#include "source/includes/sql/newtabledefinitionplaceholder.h"

#include "source/includes/dbase/dbaseexception.h"

NewTableDefinitionPlaceHolder::NewTableDefinitionPlaceHolder(QWidget *parent)
    : QTableWidget(parent)    
{
}

void NewTableDefinitionPlaceHolder::init() {
    init(0);
}

void NewTableDefinitionPlaceHolder::init(int mode)
{
    horizontalHeaderItem(2)->setTextAlignment(Qt::AlignLeft);
    
    setColumnWidth(2,320);
    setColumnWidth(0,130);
    
    enum Id   {
        Row = Qt::UserRole + 1,
        Col
    };
    
    int col = 2;
    int row = mode;
    
    auto *comboBox = new QComboBox();
    
    comboBox->insertItems(0, QString("Autowert,Zeichen,DateTime").split(","));
    comboBox->setItemData(0, row, Row);
    comboBox->setItemData(0, col, Col);
    
    connect(comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
    [=](const QString &text){ this->onComboBoxChanged(text); });

    setCellWidget(row, 1, comboBox);
}

void NewTableDefinitionPlaceHolder::onComboBoxChanged(const QString &text)
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

void NewTableDefinitionPlaceHolder::keyPressEvent(QKeyEvent *event)
{
    QModelIndex index = currentIndex();
	int  row    = index.row();
	int  column = 0;
	
	QModelIndex newIndex = model()->index(row,column);
	
	if (event->key() == Qt::Key_Down)
	{
        index = currentIndex();
        row   = index.row();
        
        newIndex = model()->index(row,column);

        selectionModel()->select(newIndex, QItemSelectionModel::Select);
        setCurrentIndex(newIndex);
        setFocus();
        edit(newIndex);
        
        if (currentItem() == nullptr)
        return;
        
        
        QList<QTableWidgetItem *> widList;
        if (currentItem()->text().length() > 0) {
            insertRow(rowCount());
            init(row+1);
            
            for (int i = 0; i < rowCount(); ++i) {
                QTableWidgetItem * widItem = item(i,0);
                widList.append(widItem);
            }
            
            for (int i = 0; i < widList.count(); ++i)
            {
                QTableWidgetItem * witem = widList.at(i);
                if (witem == nullptr)
                return;
                if (witem->text().length() < 1) {
                    widList.removeAt(1);
                    removeRow(i+1);
                }
            }
        }
    }

    index = currentIndex();
    row   = index.row()+1;
    
    newIndex = model()->index(row,0);

    selectionModel()->select(newIndex, QItemSelectionModel::Select);
    setCurrentIndex(newIndex);
    setFocus();
    edit(newIndex);

    QTableWidget::keyPressEvent(event);
}
