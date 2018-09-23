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
#include <sys/types.h>
#include <sys/syscall.h>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <csignal>

#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QSettings>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTimer>

#include <QSsl>
#include <QSslCertificate>

#include "source/includes/quazip/quazip.h"
#include "source/includes/quazip/quazipfile.h"

#include "source/includes/splash/mysplashscreen.h"
#include "source/includes/splash/infoscreen.h"
#include "source/includes/dbase/mainclass.h"
#include "source/includes/dbase/dbaseexception.h"

#include "source/parser/common.h"

MyMainClass * mc = nullptr;
int guiExceptionError = 0;

// sanity check ...
bool isGuiUp(void)
{
    if (QThread::currentThread() != nullptr) {
    if (QCoreApplication::instance() != nullptr) {
    if (QThread::currentThread() == QCoreApplication::instance()->thread()) {
    return true ; } } }
    return false;
}
// -------------------------------------------
// display nice exit/welcome back message ...
// -------------------------------------------
void exitFunction(void)
{
    if (isGuiUp()) {
        QMessageBox::information(nullptr,
        "Information",
        "Thanks for using !!!\n"
        "Please thinking over a Donation.");
        return;
    }

    std::cout << "Thanks for using !!!\n"
              << "Please thinking over a Donation."
              << std::endl;
    return;
}

// -------------------------------------------------
// try, to handle all signals that can occur in the
// underlaying OS like Linux ...
// -------------------------------------------------
void signalHandler(int signum)
{
    std::cout << "e Interrupt signal ("
              << signum << ") received."
              << std::endl;

    if (basicThread != nullptr)
    if (basicThread->thread_id == pthread_self())
        pthread_cancel(
        basicThread->thread_id);

    switch (signum) {
    case SIGABRT:
    {
        QMessageBox::warning(nullptr,
        "Warning","Abnormal termination of the program\n"
        "such as a call to abort.");
    }
    break;
    case SIGBUS:
    {
        QMessageBox::warning(nullptr,
        "Warning","Indicates an access to an invalid address.");
    }
    break;
    case SIGPIPE:
    {
        QMessageBox::warning(nullptr,
        "Warning","Broken pipe (POSIX)\n"
        "Error condition like trying to write to a socket\n"
        "which is not connected.");
    }
    break;
    case SIGSYS:
    {
        QMessageBox::warning(nullptr,
        "Warning","Bad system call");
    }
    break;
    case SIGFPE:
    {
        QMessageBox::warning(nullptr,
        "Warning","An erroneous arithmetic operation,\n"
        "such as a divide by zero or an operation\n"
        "resulting in overflow.");
    }
    break;
    case SIGILL:
    {
        QMessageBox::warning(nullptr,
        "Warning","Detection of an illegal instruction.");
    }
    break;
    case SIGINT:
    {
        QMessageBox::warning(nullptr,
        "Warning","Receipt of an interactive attention signal.");
    }
    break;
    case SIGXCPU:
    {
        QMessageBox::warning(nullptr,
        "Warning","CPU limit exceeded");
    }
    break;
    case SIGXFSZ:
    {
        QMessageBox::warning(nullptr,
        "Warning","File size limit exceeded");
    }
    break;
    case SIGSEGV:
    {
        QMessageBox::warning(nullptr,
        "Warning","An invalid access to storage.");
    }
    break;
    case SIGTERM:
    {
        QMessageBox::warning(nullptr,
        "Warning","A termination request sent to the program.");
    }
    break;
    default:
    {
        QMessageBox::warning(nullptr,
        "Warning","undefined/unknow SIGNAL received.");
    }
    break;
    }

    if (guiExceptionError > 0)
    return;  else

    exit(signum);
}

