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
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include <QFileInfo>

#include "source/includes/dbase/mainclass.h"
#include "source/includes/dbase/parseprojectfile.h"

extern int promain(MainWindow *w, QString file);

parseProjectFile::parseProjectFile(MainWindow *w)
{
    win = w;
    
    QString dname = QDir::homePath();
    
    QFileDialog dlg;
    dlg.setAcceptMode(QFileDialog::AcceptSave);
    
    QString name = dlg.getOpenFileName(
        win,
        QString("Open Project File"),
        dname,
        QString("Project *.pro (*.pro);;"
        "All Files *.* (*.*)"));

    if (name.size() < 1)
    return;

    promain(win, name);
}
