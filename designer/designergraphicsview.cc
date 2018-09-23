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
#include <QScreen>
#include "source/includes/dbase/mainwindow.h"
#include "source/includes/designer/hauptdesignerwindow.h"

#include <QMouseEvent>
#include <QPushButton>
#include <QList>

#include "source/includes/designer/designerwidgetcontainer.h"
#include "source/includes/designer/designerpushbutton.h"

#include "source/includes/designer/hauptdesignerwindow.h"

QList<QObject*> my_controls;

void
repaintListOfWidgets()
{
    for (int i = 0; i < my_controls.count(); ++i) {
//        dynamic_cast<QWidget*>(ptr->at(i))->repaint();
    }
}

float scrollThreshold = 30;
void clamp(QPointF &value)
{
    if ((value.x() > scrollThreshold) || (value.x() < 0)) value.rx() = 0;
    else value.rx() = qAbs(value.x() - scrollThreshold);
    if ((value.y() > scrollThreshold) || (value.y() < 0)) value.ry() = 0;
    else value.ry() = qAbs(value.y() - scrollThreshold);
}

void DesignerGraphicsView::keyPressEvent(QKeyEvent *event)
{
//    if (event->key() == Qt::Key_F1)
//    w->on_dockHelpOpen();
}


void DesignerGraphicsView::dropEvent(QDropEvent *event)
{
    event->accept();

    QObject * obj = event->source();
    components_draglist * ptr = dynamic_cast<
    components_draglist * >(obj);

    if (ptr != nullptr) {
        if (ptr->currentItem()->text() == "Addition") {
            DesignerSymbol_Addition *item1 = new
            DesignerSymbol_Addition(
            QString(":/images/addierer.png"),
            QRect(
                event->pos().x()- 100,
                event->pos().y(), 100, 100),
            scene);
            return;
        }
    }
}

void DesignerGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

DesignerGraphicsView::DesignerGraphicsView(QWidget * parent)
    : QGraphicsView(parent)
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setObjectName("dBaseDesigner");
    setAcceptDrops(true);

    int scr_width  = qApp->screens().at(0)->availableSize().width();
    int scr_heigth = qApp->screens().at(0)->availableSize().height();
    
    scene = new Scene(this);
    scene->setSceneRect(0,0, scr_width,scr_heigth);
    scene->setObjectName("dBaseDesignerScene");
    
    this->setScene(scene);
    setDragMode(QGraphicsView::RubberBandDrag);

    verticalScrollBar  ()->setSliderPosition(1);
    horizontalScrollBar()->setSliderPosition(1);

    design_window = new HauptDesignerWindow(this,Qt::Window) ;
    design_window->view = this;
    design_window->init();
    
    MyWidgetContainer * cnt = new
    MyWidgetContainer(design_window);
    cnt->setGeometry(10,10,264,232);
    cnt->setVisible(true);
    my_controls.append(cnt);
    
    MyPushButton *pb = new
    MyPushButton(design_window);
    pb->setGeometry(20,20,64,32);
    pb->setText("Oo");
    pb->setParent(cnt);
    pb->setVisible(true);
    my_controls.append(pb);
    
    repaintListOfWidgets(); //design_window);

//    DesignerWindow *dwin = new
//    DesignerWindow(QString("MainWindow"),QRect(0,0,300,300),scene);
    
    
    /*
    DesignerHLayout *hlay = new
    DesignerHLayout(QRect(10,10,100,100),scene);
*/    
    
/*    DesignerRadioButtonItem *radio = new
    DesignerRadioButtonItem(QString("FooBar"),QRect(30,30,150,40),scene);

    DesignerLabelItem *label = new
    DesignerLabelItem(QString("Label1"),QRect(50,100,100,35),scene);

    DesignerGroupBoxItem *group1 = new
    DesignerGroupBoxItem(QString(" Group1: "),QRect(20,150,200,125),scene);
    */
}