// ----------------------------------
// main entry / start of program ...
// ----------------------------------
int main(int argc, char **argv)
{
    // ---------------------------------
    // IMPORTANT: set plugin path's ...
    // ---------------------------------
    //#if Q_OS_LINUX
    //setenv("QT_QPA_PLATFORM_PLUGIN_PATH",
    //"./plugins", 1);
    //#endif
    
    std::atexit(exitFunction);

    std::signal(SIGABRT, signalHandler); // 1
    std::signal(SIGFPE , signalHandler); // 2
    std::signal(SIGILL , signalHandler); // 3
    std::signal(SIGINT , signalHandler); // 4
    std::signal(SIGSEGV, signalHandler); // 5
    std::signal(SIGTERM, signalHandler); // 6

    QApplication app(argc,argv);
    
    // catch exception block
    try
    {
        // splash screen
        MySplashScreen * splash = new MySplashScreen;
        splash->show();
        QTimer::singleShot(5000,splash,&MySplashScreen::closeSplash);

        LizenzDialog * lic = new
        LizenzDialog(nullptr);
        lic->exec();

        if (lic->exit_code > 0) {
            delete lic;
            delete splash;
            exit(1);
        }
        else {
            delete lic;
        }

        // we don't want changes ...
        #if 0
        QCryptographicHash::Algorithm algo = QCryptographicHash::Sha256;
        QFile sumFile(argv[0]);
        if (sumFile.open(QFile::ReadOnly)) {
            QCryptographicHash hash(algo);
            if (hash.addData(&sumFile)) {
                QByteArray fa = hash.result();
                QByteArray ca = "\x0E\xE2\xEA\x10~O\xBE\xDB\xB0X\x06\x93(\x87"
                                "6t|!\x8F\x88h\xCD\x9D\xB3@\xF8\x12\x99\x11\xE3\xA0\x9E";
                if (fa == ca) {
                    qDebug() << "okkkkkk"; // dont show in debug window :(
                }
            }
        }
        sumFile.close();
        #endif

        // trial ends? ...
        QuaZip zip(":/ssl/ssl/info.zip");
        zip.open(QuaZip::mdUnzip);
        zip.setCurrentFile("api.firmen-ring.info.crt");

        QuaZipFile file(&zip);
        file.open(QIODevice::ReadOnly); QByteArray inhalt =
        file.readAll();
        file.close();

        /*
        QSslCertificate cert(inhalt);

        QDate expire(cert.expiryDate().date());
        QDate extrad(expire.addDays(14));
        if (QDate::currentDate() > extrad) {
            QMessageBox::warning(0,"Error","Trial time expired!!!");
            exit(1);
        }*/


        mc  = new MyMainClass;

        QTranslator translator, qtTranslator;

        if (!mc->settings->contains("language")) { // choose language
            QMessageBox msgBox;

            QPushButton *engButton = msgBox.addButton(QString("English"), QMessageBox::NoRole);
            QPushButton *deuButton = msgBox.addButton(QString("Deutsch"), QMessageBox::NoRole);

            msgBox.setWindowTitle(QString("Choose language"));
            msgBox.setText(QString("<p align='center'>Choose language</o>"));
            msgBox.exec();

            if (msgBox.clickedButton() == engButton) mc->settings->setValue("language",0); else
            if (msgBox.clickedButton() == deuButton) mc->settings->setValue("language",1);

            if (mc->settings->value("language", 0).toInt() == 0) {
                translator.load(":/translations/language_eng.qm");
                app.installTranslator(&translator);

                qtTranslator.load(":/translations/qt_eng.qm");
                app.installTranslator(&qtTranslator);
            }   else
            if (mc->settings->value("language", 0).toInt() == 1) {
                translator.load(":/translations/language_deu.qm");
                app.installTranslator(&translator);

                qtTranslator.load(":/translations/qt_deu.qm");
                app.installTranslator(&qtTranslator);
            }
        }
    
        QTimer::singleShot(250,mc,SLOT(on_Open()));
        delete splash;

        int res = app.exec();

        // throw compiler error?
        if (guiExceptionError)
        {   guiExceptionError = 0;

            QProcess::startDetached(
            app.arguments()[0],
            app.arguments());
        }

        return res;
    }
    catch (QString& e) {
        QMessageBox::warning(nullptr,
        "Exception throw'd",e);
    }

    return 0;
}

