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
#ifndef ASSEMBLEREDIT_H
#define ASSEMBLEREDIT_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextCharFormat>

class AssemblerEdit : public QObject
{
    Q_OBJECT
public:
    explicit AssemblerEdit(bool x86, QObject * parent = 0);
    
    virtual QString getAssemblerPath() = 0;
    virtual QString getAssemblerOptions() = 0;
    virtual QString getStartText() = 0;
    
    virtual quint64 getMainOffset(QFile & lst, QString entryLabel) = 0;
    
    struct LineNum {
        quint64 numInCode;
        quint64 numInMemory;
        
        bool operator == (const LineNum &ln) {
            return ln.numInCode == numInCode ;
        }
    };
    struct HighlightingRule {
           HighlightingRule() : isComment(false) {}
        QRegExp pattern;
        QTextCharFormat format;
        bool isComment;
    };
    
    virtual void fillHighligherRules(
            QVector<AssemblerEdit::HighlightingRule> &highlightingRules,
            QList<QTextCharFormat *> &formats,
            bool &multiLineComments,
            QRegExp &commentStartExpression,
            QRegExp &commentEndExpression) = 0;

    bool   x86  ;
    bool isx86();
};

#endif
