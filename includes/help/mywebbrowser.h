#ifndef MYHELPBROWSER_H
#define MYHELPBROWSER_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QPlainTextEdit>

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>

class Environment: public QObject
{
    //Q_OBJECT
    Q_PROPERTY(QScriptValue document READ document)
public:
    Environment(QObject * parent = 0, QTextEdit *win = 0);
    ~Environment();
    
    QScriptValue document() const;
    QScriptValue evaluate(const QString &code,
                          const QString &fileName = QString());
                          
    QScriptValue toWrapper(QObject *object);
    QScriptEngine *engine() const;
    
    void reset();
    
    static QTextEdit * m_window;
    static QScriptValue write(QScriptContext *ctx, QScriptEngine);
signals:
    void scriptError(const QScriptValue &error);
private:
    QScriptEngine  * m_engine;
    QScriptValue     m_document;
};

class Document: public QObject
{
    //Q_OBJECT;
public:
    Document(Environment *env, QTextEdit *win);
    ~Document();
    
public slots:
    QScriptValue getElementById(const QString &id) const;
    QScriptValue getElementByTagName(const QString &name) const;
    
    // EventTarget
    void addEventListener(const QString &type,
                          const QScriptValue &listener,
                          bool  useCapture);
                          
    QTextEdit * m_window;
};


class MyHelpBrowser : public QObject
{
    //Q_OBJECT
public:
    MyHelpBrowser(QTextEdit *parent = 0);
   ~MyHelpBrowser();
   
    void reportError(const QScriptValue &error);
    QTextEdit * m_window;
    
private:
    Environment    * m_env;
};

#endif // MYHELPBROWSER_H
