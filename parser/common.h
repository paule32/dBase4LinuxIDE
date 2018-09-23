#ifndef BASIC_H
#define BASIC_H

#pragma once

#include "source/includes/dbase/mainwindow.h"

#include <QString>
#include <QVariant>
#include <QThread>

extern int     guiExceptionError;
extern int     getThreadID(void);
extern QString basic_text;

struct forthStruct {
    bool    modified = false;
    QString saved_text;
};
extern QVector<forthStruct> forthScreenList;

struct  ForthStackMachine  {
    QVariant content;
    
    // 0 = unknown
    // 1 = ident    =>  varA
    // 2 = number   =>  1234
    // 3 = string   =>  "hello"
    
    // 4 = equal    =>  ==
    // 5 = !equal   =>  !=
    // 6 = greater  =>  >
    // 7 = lower    =>  <
    // 8 = grless   =>  >=
    // 9 = lwless   =>  <=
    int      content_type = 0;
};

// ----------------------------
// for thread safe parsing ...
// ----------------------------
struct BasicThreadInfo
{
    pthread_t         thread_id    ;   // ID returned by pthread_create()
    pthread_mutex_t * thread_mutex ;   // lock thread
    int               thread_num   ;   // Application-defined thread #
    int               thread_stacks;   // thread stack size
    char *            thread_text  ;   // source code (yytext)
    QString           thread_file  ;   // parser file
    QString           thread_code  ;   // parser code
    QString           thread_header;   // parser header output
    FILE *            thread_input ;   // parser input file
    int               thread_lineno;   // parser line #
    MainWindow *      thread_window;   // window object
    QVector<ForthStackMachine> thread_forthstack;  // 1. forth stack machine
};

class dBaseThreadInfo: public QObject
{
    Q_OBJECT
public:
     dBaseThreadInfo();
    ~dBaseThreadInfo();
public:
    int               thread_num   ;   // Application-defined thread #
    int               thread_stacks;   // thread stack size
    char *            thread_text  ;   // source code (yytext)
    QString           thread_classhdr; // header files;
    QString           thread_file  ;   // parser file
    QString           thread_code  ;   // parser code
    QString           thread_header;   // parser header output
    FILE *            thread_input ;   // parser input file
    int               thread_lineno;   // parser line #
    MainWindow *      thread_window;   // window object
    QVector<ForthStackMachine> thread_forthstack;  // 1. forth stack machine
};

extern class  dBaseThreadInfo * dbaseThread;
extern struct BasicThreadInfo * basicThread;

extern int    basicmain(MainWindow*, QString);
#endif

