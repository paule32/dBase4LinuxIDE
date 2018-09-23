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
#include "source/includes/asm/assembleredit.h"
#include "source/includes/asm/nasm.h"
#include "source/includes/asm/highlighter.h"

#include "source/includes/dbase/mainwindow.h"
#include "source/includes/dbase/mainclass.h"

AsmHighlighter::AsmHighlighter(AssemblerEdit *assembler, QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
}

void AsmHighlighter::init(MainWindow *w)
{
    QTextCharFormat keywordFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat registerFormat;
    QTextCharFormat labelFormat;
    QTextCharFormat labelWithDotFormat;
    QTextCharFormat memoryFormat;
    QTextCharFormat systemFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat iomacrosFormat;
    
    QList<QColor> defaultColors;
    QList<QString> names;
    
    QList<QTextCharFormat *> formats;
    
    //setting up text formats
    names << "keywords" << "registers" << "numbers" << "memory" <<
             "labels" << "comments" << "system" << "iomacro" <<
             "quotation";
             
    defaultColors << QColor(Qt::blue) << QColor(153, 0, 204) << //according to colorNames
                     QColor(255, 122, 0) << QColor(0, 128, 255) <<
                     QColor(128, 0, 0) << QColor(Qt::darkGreen) <<
                     QColor(Qt::darkCyan) << QColor(Qt::blue) <<
                     QColor(128, 128, 128);
                     
    formats << &keywordFormat << &registerFormat << &numberFormat << &memoryFormat <<
               &labelFormat << &commentFormat << &systemFormat << &iomacrosFormat <<
               &quotationFormat;
               
    QSettings settings("dBase4Linux", "dbase");
    for (int i = 0; i < formats.size(); i++) {
         formats[i]->setForeground(settings.value(names[i] + "color", defaultColors[i]).value<QColor>());
         formats[i]->setBackground(settings.value(names[i] + "colorbg", QPalette().color(QPalette::Base)).value<QColor>());
         if (settings.value(names[i] + "bold", (i == 0) ? true : false).toBool())
             formats[i]->setFontWeight(QFont::Bold);
         formats[i]->setFontItalic(settings.value(names[i] + "italic", false).toBool());
    }
    labelWithDotFormat.setForeground(settings.value("fontcolor", QPalette().color(QPalette::WindowText)).value<QColor>());
    formats << &labelWithDotFormat;
    
     w->assembler  = new NASM(true);
     w->assembler->fillHighligherRules(
            highlightingRules,
            formats,
            multiLineComments,
            commentStartExpression,
            commentEndExpression);
}

void AsmHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            if (rule.isComment) {
                if (!isCommentInQuote(text, index)) {
                    setFormat(index, length, rule.format);
                    index = expression.indexIn(text, index + length);
                } else {
                    index = expression.indexIn(text, index + 1);
                }
             } else {
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
             }
         }
     }
     if (multiLineComments) {
         setCurrentBlockState(0);
         int startIndex = 0;
         if (previousBlockState() != 1) {
             startIndex = commentStartExpression.indexIn(text);
             if (startIndex != -1 && isCommentInQuote(text, startIndex)) {
                 startIndex = -1;
             }
         }
         while (startIndex >= 0) {
             int endIndex = commentEndExpression.indexIn(text, startIndex);
             int commentLength;
             if (endIndex == -1) {
                 setCurrentBlockState(1);
                 commentLength = text.length() - startIndex;
             } else {
                 commentLength = endIndex - startIndex
                                 + commentEndExpression.matchedLength();
             }
             setFormat(startIndex, commentLength, commentFormat);
             startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
         }
     }
 }

bool AsmHighlighter::isCommentInQuote(const QString &text, int index)
{
    bool inQuote = false;
    char quote = 0;
    for (int i = 0; i < index; ++i) {
        char c = text[i].toLatin1();
        switch (c) {
        case '"':
        case '\'':
        case '`':
            if (!inQuote) {
                inQuote = true;
                quote = c;
            } else if (quote == c) {
                inQuote = false;
            }
        }
    }
    return inQuote;
}

AsmHighlighter::~AsmHighlighter()
{
    highlightingRules.clear();
}
