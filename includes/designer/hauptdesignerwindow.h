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
#ifndef HAUPTDESIGNERWINDOW_H
#define HAUPTDESIGNERWINDOW_H

#include <QtWidgets/QGraphicsView>
#include "pch.h"
#include "scene.h"
#include "source/includes/designer/designergraphicsview.h"

class DesignerGraphicsView;
class HauptDesignerWindow : public QDialog
{
public:
    explicit HauptDesignerWindow(QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~HauptDesignerWindow();
    void init();
protected:
    void dropEvent(QDropEvent *event);
    
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    
public:
    class DesignerGraphicsView *view;
    Scene* scene;
};

extern void repaintListOfWidgets();

#endif // HAUPTDESIGNERWINDOW_H
