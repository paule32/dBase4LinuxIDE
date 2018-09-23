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
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cxxabi.h>
using namespace std;

#include "source/includes/dbase/dbasevisitor.h"
#include "source/includes/dbase/dbaseaddnumber.h"
#include "source/includes/dbase/dbasemulnumber.h"
#include "source/includes/dbase/dbaseparameter.h"
#include "source/includes/dbase/dbaseassign.h"
#include "source/includes/dbase/dbasedownvisitor.h"

#include <QDebug>

#include <QString>
#include <QFile>
#include <QStack>
#include <QByteArray>
#include <QMessageBox>
#include <QTranslator>

#include "source/includes/dbase/mainclass.h"
#include "source/includes/dbase/dbaseexception.h"

// ------------------------------------------------------
// "catch" newline feeds, and try to handle next line ...
// ------------------------------------------------------
class dBaseNewLine {public:
      dBaseNewLine() {}  };

class dBaseEndOfProgram {public:
      dBaseEndOfProgram() {}  };

class dBaseEndOfComment {public:
      dBaseEndOfComment() {}  };

enum enumMathCommand {
    ncMUL
};
enum enumClassType {
    ctAssign,
    ctAssignADD,
    ctAssignSUB,
    ctAssignDIV
};


enum enumStaticType {
    CHAR,
    SHORT,
    INT,
    LONG,
    stFLOAT,
    DOUBLE,
    ARRAY
};

const int TOKEN_IS_NUMBER     = 2;
const int TOKEN_IS_LETTER     = 3;

int line_no;
QFile * srcfile = nullptr;

QVector<dBaseComando *> cmds;

class dBaseParser {
public:
    bool check_for_token(QString name) {
        struct token_names {
            QString name;
        } tokens[] = {
            "parameter",
            0
        };
        
        for (int i = 0; i < 1; i++) {
            if (name == tokens[i].name)
            return true;
        }   return false;
    }

    virtual void start(QString fname) {
    #if 0
        FILE *input = fopen(fname.toLatin1().data(),"r");
        yyset_in(input);
        yyparse();
        fclose(input);
    #endif
        
        qDebug() << "===================";
        qDebug() << "parser start debase";
        qDebug() << "ende";
    }
};

template <class T>
class Parser {
public:
    QString getParserClassName()
    {
        int status;
        std::string tname = typeid(T).name();
        char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);
        if(status == 0) {
            tname = demangled_name;
            std::free(demangled_name);
        }   
        return QString(tname.c_str());
    }
    void start(QString name) {
        QString pc = getParserClassName();
        if (pc == "dBaseParser") {
            dBaseParser * pc = new
            dBaseParser ; pc->start(name);
        }
    }
};

void testParser(QString name) {
    Parser<dBaseParser> dbasep;
    dbasep.start(name);
}

void dBaseAssign   ::accept(class dBaseVisitor &v) { v.visit(this); }
void dBaseADDnumber::accept(class dBaseVisitor &v) { v.visit(this); }
void dBaseMULnumber::accept(class dBaseVisitor &v) { v.visit(this); }

void dBaseParameter::accept(class dBaseVisitor &v) { v.visit(this); }

void testAST()
{    
/*    
    dBaseComando * cmd1 = new dBaseAssign("varA",12)  ; cmds.append(cmd1);
    dBaseComando * cmd2 = new dBaseADDnumber(cmd1,15) ; cmds.append(cmd2);
    
    dBaseComando * cmd3 = new dBaseAssign   ("varB", 8) ; cmds.append(cmd3);
    dBaseComando * cmd4 = new dBaseMULnumber(cmd3,   4) ; cmds.append(cmd4);
*/

//    dBaseComando * cmd1 = new dBaseParameter(QString("bModal"));
//    cmds.append(cmd1);
  
    dBaseDownVisitor down;
    for (int i = 0 ; i < cmds.count(); i++) {
        cmds.at(i)->accept(down);
    }
    
    cmds.clear();
}


// --------------------------------
// reset variables for next run ...
// --------------------------------
void reset_program()
{
    line_no = 1;
}

void run_dbase_code()
{
    try
    {   //if (w == nullptr)
        ///throw new dBaseError("window object memory is null");
    
        //if (w->ui->EditorWidget == nullptr)
        //throw new dBaseError("editor object is null");
        
        QString fname = mc->win->ui->EditorWidget->documentTitle();
        if (fname.size() < 1) {
            fname = QApplication::applicationDirPath() + "/unnamed.prg";
            mc->win->ui->EditorWidget->setDocumentTitle(fname);
            mc->win->on_SaveFileAs();
            
            mc->win->ui->EditorWidget->document()->setModified(false);
            fname = mc->win->ui->EditorWidget->documentTitle();
            qDebug() << "name: " << fname;
        }
        
        if (mc->win->ui->EditorWidget->document()->isModified())
        mc->win->on_SaveFile();
        
        reset_program();
        testParser(fname);
        testAST();
        
        qDebug() << "ende: " << line_no;
    }
    catch (dBaseEndOfProgram *e) {
        Q_UNUSED(e);
        QMessageBox::information(mc->win,
        "Information",
        QString("End of Program.\nParsed lines: %1").arg(line_no));

        srcfile->close();
        return;
    }
    catch (dBaseError *e) {
        if ((srcfile != nullptr)
        &&  (srcfile->isOpen()))
        srcfile->close();
        
        QMessageBox::critical(mc->win,"Error",
        QString("%1\n%2")
        
        .arg(e->m_message)
        .arg("\nLine: %1")
        .arg(line_no));
    }
    catch (...) {
        srcfile->close();
        QMessageBox::critical(mc->win,
        "Error",
        "unknown error");
    }
}
