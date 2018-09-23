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
#include <QTextEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>

#include "source/includes/help/mywebbrowser.h"

QTextEdit * Environment::m_window = nullptr;

Environment::Environment(QObject *parent, QTextEdit *win)
    : QObject(parent)
{
    m_engine = new QScriptEngine(this);
    m_window = win ;
    
    m_document = m_engine->newQObject(
    new Document(this,win), QScriptEngine::QtOwnership,
    QScriptEngine::ExcludeSuperClassContents);
    
    reset();
}

Environment::~Environment()
{

}

QScriptValue Environment::write(QScriptContext *ctx, QScriptEngine)
{
    QScriptValue a = ctx->argument(0);
    QString str = a.toString();
    qDebug() << str;
    m_window->append(a.toString());
    return a;
}

void Environment::reset()
{
    if (m_engine->isEvaluating())
        m_engine->abortEvaluation();
        
    QScriptValue self = m_engine->newQObject(this,
    QScriptEngine::QtOwnership,
    QScriptEngine::ExcludeSuperClassContents);
    
    self.setProperty("self"  ,self);
    self.setProperty("window",self);

    m_engine->setGlobalObject(self);

    //QScriptValue fun = m_engine->newFunction(write);
    //m_engine->globalObject().setProperty("write",fun);
}

QScriptValue Environment::evaluate(const QString &code, const QString &fileName)
{
    return m_engine->evaluate(code,fileName);
}

QScriptValue Environment::toWrapper(QObject *object)
{
    return m_engine->newQObject(object,
    QScriptEngine::QtOwnership,
    QScriptEngine::PreferExistingWrapperObject |
    QScriptEngine::ExcludeSuperClassContents)  ;
}

Document::Document(Environment *env, QTextEdit *win)
    : QObject(env)
    , m_window(win)
    {
}

Document::~Document()
{

}

QScriptValue Document::getElementById(const QString &id) const
{
    //Environment *env = dynamic_cast<Environment*>(parent());
    //return env->toWrapper();
    return QScriptValue();
}

QScriptValue Document::getElementByTagName(const QString &id) const
{
    return QScriptValue();
}

void Document::addEventListener(const QString &type, const QScriptValue &listener, bool useCapture)
{
    Q_UNUSED(useCapture);
    if (listener.isFunction()) {
        Environment * env = dynamic_cast<Environment*>(parent());
        QScriptValue self = env->toWrapper(this);
        self.setProperty("on" + type, listener);
    }
}

void MyHelpBrowser::reportError(const QScriptValue &error)
{
    QMessageBox::critical(0,
        "dBase4Linux - Script",
        QString("Line %0: %1")
        .arg(error.property("lineNumber").toInt32())
        .arg(error.toString()));
}

extern int htmlmain(QTextEdit *p, QString name);

MyHelpBrowser::MyHelpBrowser(QTextEdit *parent)
{
    //Environment::m_window = parent;
    
    QString fileName = "./source/docs/test.html";
    htmlmain(parent, fileName);
    
    
    #if 0
    m_env = new Environment(this, m_window);
    QObject::connect(m_env,
        SIGNAL(scriptError(QScriptValue)), this,
        SLOT(reportError(QScriptValue)));
    
    QString fileName = "./test.js";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);  QString contents = file.readAll();
    file.close();
    m_env->reset();
    
    QScriptValue ret = m_env->evaluate(contents, fileName);
    if (ret.isError()) {
       reportError(ret);
    }
    #endif
}

MyHelpBrowser::~MyHelpBrowser()
{}
