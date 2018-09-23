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

#include <QSsl>
#include <QAbstractSocket>
#include <QSslSocket>

#include "source/includes/ssl/qsslclient.h"

QSslClient::QSslClient(QObject *parent) :
    QObject(parent)
{
    //client_socket = new QSslSocket(this);
    //client_socket.setProtocol(QSsl::SslV3);
/*
    connect(client_socket,
            &QAbstractSocket::error,
            this,
            &QSslClient::TCPError);

    connect(client_socket,
            &QAbstractSocket::readyRead,
            this,
            &QSslClient::tcpReady);*/
}

QSslClient::~QSslClient() { }

#if 0
void QSslClient::tcpReady()
{
    QByteArray array = client_socket.read( client_socket.bytesAvailable() );
    //...
}

void QSslClient::sslError(QList<QSslError> errors)
{
    Q_UNUSED(errors)
    client_socket.ignoreSslErrors();
}

void QSslClient::TCPError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error)
}


void QSslClient::connectToServer(int port)
{
    client_socket.abort();
    client_socket.connectToHostEncrypted("127.0.0.1", port);
}
#endif
