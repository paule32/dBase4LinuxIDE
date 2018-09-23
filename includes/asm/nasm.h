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
#ifndef NASM_H
#define NASM_H

#include <QTextStream>

#include "source/includes/asm/common.h"
#include "source/includes/asm/codeeditor.h"
#include "source/includes/asm/assembleredit.h"

class NASM : public AssemblerEdit
{
    Q_OBJECT
public:
    explicit NASM(bool x86, QObject *parent = 0);
    QString getAssemblerPath();
    QString getLinkerPath();
    quint64 getMainOffset(QFile &lst, QString entryLabel);
    void parseLstFile(QFile &lst, QVector<AssemblerEdit::LineNum> &lines, quint64 offset);
    void fillHighligherRules(QVector<AssemblerEdit::HighlightingRule> &highlightingRules,
                             QList<QTextCharFormat *> &formats,
                             bool &multiLineComments,
                             QRegExp &commentStartExpression,
                             QRegExp &commentEndExpression);
    QString getStartText();
    void putDebugString(CodeEditor *code);
    QString getAssemblerOptions();
    QString getLinkerOptions();
};

#endif // NASM_H
