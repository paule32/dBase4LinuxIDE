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
#include <QMimeData>
#include <QWindow>
#include <QDrag>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "source/includes/designer/designeritem.h"
#include "source/includes/editors/dbase/editorgutter.h"
#include "source/includes/designer/dragdroplistwidget.h"
#include "source/includes/designer/hauptdesignerwindow.h"

#include "source/includes/dbase/mainwindow.h"
#include "source/includes/dbase/mainclass.h"

static QString hotSpotMimeDataKey() { return QStringLiteral("application/x-hotspot"); }

DragDropListWidget::DragDropListWidget(QWidget * parent)
    : QTreeWidget(parent)
{
    setVerticalScrollBarPolicy  (Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setDefaultDropAction(Qt::TargetMoveAction);

    setAlternatingRowColors(true);

    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectItems);

    connect(this,&QTreeWidget::itemPressed,
            this,&DragDropListWidget::on_itemPressed);
}

void DragDropListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragDropListWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        QMessageBox::information(this,"IRFO",event->mimeData()->text());

        const QMimeData *mime = event->mimeData();

        QPoint position = event->pos();
        QPoint hotSpot;

        QByteArrayList hotSpotPos = mime->data(hotSpotMimeDataKey()).split(' ');
        if (hotSpotPos.size() == 2) {
            hotSpot.setX(hotSpotPos.first().toInt());
            hotSpot.setY(hotSpotPos.last().toInt());
        }
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    }
    else {
        event->ignore();
    }
}

void DragDropListWidget::on_itemPressed(QTreeWidgetItem *item, int col)
{
    QMimeData * mimeData = new QMimeData;
    mimeData->setText(item->text(col));

    QDrag * drag = new QDrag(this);
    Qt::DropAction dropAction = drag->exec(
    Qt::CopyAction |
    Qt::MoveAction ,
    Qt::CopyAction);
}
