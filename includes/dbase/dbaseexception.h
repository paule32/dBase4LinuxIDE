#ifndef DBASEEXCEPTION_H
#define DBASEEXCEPTION_H

#include <exception>
#include <QString>
#include <QByteArray>

// ------------------------------------------------------
// class for error's in the source.
// error's make a trap - how wonderful is "try catch" :-)
// ------------------------------------------------------
class dBaseError {
public:
    dBaseError(QString message) : m_message(message) {}
    QString m_message;
};

class dBaseException : public std::exception {
public:
    explicit dBaseException(const QString& string) {_data = string.toLatin1(); }
    const char * what()     const noexcept         { return _data.constData(); }
private:
    QByteArray _data;
};

#endif // DBASEEXCEPTION_H
