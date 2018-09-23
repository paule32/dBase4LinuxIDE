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
#ifndef DESIGNERPUSHBUTTON_H
#define DESIGNERPUSHBUTTON_H

#include <QRect>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

#include "source/includes/designer/hauptdesignerwindow.h"

class MyPushButton: public QPushButton
{
    //Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0)
    : QPushButton(parent) {
        setMouseTracking(true);
    }
    ~MyPushButton() { }
    enum startPositions {
        topleft, left,
        bottomleft, bottom,
        bottomright, right,
        topright, top, move
    } startPositions;
protected:
    void paintEvent(QPaintEvent *e) {
        QPushButton::paintEvent(e);
        
        QPainter p(this);
        p.setPen(Qt::black);
        
        if (mousepress == true) {
            p.fillRect(0,0,8,8,Qt::black);
            p.fillRect(0,height()-8,8,8,Qt::black);
            p.fillRect(width()-8,height()-8,8,8,Qt::black);
            p.fillRect(width()-8,0,8,8,Qt::black);
        }
    }
    void mousePressEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            dragStartPosition = event->pos();
            dragStartGeometry = geometry();
            
            mousepress = true;
        }
    }
    void mouseReleaseEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            //mousepress = false;
            repaint();
        }
    }
    void mouseMoveEvent(QMouseEvent *event) {
        if (!(event->buttons() & Qt::LeftButton)) {
            if (event->x() <= 8 && event->y() <= 8) {
                startPos = topleft;
                setCursor(Qt::SizeFDiagCursor);
            } else if (event->x() <= 8 && event->y() >= height() - 8) {
                startPos = bottomleft;
                setCursor(Qt::SizeBDiagCursor);
            } else if (event->x() >= width() - 8 && event->y() <= 8) {
                startPos = topright;
                setCursor(Qt::SizeBDiagCursor);
            } else if (event->x() >= width() - 8 && event->y() >= height() - 8) {
                startPos = bottomright;
                setCursor(Qt::SizeFDiagCursor);
            } else if (event->x() <= 8) {
                startPos = left;
                setCursor(Qt::SizeHorCursor);
            } else if (event->x() >= width() - 8) {
                startPos = right;
                setCursor(Qt::SizeHorCursor);
            } else if (event->y() <= 8) {
                startPos = top;
                setCursor(Qt::SizeVerCursor);
            } else if (event->y() >= height() - 8) {
                startPos = bottom;
                setCursor(Qt::SizeVerCursor);
            } else {
                startPos = move;
                setCursor(Qt::SizeAllCursor);
            }
            return;
        }
        
        switch (startPos) {
        case topleft:
            setGeometry(dragStartGeometry.left() - (dragStartPosition.x() - event->x()),
                        dragStartGeometry.top() - (dragStartPosition.y() - event->y()),
                        dragStartGeometry.width() + (dragStartPosition.x() - event->x()),
                        height() + (dragStartPosition.y() - event->y()));
            dragStartGeometry = geometry();
            break;
        
        case bottomleft:
            setGeometry(dragStartGeometry.left() - (dragStartPosition.x() - event->x()),
                        dragStartGeometry.top(),
                        dragStartGeometry.width() + (dragStartPosition.x() - event->x()),
                        event->y());
            dragStartGeometry = geometry();
            break;
        
        case topright:
            setGeometry(dragStartGeometry.left(),
                        dragStartGeometry.top() - (dragStartPosition.y() - event->y()),
                        event->x(),
                        height() + (dragStartPosition.y() - event->y()));
            dragStartGeometry = geometry();
            break;
        
        case bottomright:
            setGeometry(dragStartGeometry.left(),
                        dragStartGeometry.top(),
                        event->x(),
                        event->y());
            break;
        
        case left:
            setGeometry(dragStartGeometry.left() - (dragStartPosition.x() - event->x()),
                        dragStartGeometry.top(),
                        dragStartGeometry.width() + (dragStartPosition.x() - event->x()),
                        height());
            dragStartGeometry = geometry();
            break;
        
        case right:
            setGeometry(dragStartGeometry.left(),
                        dragStartGeometry.top(),
                        event->x(),
                        height());
            break;
        
        case top:
            setGeometry(dragStartGeometry.left(),
                        dragStartGeometry.top() - (dragStartPosition.y() - event->y()),
                        dragStartGeometry.width(),
                        height() + (dragStartPosition.y() - event->y()));
            dragStartGeometry = geometry();
            break;
        
        case bottom:
            setGeometry(dragStartGeometry.left(),
                        dragStartGeometry.top(),
                        width(),
                        event->y());
            break;
        
        case move:
            setGeometry(dragStartGeometry.left() - (dragStartPosition.x() - event->x()),
                        dragStartGeometry.top() - (dragStartPosition.y() - event->y()),
                        width(),
                        height());
            dragStartGeometry = geometry();
            break;
        
        default:
            break;
        }
    }
private:
    QPoint dragStartPosition;
    QRect dragStartGeometry;
    
    enum startPositions startPos;
    bool mousepress;
};

#endif

