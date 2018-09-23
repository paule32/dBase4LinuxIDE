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
#include <QMessageBox>
#include <QTextCursor>
#include <QString>

#include "source/includes/dbase/mainwindow.h"
#include "source/includes/dbase/mainclass.h"

#include "source/includes/help/helpbrowser.h"
#include "source/parser/basic/basic.h"

#include <QListWidget>
#include <QUrl>

extern bool run_dbase_code();

extern int  basicmain(MainWindow*,QString);
extern int  dbasemain(MainWindow*,QString);
extern int  lispmain (MainWindow*,QString);

MyEditor *global_textedit = nullptr;

MyEditor::MyEditor(QWidget *parent)
    : QPlainTextEdit(parent)
{
    setObjectName("dBaseEditor");
    setWordWrapMode(QTextOption::NoWrap);
    setAcceptDrops(true);

	global_textedit = this;

    gutter = new EditorGutter(this);
    lines  = 1;

    //connect(this, SIGNAL(blockCountChanged(int)  ), this, SLOT(updateGutterWidth(int)));
    connect(this, SIGNAL(cursorPositionChanged() ), this, SLOT(on_cursorPositionChanged()));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(on_linesUpdate(QRect,int)));

    highlighter = new Highlighter(this);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));

    on_gutterUpdate(0);
    on_cursorPositionChanged();
}

void MyEditor::ShowContextMenu(const QPoint& pos) // this is a slot
{
    // for most widgets
    QPoint globalPos = mapToGlobal(pos);
    QMenu myPopUp;

    myPopUp.addAction("Run ...");
    myPopUp.addSeparator();
    myPopUp.addAction("Insert template ...");
    myPopUp.addSeparator();
    myPopUp.addAction("Copy Text");
    myPopUp.addAction("Paste");
      
    QAction* selectedItem = myPopUp.exec(globalPos);
    if (selectedItem == nullptr) {
        QMessageBox::critical(this,"Memory Allocation Error",
        "could not get item");
        return;
    }
    
    qDebug() << selectedItem->text();
    
    if (selectedItem->text() == QString("Run ...")) {
        qDebug() << "runner start";
        run_dbase_code();
        qDebug() << "runner end";
        
        /*std::string(
                    w->ui->editorWidget
                   ->document()
                   ->toPlainText().toStdString()));*/
    }  else
    if (selectedItem->text() == QString("Insert template ..."))
    {
        std::string temp =
R"(** END HEADER -- Diese Zeile nicht löschen.
// Erstellt am 14.01.1997
//
parameter bModal
local f
f = new MainFormular()
if (bModal)
    f.mdi = .F.        && ensure mdi
    f.ReadModal()
else
    f.Open()
endif

CLASS MainFormular OF FORM


ENDCLASS
)";
        this->document()->clear();
        this->document()->setPlainText(QString(temp.c_str()));
    }
    else
    {
        // nothing was chosen
    }
}

void MyEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();
    gutter->setGeometry(
    QRect(cr.left(),
          cr.top (), gutterWidth(),
          cr.height()));
}

void MyEditor::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    
    switch (event->key())
    {
    case Qt::Key_Escape:
        mc->win->close();
        break;

    case Qt::Key_F1:
        on_dockHelpOpen();
        break;

    case Qt::Key_F2:
        on_parseText();
        break;
        
    case Qt::Key_Tab:
        insertPlainText("    ");
        break;

    default:
        QPlainTextEdit::keyPressEvent(event);
        break;
    }
}

void MyEditor::mousePressEvent(class QMouseEvent  *event)
{
    QPlainTextEdit::mousePressEvent(event);
    on_cursorPositionChanged();
}

