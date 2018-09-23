#ifndef _MAINCLASS_H_
#define _MAINCLASS_H_

#include <QObject>
#include <QtGui>
#include <QApplication>
#include <QSettings>

#include "source/includes/dbase/mainwindow.h"

extern bool parseText(std::string,int);

class MyMainClass: public QObject
{
    Q_OBJECT
public:
     MyMainClass();
    ~MyMainClass();
    
    MainWindow * win = nullptr;
    QSettings  * settings = nullptr;
    
public slots:
	void on_Exit(int ec, QProcess::ExitStatus);
	void on_Open(void);
};
extern MyMainClass *mc;

#endif
