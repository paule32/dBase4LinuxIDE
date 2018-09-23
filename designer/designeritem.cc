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
#include <QWindow>
#include <QPainter>
#include <QString>
#include <QMessageBox>

#include "source/includes/dbase/mainclass.h"

#include "source/includes/designer/designeritem.h"
#include "source/includes/designer/designergraphicsview.h"
#include "source/includes/designer/designerwindow.h"

MyDesignerItem::MyDesignerItem(QRect rect, Scene *p) :
    _outterborderColor(Qt::black),
    _outterborderPen(),
    _location(0,0),
    _dragStart(0,0),
    _gridSpace(10),
    _width (QString("%1").arg(rect.width ()).toDouble()),
    _height(QString("%1").arg(rect.height()).toDouble()),
    _cornerDragStart(0,0),
    _XcornerGrabBuffer(6),
    _YcornerGrabBuffer(6),
    _drawingWidth(  _width -   _XcornerGrabBuffer),
    _drawingHeight( _height -  _YcornerGrabBuffer),
    _drawingOrigenX( _XcornerGrabBuffer),
    _drawingOrigenY( _YcornerGrabBuffer)
{
    _outterborderPen.setWidth(2);
    _outterborderPen.setColor(_outterborderColor);

    setPos(rect.top(),rect.left());
    setAcceptHoverEvents(true);

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemContainsChildrenInShape);

    p->addItem(this);
}

void MyDesignerItem::adjustSize(int x, int y)
{
    _width += x;
    _height += y;

    _drawingWidth =  _width - _XcornerGrabBuffer;
    _drawingHeight=  _height - _YcornerGrabBuffer;
}

bool MyDesignerItem::sceneEventFilter(
        QGraphicsItem *watched,
        QEvent * event)
{
    CornerGrabber * corner = dynamic_cast<CornerGrabber*>(watched);
    if (corner == nullptr) return false;

    QGraphicsSceneMouseEvent * mevent = dynamic_cast<
    QGraphicsSceneMouseEvent *>(event);
    if (mevent == nullptr) return false;

    switch (mevent->type())
    {
        case QEvent::GraphicsSceneMousePress:
        {
            corner->setMouseState(CornerGrabber::kMouseDown);
            corner->mouseDownX = mevent->pos().x();
            corner->mouseDownY = mevent->pos().y();
        }
        break;

        case QEvent::GraphicsSceneMouseRelease:
        {
            corner->setMouseState(CornerGrabber::kMouseReleased);
        }
        break;

        case QEvent::GraphicsSceneMouseMove:
        {
            corner->setMouseState(CornerGrabber::kMouseMoving);
        }
        break;

        default:
            return false;
        break;
    }

    if (corner->getMouseState() == CornerGrabber::kMouseMoving)
    {

        qreal x = mevent->pos().x();
        qreal y = mevent->pos().y();

        int XaxisSign = 0;
        int YaxisSign = 0;
        switch( corner->getCorner() )
        {
        case 0:
            {
                XaxisSign = +1;
                YaxisSign = +1;
            }
            break;

        case 1:
            {
                XaxisSign = -1;
                YaxisSign = +1;
            }
            break;

        case 2:
            {
                XaxisSign = -1;
                YaxisSign = -1;
            }
            break;

        case 3:
            {
                XaxisSign = +1;
                YaxisSign = -1;
            }
            break;
        }

        // if the mouse is being dragged, calculate a new size and also re-position
        // the box to give the appearance of dragging the corner out/in to resize the box

        int xMoved = corner->mouseDownX - x;
        int yMoved = corner->mouseDownY - y;

        int newWidth = _width + ( XaxisSign * xMoved);
        if ( newWidth < 40 ) newWidth  = 40;

        int newHeight = _height + (YaxisSign * yMoved) ;
        if ( newHeight < 40 ) newHeight = 40;

        int deltaWidth  =   newWidth - _width ;
        int deltaHeight =   newHeight - _height ;

        adjustSize(  deltaWidth ,   deltaHeight);

        deltaWidth *= (-1);
        deltaHeight *= (-1);

        if ( corner->getCorner() == 0 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(newXpos, newYpos);
        }
        else   if ( corner->getCorner() == 1 )
        {
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(this->pos().x(), newYpos);
        }
        else   if ( corner->getCorner() == 3 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            this->setPos(newXpos,this->pos().y());
        }

        setCornerPositions();

        this->update();
    }

    return true;// true => do not send event to watched - we are finished with this event
}



