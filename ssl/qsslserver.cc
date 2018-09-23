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
#include "source/includes/ssl/qsslserver.h"

#include <QtNetwork>
#include <QMessageBox>
#include <QTcpServer>
#include <QByteArray>
#include <QFile>
#include <QSslKey>

#include "source/includes/quazip/quazipfile.h"

#include <QDebug>

static
QByteArray getZipContent(QString hfile)
{
    QByteArray inhalt;

    QuaZip zip(":/ssl/ssl/info.zip");
    zip.open(QuaZip::mdUnzip);
    zip.setCurrentFile(hfile);

    QuaZipFile file(&zip);
    file.open(QIODevice::ReadOnly); inhalt =
    file.readAll();
    file.close();

    return inhalt.data();
}

QSslServer::QSslServer(QObject *parent) :
    QTcpServer(parent)
{
#if 0
    server_socket.setProtocol(QSsl::SslV3);
    
    QByteArray cert;

    QByteArray key = getZipContent("server.key");
    
    QString certName =
    QDir::homePath() + ".config/dBase4Linux/server.crt";
    QFile file_cert(certName); qDebug() << "cert: " << certName;
    if(file_cert.open(QIODevice::ReadOnly)) {
        cert = file_cert.readAll();
        file_cert.close();
    }   else {
        qDebug() << file_cert.errorString();
    }

    QSslKey ssl_key(key,
        QSsl::Rsa,
        QSsl::Pem,
        QSsl::PrivateKey,"server");
    QSslCertificate ssl_cert(cert);

    server_socket.addCaCertificate(ssl_cert);
    server_socket.setLocalCertificate(ssl_cert);
    server_socket.setPrivateKey(ssl_key);

qDebug() << "dddddd";
    connect( &server_socket,
        SIGNAL(sslErrors(QList<QSslError>)), this,
        SLOT  (sslError(QList<QSslError>)));

    connect(&server_socket,
        SIGNAL(encrypted()) ,this,
        SLOT  (encrypted()));

    server_socket.setSocketOption(QAbstractSocket::KeepAliveOption, true );
#endif
}

QSslServer::~QSslServer()
{
//    server_socket.disconnectFromHost();
//    server_socket.waitForDisconnected();
}

#if 0
void QSslServer::tcpReady()
{
    QByteArray array = server_socket.read(server_socket.bytesAvailable());
    QMessageBox::information(0,"TCPREADY",array.data());
    // ...
}

void QSslServer::encrypted()
{
    connect(&server_socket ,
        SIGNAL(readyRead()), this,
        SLOT(tcpReady()));

    //emit connection_established();
}

void QSslServer::sslError(QList<QSslError> errors)
{
    QString erroStr="";
    foreach (const QSslError &e, errors)
        erroStr.append(e.errorString()).append("\n");

    QMessageBox::warning(
    (QWidget *)this->parent(),
    tr("Error"),erroStr );

    server_socket.ignoreSslErrors();
}


bool QSslServer::start_listen(int port_no)
{
    if( !this->listen(
        QHostAddress::Any, port_no )) {
        QMessageBox::warning(
        (QWidget *)this->parent(),
        tr("Error!"),
        tr("Cannot listen to port %1").arg(port_no));
        return false;
    }   return true;
}

void QSslServer::incomingConnection(int descriptor)
{
    if(server_socket.state() != QAbstractSocket::UnconnectedState)
        return;
        
    if( !server_socket.setSocketDescriptor(descriptor)) {
        QMessageBox::warning(
        (QWidget *)this->parent(),
        tr("Error!"),
        tr("Socket error!"));
        return;
    }   else  {
        server_socket.startServerEncryption();
    }
}
#endif
