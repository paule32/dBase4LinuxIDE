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
#include <QGraphicsProxyWidget>

#include "source/includes/designer/scene.h"
#include "source/includes/designer/hauptdesignerwindow.h"
#include "source/includes/designer/dragdroplistwidget.h"
#include "source/includes/designer/designergraphicsview.h"

HauptDesignerWindow::HauptDesignerWindow(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
}
void HauptDesignerWindow::init()
{
    setGeometry(0,0,164,122);
    
    view->setObjectName("hauptViewer");
    view->setAcceptDrops(true);
       
    QPoint pt; pt.setX(5); pt.setY(15);
    
    QGraphicsProxyWidget * const proxy =
    view->getScene()->addWidget(this, Qt::Window);
    proxy->setPos(QPointF(pt));
}

HauptDesignerWindow::~HauptDesignerWindow()
{
}

void HauptDesignerWindow::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void HauptDesignerWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    qDebug() << "121212";
}

void HauptDesignerWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
    qDebug() << "asddasd";
}


void HauptDesignerWindow::dropEvent(QDropEvent *event)
{
    event->accept();
    qDebug() << "dfffdfdfdf";

    QObject * obj = event->source();
    DragDropListWidget * ptr = dynamic_cast<
    DragDropListWidget * >(obj);

    qDebug() << "elser";
}
