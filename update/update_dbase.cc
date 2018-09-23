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
#include "source/includes/update/update_dbase.h"
#include "source/includes/update/update_thread.h"
#include <QDebug>

extern int parseRFC_dBaseUpdate(QString,int);

QString base64_encode(QString string){
    QByteArray ba;
    ba.append(string);
    return ba.toBase64();
}

QString base64_decode(QString string){
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

#ifdef updaterimpl
update_dbase::update_dbase(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::update_dbase)
#else
update_dbase::update_dbase(QDialog *parent)
#endif
#ifndef updaterimpl
{
	return;
#else

    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);

    connect( manager
           , SIGNAL(finished(QNetworkReply*)), this
           , SLOT(replyFinished(QNetworkReply*)));

    mThread1 = new update_thread(this);
    connect( mThread1
           , SIGNAL(valueChanged(int)) , this
           , SLOT(onValueChanged(int)));

    show();
    mode = 0; manager->get(QNetworkRequest(QUrl("http://updates.dbase.tools/test.txt")));
#endif
}

update_dbase::~update_dbase()
{
    delete manager;
    delete mThread1;
    delete mThread2;

    delete ui;
}

void update_dbase::replyFinished(QNetworkReply *_reply)
{
    if (_reply->error()) {
        qDebug() << "ERROR!";
        qDebug() << _reply->errorString();
    }
    else {
        HeaderLength = _reply->header(
        QNetworkRequest::ContentLengthHeader).toULongLong();
        this->reply = _reply;

        if (mode < 2) {
            binfile = new QFile(QString(qApp->applicationFilePath()) +
                          QString(".bin"));
            if (binfile->exists())
                binfile->remove();
            if (!binfile->open(QFile::Append)) {
                delete binfile;
                return;
            }
        }

        if (mode == 0) {
            mThread1->steps = 100; //HeaderLength;
            mThread1->start();
        }
        else if (mode == 1) {
            mThread2->steps = HeaderLength;
            mThread2->start();
        }
        else if (mode == 2) {
            mThread3->steps = HeaderLength;
            mThread3->start();
        }

        //reply->deleteLater();
    }
}

void update_dbase::onValueChanged(int count)
{
    binfile->write(reply->read(1));
    binfile->flush();

    ui->progressBar->setValue(count);

    if (count >= 100) {
        mThread1->Stop = true;
        binfile->close();

        if (mode == 0) {
            if (!binfile->open(QFile::ReadOnly)) {
                delete binfile;
                return;
            }

            QString checker =
            base64_encode(
            "user1621|geheim|2016-07-15|jkallup@web.de|2016-07-13");
            mode = 2 ;
            mThread3 = new update_thread(this);
            connect( mThread3
                   , SIGNAL(valueChanged (int)), this
                   , SLOT(onValueChanged3(int)));
            manager->get(
                QNetworkRequest(QUrl(
                QString("http://updates.dbase.tools/pay/users.php?checker=%1")
                .arg(checker))));
            return;

            QByteArray ba = binfile->read(100); binfile->close();
            QString    bs;
            bs.append(ba);

            if ((bs.size() > 0) && (bs.contains("Latest-Update:"))) {
                QString dat = bs.toStdString().substr(15,10).c_str();
                QDate dateA = QDate::fromString(dat,"yyyy-MM-dd");
                QDate dateB = QDate::fromString(BUILDDATE,"yyyy-MM-dd");

                QString date1 = dateA.toString();
                QString date2 = dateB.toString();

                if (date1 < date2) {
                    //QMessageBox::information(w,"info","There is an update available.");

                    ui->progressBar->setValue(0);
                    ui->progressBar->setMaximum(HeaderLength);
                    mode = 1;

                    mThread2 = new update_thread(this);
                    connect( mThread2
                           , SIGNAL(valueChanged (int)), this
                           , SLOT(onValueChanged2(int)));

                    manager->get(QNetworkRequest(QUrl("http://updates.dbase.tools/dbase.latest.run")));
                }
            }
        }
    }
}

void update_dbase::onValueChanged2(int count)
{
    binfile->write(reply->read(1024));
    binfile->flush();

    ui->progressBar->setValue(count);
    ui->clabel1->setText(QString("%1 / %2")
                         .arg(binfile->size())
                         .arg(HeaderLength));

    if (binfile->size() >= HeaderLength) {
        mThread2->Stop = true;
        binfile->close();

        binfile->setPermissions(QFileDevice::ExeUser & QFileDevice::ReadUser);
        binfile->copy(QString(qApp->applicationFilePath()));
        binfile->remove();

        ui->progressBar->setMaximum(100);
        ui->progressBar->setValue(100);
    }
}

void update_dbase::onValueChanged3(int count)
{
    user_check = reply->readAll();

    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(100);

    mThread3->Stop = true;

    QString s1 = base64_decode(user_check);
    if (!s1.contains("ok"))
    {   QMessageBox::information(0
           , "Warning"
           , "Licence-Expired !");
        exit(1);
    }

    close();
}
