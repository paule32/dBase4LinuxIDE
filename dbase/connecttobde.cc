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
#include <QColumnView>
#include <QStandardItem>
#include <QFont>

#include "source/includes/BDE/connecttobde.h"

ConnectToBDE::ConnectToBDE(QWidget * parent)
    : QColumnView(parent)
{
    
}

void ConnectToBDE::init()
{
    auto * tableModel = new QStandardItemModel;
    for (int groupnum = 0; groupnum < 2 ; ++groupnum)
    {
        // Create the phone groups as QStandardItems
        QStandardItem *group = new
        QStandardItem(QString("Group %1").arg(groupnum));
        
        QFont font;
        font.setFamily("Helvetica");
        font.setPointSize(12);
        font.setBold(true);
        
        group->setFont(font);
        group->sizeHint().setWidth(44);

        // Append to each group 5 person as children
        for (int personnum = 0; personnum < 5 ; ++personnum)
        {
            QStandardItem *child = new
            QStandardItem(
            QString("Person %1 (group %2)")
            .arg(personnum)
            .arg(groupnum));
            
            // the appendRow function appends the child as new row
            group->appendRow(child);
        }   group->setColumnCount(2);
        
        // append group as new row to the model.
        // model takes the ownership of the item
        tableModel->appendRow(group);
    }
    
    setModel(tableModel);
}