// for supporting moving the box across the scene
void MyDesignerItem::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(true);
    _location.setX( ( static_cast<int>(_location.x()) / _gridSpace) * _gridSpace );
    _location.setY( ( static_cast<int>(_location.y()) / _gridSpace) * _gridSpace );
    this->setPos(_location);
}

// for supporting moving the box across the scene
void MyDesignerItem::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(true);
    _dragStart = event->pos();
}

// for supporting moving the box across the scene
void MyDesignerItem::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    QPointF newPos = event->pos() ;
    _location += (newPos - _dragStart);
    this->setPos(_location);
    
    QPoint pt = _location.toPoint();
}

// remove the corner grabbers
void MyDesignerItem::hoverLeaveEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::black;

    _corners[0]->setParentItem(NULL);
    _corners[1]->setParentItem(NULL);
    _corners[2]->setParentItem(NULL);
    _corners[3]->setParentItem(NULL);

    delete _corners[0];
    delete _corners[1];
    delete _corners[2];
    delete _corners[3];
}

// create the corner grabbers
void MyDesignerItem::hoverEnterEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::red;

    _corners[0] = new CornerGrabber(this,0);
    _corners[1] = new CornerGrabber(this,1);
    _corners[2] = new CornerGrabber(this,2);
    _corners[3] = new CornerGrabber(this,3);


    _corners[0]->installSceneEventFilter(this);
    _corners[1]->installSceneEventFilter(this);
    _corners[2]->installSceneEventFilter(this);
    _corners[3]->installSceneEventFilter(this);

    setCornerPositions();
}

void MyDesignerItem::setCornerPositions()
{
    _corners[0]->setPos(_drawingOrigenX, _drawingOrigenY);
    _corners[1]->setPos(_drawingWidth,  _drawingOrigenY);
    _corners[2]->setPos(_drawingWidth , _drawingHeight);
    _corners[3]->setPos(_drawingOrigenX, _drawingHeight);
}

QRectF MyDesignerItem::boundingRect() const
{
    return QRectF(0,0,_width,_height);
}

void MyDesignerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QBrush brush2(QColor(213,255,216,255),Qt::SolidPattern);
    painter->setBrush(brush2);
    
    QPointF topLeft2 (_drawingOrigenX, _drawingOrigenY);
    QPointF bottomRight2 ( _drawingWidth, _drawingHeight);
    QRectF  rect2(topLeft2, bottomRight2);

    _widget->setGeometry(
                _drawingOrigenX,
                _drawingOrigenY,
                _drawingWidth,
                _drawingHeight);
    _pixmap = _widget->grab();

    painter->fillRect(rect2,brush2);
    painter->drawPixmap(
                _drawingOrigenX,
                _drawingOrigenY,
                _drawingWidth,
                _drawingHeight,
                _pixmap
    );
}

void MyDesignerItem::mouseMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

void MyDesignerItem::mousePressEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

DesignerPushButtonItem::DesignerPushButtonItem(QString caption, QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QPushButton(caption);
    _widget->setGeometry(rect);
    _pixmap =  _widget->grab();
}

DesignerRadioButtonItem::DesignerRadioButtonItem(QString caption, QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QRadioButton(caption);
    _widget->setGeometry(rect);
    _pixmap =  _widget->grab();
}

DesignerLabelItem::DesignerLabelItem(QString caption, QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QLabel(caption);
    _widget->setGeometry(rect);
    _pixmap =  _widget->grab();
}

DesignerGroupBoxItem::DesignerGroupBoxItem(QString caption, QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QGroupBox(caption);
    _widget->setGeometry(rect);
    _pixmap =  _widget->grab();
}


// the designer window
DesignerWindow::DesignerWindow(QString caption, QRect rect, Scene *p)
    : MyDesignerItem(rect, p)
{
    _widget = new graphicsDesignWindow();
    _widget->setGeometry(rect);
    _widget->setWindowTitle(caption);
}

DesignerHLayout::DesignerHLayout(QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QWidget;
    _widget->move(10,10);
    _widget->resize(200,200);
}

DesignerSymbol_Addition::DesignerSymbol_Addition(QString image, QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    QPixmap pix(image);
    QLabel *lbl = new QLabel;
    lbl->setPixmap(pix);

    _widget = lbl;
    _widget->setGeometry(lbl->rect());
    _pixmap =  _widget->grab();
}

DesignerSQLwindow::DesignerSQLwindow(QRect rect, Scene *p)
    : MyDesignerItem(rect,p)
{
    _widget = new QWidget;
//    _widget->setWindowFlag(Qt::Tool, true);
    _widget->move(20,20);
    _widget->resize(100,100);
}
