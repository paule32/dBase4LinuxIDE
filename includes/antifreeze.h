#ifndef ANTIFREEZE_H
#define ANTIFREEZE_H

#define MsgBox(t,txt)  	QMessageBox::information(0,t,txt)

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>

#include <QMessageBox>
#include <QString>
#include <QVariant>
#include <QMutex>
#include <QThread>
#include <QTimer>
#include <QStack>

#include <QDebug>

namespace antifreeze
{
	class MyTimer : public QObject
	{
		Q_OBJECT
	public:
		MyTimer();
		QTimer *timer;
	public slots:
		void MyTimerSlot();
	};

	void init();
}

#endif
