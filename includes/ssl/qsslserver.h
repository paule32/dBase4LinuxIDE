#ifndef QSSLSERVER_H
#define QSSLSERVER_H

#undef QT_NO_SSL
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QSsl>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>
#include <QList>

class QSslServer: public QTcpServer
{
    Q_OBJECT
public:
    explicit QSslServer(QObject *parent = 0);
    ~QSslServer();

//    QSslSocket server_socket;

//public slots:
//      void tcpReady();
//      void encrypted();
//      void sslError(QList<QSslError> errors);

//      bool start_listen(int port_no);

//protected:
//    virtual void incomingConnection(int descriptor);

};

#endif // QSSLSERVER_H