void MyEditor::on_parseText()
{
    MainWindow * win = mc->win;
    win->ui->progressBar->setValue(0);
    
    // ----------
    // BASIC ...
    // ----------
    if (win->ui->delphiWidget->currentIndex() == 2) {
        QString filename =
        QFileDialog::getSaveFileName(
            this,
            tr("Save BASIC File"),
            QString(QDir::homePath() ),
            "BASIC     *.bas (*.bas);;"
            "All Files *.* (*.*)");
        if (filename.trimmed().size() < 1)
        filename = "unnamed.bas";
        win->ui->basicEditorWidget->setDocumentTitle(filename);
        
        win->on_listScreensWidgetItemDblClicked(
        win->ui->listScreenWidget->currentItem());
        
        QFile out_file(filename);
        if  (!out_file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw QString("BASIC data file could not save.");
        
        QTextStream out(&out_file);
        int spage  = 0;
        int row    = 0;
        
        row = win->ui->listScreenWidget->currentRow();
        if (win->ui->listScreenWidget->count() > 0) {
            for (spage = 0;
            spage < win->ui->listScreenWidget->count();
            spage++) {
                win->ui->listScreenWidget->setCurrentRow(spage);
                out << "rem please don't remove this line: "
                    << QString("screen: %1\n").arg(spage)
                    << forthScreenList.at(spage).saved_text
                    << "\n";

                if (spage == win->ui->listScreenWidget->count())
                break;
            }
        }
        
        win->ui->listScreenWidget->setCurrentRow(row);
        win->ui->basicEditorWidget->setPlainText(
        forthScreenList.at(row).saved_text);
        
        out_file.close();
    
        basicmain(win,filename);
        return;
    }

    // -----------
    // dBASE ...
    // -----------
    else if (win->ui->delphiWidget->currentIndex() == 0) {
        QString filename =
        QFileDialog::getSaveFileName(
            this,
            tr("Save dBase File"),
            QString(QDir::homePath() ),
            "Program   *.prg (*.prg);;"
            "Form      *.frm (*.frm);;"
            "All Files *.* (*.*)");
        if (filename.trimmed().size() < 1)
        filename = "unnamed.prg";
        win->ui->EditorWidget->setDocumentTitle(filename);
        dbasemain(win,filename);
    }

    // ------------
    // Lisp ...
    // ------------
    else if (win->ui->delphiWidget->currentIndex() == 4) {
        QString filename =
        QFileDialog::getSaveFileName(
            this,
            tr("Save Lisp File"),
            QString(QDir::homePath() ),
            "Program   *.lisp (*.lisp);;"
            "All Files *.* (*.*)");
        if (filename.trimmed().size() < 1)
        filename = "unnamed.lisp";
        win->ui->lispEditorWidget->setDocumentTitle(filename);
        lispmain(win,filename);
    }

    std::string str;
    str = document()->toPlainText().toStdString();
    //parseText(str);
}

void MyEditor::on_dockHelpOpen()
{
    bool found     = false;
    QTextCursor tc = textCursor();

    tc.select(QTextCursor::WordUnderCursor);

    QString word = tc.selectedText();
    actualTopic  = word;

    struct dbase__keywords {
        QString name;
        QString html;
    };
    QVector<dbase__keywords> dbase_keywords = {
        {"class"   , "class"    },
        {"endclass", "endclass" },
        {"form"    , "form"     },
        {"of"      , "classof"  }
    };

    // -----------
    // dBASE ...
    // -----------
    if (mc->win->ui->delphiWidget->currentIndex() == 0) {
        word = word.toLower();
        for (auto p: dbase_keywords) {
            if (p.name == word) {
                actualTopic = word;

                QString hlp = qApp->applicationDirPath();
                hlp.append(QString("/help/doc/dbase/%1.html")
                .arg(p.html));
                mc->win->addHelp(hlp);

                found = true;
                break;
            }
        }
    }

    if (!found) {
        QString hlp = qApp->applicationFilePath();
        hlp.append("/help/doc/dbase/index.html");
        mc->win->addHelp(hlp);
    }

	mc->win->ui->tabWidget->setCurrentWidget(
	mc->win->ui->HelpTab);
}

void MyEditor::on_cursorPositionChanged()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor =   textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void MyEditor::on_gutterUpdate(int) {
    setViewportMargins(gutterWidth(), 0,0,0);
}

void MyEditor::on_linesUpdate(const QRect &rect, int dy)
{
    if (dy)
    gutter->scroll(0,dy); else
    gutter->update(0,rect.y(),
    gutter->width() ,rect.height());

    if (rect.contains(viewport()->rect()))
       on_gutterUpdate(0);
}

void MyEditor::linePaintEvent(class QPaintEvent *event)
{
    QPainter painter(gutter);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = static_cast<int>(blockBoundingGeometry(block).
                    translated(contentOffset()).top());
    int bottom = top + static_cast<int>(blockBoundingRect(block).height());

    lines = 0;
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, gutter->width(),
                             fontMetrics().height(),
                             Qt::AlignRight, number);
            ++lines;
        }

        block = block.next();
        top = bottom;
        bottom = top + static_cast<int>(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

int MyEditor::gutterWidth()
{
    int digits = 2;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

Highlighter::Highlighter(MyEditor *parent)
    : QSyntaxHighlighter(parent->document())
{
    //HighlighterRule rule;

    cppCommentFormat.setForeground(Qt::red);
    cppCommentFormat.setFontWeight(QFont::Bold);
    cppCommentFormat.setFontItalic(true);

    commentStart = QRegExp("/\\*");
    commentEnd   = QRegExp("\\*/");
}

void Highlighter::highlightBlock(const QString &text)
{
    enum { NormalState = -1, InsideCStyleComment };

    int state = previousBlockState();
    int start = 0;

    for (int i = 0; i < text.length(); ++i) {
        if (state == InsideCStyleComment) {
            if (text.mid(i, 2) == "*/") {
                state = NormalState;
                setFormat(start, i - start + 2, cppCommentFormat);
            }   }   else {
            if (text.mid(i,2) == "**") {
                setFormat(i, text.length() - i, cppCommentFormat);
                break;
            }
            if (text.mid(i,2) == "&&") {
                setFormat(i, text.length() - i, cppCommentFormat);
                break;
            }
            // C++ comment
            if (text.mid(i,2) == "//") {
                setFormat(i, text.length() - i, cppCommentFormat);
                break;  }
                else if (text.mid(i, 2) == "/*") {
                start = i;
                state = InsideCStyleComment;
            }
        }
    }

    if (state == InsideCStyleComment)
    setFormat(start, text.length() - start, cppCommentFormat);

    setCurrentBlockState(state);
}
