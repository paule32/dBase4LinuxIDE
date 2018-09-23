#ifndef QSSLCLIENT_H
#define QSSLCLIENT_H

#include <QObject>
#include <QList>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>

class QSslSocket;
class QSslError;

class QSslClient: public QObject
{
    Q_OBJECT
public:
    explicit QSslClient(QObject *parent = 0);
    ~QSslClient();

//    class QSslSocket client_socket;
//    void connectToServer(int port);

//private slots:
///    void tcpReady();

//    void sslError( QList<QSslError> errors );
//    void TCPError( QAbstractSocket::SocketError error );
};


#endif // QSSLCLIENT_H
