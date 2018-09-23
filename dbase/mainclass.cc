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
#include <QEvent>
#include <QMouseEvent>
#include "source/includes/dbase/mainclass.h"

MyMainClass::MyMainClass()
{
    settings = new QSettings("dBase4Linux","dbase");
    win = new MainWindow;
    win->resize(1200,1000);
    win->setVisible(false);
}

MyMainClass::~MyMainClass()
{
    delete settings;
}

void MyMainClass::on_Exit(int ec, QProcess::ExitStatus)
{
	//MainProcess *process = new MainProcess;
	//process->start();
}

void MyMainClass::on_Open()
{
    mc->win->showMaximized();
    mc->win->setVisible(true);
}
