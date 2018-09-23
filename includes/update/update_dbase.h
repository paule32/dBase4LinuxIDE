#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include "source/includes/dbase/mainwindow.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include ".uic/ui_update_dbase.h"
#include "source/includes/update/update_thread.h"

namespace Ui {
class update_dbase;
}

class update_dbase : public QDialog
{
    Q_OBJECT
public:
    explicit update_dbase(QDialog *parent = 0);
    ~update_dbase();

public slots:
    void replyFinished(QNetworkReply * _reply);
    void onValueChanged (int);
    void onValueChanged2(int);
    void onValueChanged3(int);

private:
    Ui::update_dbase * ui;

    QNetworkAccessManager * manager;
    QNetworkReply         * reply;
    QFile                 * binfile;

    update_thread * mThread1;
    update_thread * mThread2;
    update_thread * mThread3;

    QByteArray user_check;

    int HeaderLength;
    int mode;
};

#endif // MYTCPSERVER_H
