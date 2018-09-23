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
#ifndef EDITORGUTTER_H
#define EDITORGUTTER_H

#include <QtWidgets/QPlainTextEdit>
#include <QtGui/QSyntaxHighlighter>

class Highlighter;
class EditorGutter;

class MyEditor: public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MyEditor  (class QWidget *parent = 0);
    void linePaintEvent(class QPaintEvent *event) ;
    int  gutterWidth();
    int  lines;
protected:
    void mousePressEvent(class QMouseEvent  *event) Q_DECL_OVERRIDE;
    void keyPressEvent  (class QKeyEvent    *event) Q_DECL_OVERRIDE;
    void resizeEvent    (class QResizeEvent *event) Q_DECL_OVERRIDE;
public slots:
    void on_cursorPositionChanged();
    void on_gutterUpdate(int);
    void on_linesUpdate(const QRect &rect, int dy);
private:
    class Highlighter  * highlighter;
    class EditorGutter * gutter;
public slots:
    void on_dockHelpOpen();
    void on_parseText();
    void ShowContextMenu(const QPoint& pos);
signals:
    void onHelpF1();
};

extern class MyEditor *global_textedit;

class EditorGutter: public QWidget
{
    Q_OBJECT
public:
    explicit EditorGutter(class MyEditor *editor) : QWidget(editor) {
        codeEditor = editor;
    }
protected:
    void paintEvent(class QPaintEvent *event) Q_DECL_OVERRIDE {
        codeEditor->linePaintEvent(event);
    }
private:
    class MyEditor *codeEditor;
};


class Highlighter: public QSyntaxHighlighter
{
    Q_OBJECT
public:
    Highlighter(MyEditor *parent = 0);
protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;
private:
    struct HighlightRule      {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightRule> HighlightRules;

    QRegExp commentStart, cppComment;
    QRegExp commentEnd;

    QTextCharFormat cppCommentFormat;
    QTextCharFormat multiLineCommentFormat;
};

extern MyEditor *global_textedit;
#endif // EDITORGUTTER_H
