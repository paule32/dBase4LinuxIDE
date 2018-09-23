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
#include <QScreen>
#include "source/includes/dbase/mainwindow.h"

void SQLgraphicsDesigner::dropEvent(QDropEvent *event)
{
    event->accept();
}

void SQLgraphicsDesigner::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

SQLgraphicsDesigner::SQLgraphicsDesigner(QWidget * parent)
    : QGraphicsView(parent)
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setObjectName("SQLDesigner");
    setAcceptDrops(true);

    int scr_width  = qApp->screens().at(0)->availableSize().width();
    int scr_heigth = qApp->screens().at(0)->availableSize().height();
    
    scene = new Scene(this);
    scene->setSceneRect(0,0, scr_width,scr_heigth);
    scene->setObjectName("SQLDesignerScene");
    
    this->setScene(scene);
    setDragMode(QGraphicsView::RubberBandDrag);

    verticalScrollBar  ()->setSliderPosition(1);
    horizontalScrollBar()->setSliderPosition(1);
}
