#include "source/includes/singleapplication.h"

#include <QtNetwork/QLocalSocket>
#include <QFileInfo>
#include <QMessageBox>
 
#define TIME_OUT                (500)    // 500ms

SingleApplication::SingleApplication(int &argc, char **argv)
     : QApplication(argc, argv)
     , w(NULL)
     , _isRunning(false)
     , _localServer(NULL) {
 
     // The application name as the name of the LocalServer
     _serverName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();
 
     _initLocalConnection();
}
 
 
////////////////////////////////////////////////////////////////////////////////
// Explain: 
// Check if there is already an instance running, true - a running example, false - no running instance
////////////////////////////////////////////////////////////////////////////////
bool SingleApplication::isRunning() {
     return _isRunning;
}
 
////////////////////////////////////////////////////////////////////////////////
// Explain: 
// Single instance running program through socket communication, listening to the new connection is triggered when the function
////////////////////////////////////////////////////////////////////////////////
void SingleApplication::_newLocalConnection() {
     QLocalSocket *socket = _localServer->nextPendingConnection();
     if(socket) {
         socket->waitForReadyRead(2*TIME_OUT);
         delete socket;
 
         // Other treatments, such as: reading the boot parameters
 
         _activateWindow();
     }
}
 
////////////////////////////////////////////////////////////////////////////////
// Explain: 
// Realization of single instance running through socket communication program, 
// Initialize the local connection, if the connection is not on the server, create, or exit
////////////////////////////////////////////////////////////////////////////////
void SingleApplication::_initLocalConnection() {
     _isRunning = false;    
 
     QLocalSocket socket;
     socket.connectToServer(_serverName);
     if(socket.waitForConnected(TIME_OUT)) {
		QMessageBox::information(0,"Trail-Version", "Error: only 1 running thread allow");
         _isRunning = true;
         // Other treatments, such as: the start-up parameters are sent to the server
         return;
     }
 
     //Failed to connect to server, create a
     _newLocalServer();
}
 
////////////////////////////////////////////////////////////////////////////////
// Explain: 
// Create LocalServer
////////////////////////////////////////////////////////////////////////////////
void SingleApplication::_newLocalServer() {
     _localServer = new QLocalServer(this);
     connect(_localServer, SIGNAL(newConnection()), this, SLOT(_newLocalConnection()));
     if(!_localServer->listen(_serverName)) {
         // The monitor failure, may beWhen a program crashes, residual process service led, removal
         if(_localServer->serverError() == QAbstractSocket::AddressInUseError) {
             QLocalServer::removeServer(_serverName); // <-- A key
             _localServer->listen(_serverName); // Listen again
         }
     }
 }
 
////////////////////////////////////////////////////////////////////////////////
// Explain: 
// To activate the main window
////////////////////////////////////////////////////////////////////////////////
void SingleApplication::_activateWindow() {
     if(w) {
         w->show();
         w->raise();
         w->activateWindow(); // Activates the window
     }
 }

