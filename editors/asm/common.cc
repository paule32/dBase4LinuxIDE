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
#include "source/includes/asm/common.h"

QString Common::applicationDataPath()
{
    QString path = QCoreApplication::applicationDirPath();
    QString appDir = path.left(path.length() - 4) + QString("/share/dBase4Linux");
    if (! QFile::exists(appDir)) {
        appDir = QCoreApplication::applicationDirPath() + "/share/dBase4Linux";
    }
    if (! QFile::exists(appDir)) {
        appDir = QCoreApplication::applicationDirPath() + "/Linux/share/dBase4Linux";
    }
    if (! QFile::exists(appDir)) {
        appDir = QCoreApplication::applicationDirPath();
    }
    return appDir;
}

QString Common::pathInTemp(QString path)
{
    QString temp = QDir::tempPath();
    QChar lastSymbol = temp[temp.length() - 1];
    if (lastSymbol == QChar('/') || lastSymbol == QChar('\\')) {
        temp.chop(1);
    }
    if (! QFile::exists(temp + "/dbase")) {
        QDir().mkpath(temp + "/dbase");
    }
    QString tempPath = temp + "/dbase";
    if (!path.isEmpty()) {
        tempPath += "/" + path;
    }
    tempPath = QDir::toNativeSeparators(tempPath);
    return tempPath;
}
