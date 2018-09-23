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
#ifndef DESIGNERITEM_H
#define DESIGNERITEM_H

#include "pch.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsSceneMoveEvent>
#include <QtCore/QPointer>

#include "scene.h"
#include "source/includes/designer/designerwindow.h"

class CornerGrabber: public QGraphicsItem
{
public:
    explicit CornerGrabber(QGraphicsItem *parent = 0,  int corner=0);

    int  getCorner(); ///< allows the owner to find out which coner this is
    void setMouseState(int); ///< allows the owner to record the current mouse state
    int  getMouseState(); ///< allows the owner to get the current mouse state

    qreal mouseDownX;
    qreal mouseDownY;

    enum {kMouseReleased=0, kMouseDown, kMouseMoving}; ///< define the mouse states
private:
    QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    void hoverEnterEvent ( QGraphicsSceneHoverEvent * event ); ///< must be re-implemented to handle mouse hover enter events
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event ); ///< must be re-implemented to handle mouse hover leave events

    // once the hover event handlers are implemented in this class,
    // the mouse events must allow be implemented because of
    // some linkage issue - apparrently there is some connection
    // between the hover events and mouseMove/Press/Release
    // events which triggers a vtable issue
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    void mousePressEvent (QGraphicsSceneMouseEvent * event );
    void mousePressEvent(QGraphicsSceneDragDropEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );

    QColor _outterborderColor; ///< the hover event handlers will toggle this between red and black
    QPen _outterborderPen; ///< the pen is used to paint the red/black border

    qreal   _width;
    qreal   _height;

    int _corner;// 0,1,2,3  - starting at x=0,y=0 and moving clockwise around the box
    int _mouseButtonState;
};


class MyDesignerItem: public QGraphicsItem
{
public:
    explicit MyDesignerItem(QRect rect, Scene *p);
protected:
    void mouseMoveEvent    (QGraphicsSceneMouseEvent* event);
    void mousePressEvent   (QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent* event);
private:
    QRectF boundingRect() const;

    void mouseMoveEvent (QGraphicsSceneDragDropEvent *event);
    void mousePressEvent(QGraphicsSceneDragDropEvent *event);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w);

    void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );

    void setCornerPositions();
    void adjustSize(int x, int y);

    QPointF mLastMousePosition;

    bool mMoving;
    bool sceneEventFilter(QGraphicsItem *watched, QEvent * event);

protected:
    QColor _outterborderColor; ///< the hover event handlers will toggle this between red and black
    QPen   _outterborderPen; ///< the pen is used to paint the red/black border

    QPointF _location;
    QPointF _dragStart;
    int     _gridSpace;
    qreal   _width;
    qreal   _height;

    QPointF _cornerDragStart;

    int _XcornerGrabBuffer;
    int _YcornerGrabBuffer;

    qreal   _drawingWidth;
    qreal   _drawingHeight;
    qreal   _drawingOrigenX;
    qreal   _drawingOrigenY;

    class QWidget       * _widget;
    class QWindow       * _widget_win;
    class QPixmap         _pixmap;

    class CornerGrabber * _corners[4];
};

class DesignerPushButtonItem:  public MyDesignerItem { public: explicit
      DesignerPushButtonItem(QString caption, QRect rect, Scene *p);
      DesignerPushButtonItem(QString caption, QRect rect, QWidget *p);
};

class DesignerRadioButtonItem: public MyDesignerItem { public: explicit
      DesignerRadioButtonItem(QString caption, QRect rect, Scene *p);};

class DesignerLabelItem:       public MyDesignerItem { public: explicit
      DesignerLabelItem        (QString caption, QRect rect, Scene *p);};

class DesignerGroupBoxItem:    public MyDesignerItem { public: explicit
      DesignerGroupBoxItem     (QString caption, QRect rect, Scene *p);};

class DesignerHLayout : public MyDesignerItem{ public: explicit
      DesignerHLayout(QRect rect, Scene *p); };
class DesignerVLayout : public MyDesignerItem{ public: explicit
      DesignerVLayout(QRect rect, Scene *p); };
      
class DesignerWindow: public MyDesignerItem { public: explicit
      DesignerWindow  (QString caption, QRect rect, Scene *s); };

class DesignerSymbol_Addition: public MyDesignerItem { public: explicit
      DesignerSymbol_Addition  (QString image, QRect rect, Scene *s); };

class DesignerSQLwindow: public MyDesignerItem { public: explicit
      DesignerSQLwindow  (QRect rect, Scene *s); };

#endif // DESIGNERITEM_H
