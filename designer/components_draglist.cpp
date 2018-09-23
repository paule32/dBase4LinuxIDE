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
#include "source/includes/dbase/mainwindow.h"

components_draglist::components_draglist(QWidget *parent)
    : QListWidget(parent)
{
    setGeometry(QRect(0, 0, 262, parent->height()));
    setSortingEnabled(false);

    setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"));
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setDefaultDropAction(Qt::TargetMoveAction);
    setAlternatingRowColors(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectItems);
    setSpacing(2);
    setViewMode(QListView::ListMode);
    setModelColumn(0);
    show();

    MyListWidgetItem *li_00 = new MyListWidgetItem(this,"Standard","",1);
    MyListWidgetItem *li_01 = new MyListWidgetItem(this,"Push Button","",0);
    MyListWidgetItem *li_02 = new MyListWidgetItem(this,"Radio Button", ":/images/radiobutton-icon-12585.png",0);

    MyListWidgetItem *li_10 = new MyListWidgetItem(this,"Symbolic","",2);
    MyListWidgetItem *li_11 = new MyListWidgetItem(this,"Addition","",0);
    MyListWidgetItem *li_12 = new MyListWidgetItem(this,"Subtracton","",0);
    MyListWidgetItem *li_13 = new MyListWidgetItem(this,"Multiplication","",0);
    MyListWidgetItem *li_14 = new MyListWidgetItem(this,"Division","",0);
    MyListWidgetItem *li_15 = new MyListWidgetItem(this,"Modulo","",0);
    MyListWidgetItem *li_16 = new MyListWidgetItem(this,"Sqrt","",0);

    ItemStandardFlag = false;
}

MyListWidgetItem::MyListWidgetItem(QListWidget *p, QString name, QString icon_res, int mode)
    : QListWidgetItem(p)
{
    QFont font("Helvetia");
    font.setBold(false);
    font.setWeight(75);

    setText(name);
    setFont(font);

    if (mode > 0) {
        QBrush brush(QColor(225, 223, 173, 255));
        brush.setStyle(Qt::SolidPattern);

        font.setBold(true);

        setBackground(brush);
        setTextAlignment(Qt::AlignCenter);
        setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    }

    QIcon icon1;
    if (icon_res.size() > 0) {
        icon1.addFile(icon_res, QSize(), QIcon::Normal, QIcon::Off);
        setIcon(icon1);
    }

    p->addItem(this);
}

void components_draglist::mouseDoubleClickEvent(QMouseEvent * event)
{
    QListWidgetItem * ptr = currentItem();
    if (!ptr) return;

    try {
        if (ptr->text() == QString("Standard"))
        {
            if (ItemStandardFlag  == false) {
                item(1)->setHidden(true);
                item(2)->setHidden(true);
                ItemStandardFlag = true;
            }   else {
                item(1)->setHidden(false);
                item(2)->setHidden(false);
                ItemStandardFlag = false;
            }
        }
    }
    catch (...) {
        qDebug() << QString("Error detected: ")+
                    QString(__FILE__) +
                    QString(": ") +
                    QString(__LINE__) ;
    }
}

void components_draglist::mousePressEvent(QMouseEvent *event)
{
    QListWidgetItem *itemptr = itemAt(event->pos());
    if (!itemptr) return;

    if (itemptr->text() == QString("Standard")) {
        event->accept();
        QListWidget::mousePressEvent(event);
        return;
    }

    QListWidget::mousePressEvent(event);

    QMimeData *mimeData = new QMimeData;
    mimeData->setText("lops blops\n");

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    Qt::DropAction dropAction =
    drag->exec(
        Qt::CopyAction |
        Qt::MoveAction ,
        Qt::CopyAction);

    QObject *tar = drag->target();
    if (tar == nullptr) {
        return;
    }

    MyEditor * ptr = tar->findChild<MyEditor *>("dBaseEditor");
    if (ptr != nullptr && ptr->hasFocus())  {
        dynamic_cast<MyEditor*>(ptr)->setFocus();
        dynamic_cast<MyEditor*>(ptr)->on_cursorPositionChanged();
        dynamic_cast<MyEditor*>(ptr)->setFocus();
        return;
    }
}
